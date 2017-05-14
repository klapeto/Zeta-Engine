/*
 * Map.cpp
 *
 *  Created on: 7 Μαρ 2014
 *      Author: klapeto
 */

/*	This file is Part of Zeta Engine
 *
 *	The MIT License
 *
 * Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <Zeta/Core/Color.hpp>
#include <Zeta/Core/ConsoleFunctions.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/MapClasses/InteractField.hpp>
#include <Zeta/Core/MapClasses/Layer.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/MapClasses/Tile.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/MapClasses/ReferenceRequest.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/View.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/MapClasses/StaticObject.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <lua.hpp>
#include <Zeta/Core/ShapeRenderer.hpp>
#include <tolua++.h>
#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <Zeta/Core/MapClasses/ExternalObjectRequest.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <iostream>

namespace Zeta {

Map::Map() :
		Resource("null Map"), camera(nullptr), width(10), height(10), tileWidth(
				64), tileHeight(64), subWidth(0), subHeight(0), subTileWidth(
				32), subTileHeight(32), tilesetLifeSpan(-2) {
	// Nullise the Map to make it valid for use, even it has no meaning to the player
	nullise();
}

Map::Map(const std::string& path) :
		Resource(path), camera(nullptr), width(10), height(10), tileWidth(64), tileHeight(
				64), subWidth(0), subHeight(0), subTileWidth(32), subTileHeight(
				32), tilesetLifeSpan(-2) {
	// Load from file
	load(path);
}

Map::~Map() {

	// Delete all layers
	clear();

}

void Map::draw(const View& camera) const {
	// Get the number of tiles we need to draw on both axis
	int numTilesWidth = std::ceil((camera.getWidth() / tileWidth) + 0.5f) + 1;
	int numTilesHeight = std::ceil((camera.getHeight() / tileHeight) + 0.5f)
			+ 1;

	// Get the camera location
	Float x = camera.getX();
	Float y = camera.getY();

	// clear the list of the Animated tiles
	tilesToBeUpdated.clear();

	// Draw all lower the layers
	for (const Layer* layer : lowerLayers) {
		layer->draw(x, y, numTilesWidth, numTilesHeight);
	}

	// draw all the visible objects
	for (auto obj : visibles) {
		obj->draw(x, y);
	}

	// draw all the upperLayers
	for (const Layer* layer : upperLayers) {
		layer->draw(x, y, numTilesWidth, numTilesHeight);
	}

	// Check if we need to draw the collision boundaries
	if (ConsoleFunctions::getInstance().isBoundsShown()) {

		// We must find the start and end sub-tile that we need to draw

		// Calculate the coordinates of the tile on the top-Left of the camera
		int startTileX = (x / subTileWidth);
		int startTileY = (y / subTileHeight);

		// Calculate the coordinates of the tile on the bottom-Right of the camera
		unsigned int endTileX = startTileX--
				+ (camera.getWidth() / subTileWidth) + 1;
		unsigned int endTileY = startTileY--
				+ (camera.getHeight() / subTileHeight) + 1;

		// Check if we have valid coordinates
		if (startTileX < 0) {
			startTileX = 0;
		}

		if (startTileY < 0) {
			startTileY = 0;
		}

		if (endTileX >= subWidth) {
			endTileX = subWidth - 1;
		}

		if (endTileY >= subHeight) {
			endTileY = subHeight - 1;
		}

		// Get a temp colour to use for drawing the Bounds
		Color c(0x000000BA);

		// get The shape renderer
		ShapeRenderer& renderer = System::getInstance().getShapeRenderer();

		// for all the sub-tiles we calculated
		for (unsigned int i = startTileY; i <= endTileY; ++i) {
			for (unsigned int j = startTileX; j <= endTileX; ++j) {
				// check if the tile there has a collision
				if (collisions(j, i)) {
					// if it has, then calculate the coordinates of the rectangle to draw
					float px = std::ceil(((j * subTileWidth) - x) + 0.5f);
					float py = std::ceil(((i * subTileHeight) - y) + 0.5f);

					// draw the Rectangle
					renderer.drawFilledRectangle(px, py, px + subTileWidth,
							py + subTileHeight, c);
				}
			}
		}

	}

}

void Map::update(Float elapsedTime) {
	// Clear all the items on the Quadtree
	quadtree.clear();

	// Clear all the Visibles list
	visibles.clear();

	// Update all the Animated Tiles
	for (auto tile : tilesToBeUpdated) {
		tile->update(elapsedTime);
	}

	// For all the items that are to be removed
	for (auto& itr : toBeDeleted) {

		// Remove it from the inView if it is there
		inView.erase(itr->getObject());

		// if we must destroy it too
		if (itr->isToBeDeleted()) {
			// destroy it
			delete itr->getObject();
		}

		// remove it from the objects list
		objects.erase(itr);
	}

	// clear the objects to be removed
	toBeDeleted.clear();

	// Reset the offsets of the camera
	camera->resetOffests();

	Player* player = &WorldManager::getInstance().getPlayer();

	// Put the player on the visibles list
	visibles.push_back(player);

	// for all objects we have
	for (auto& objPair : objects) {

		// Get the actual object
		Object *obj = objPair.getObject();

		// Check if it is in view
		if (camera->isInView(*obj)) {
			// Check if it is visible
			if (!obj->isVisible()) {

				// if it is not visible, then it means
				// that it just showed up on the camera
				// and we must show it
				obj->show();
			}

			// we must calculate the order of the object according to other objects
			auto itr = visibles.begin();
			// for all the objects
			for (; itr != visibles.end(); ++itr) {

				// check if the Y coord is below the others
				if (obj->getPosition().getY() < (*itr)->getPosition().getY()) {
					// If it is, then we must put it there
					break;
				}
			}

			// insert the object on the right position to be rendered
			visibles.insert(itr, obj);
			// insert it on the inView too
			inView.insert(obj);
		} else {

			// if it is not on the view, check if we already
			// have hide it
			if (obj->isVisible()) {

				// if it is not hidden, hide it
				obj->hide();
			}
			// remove it from the inView if it is there.
			inView.erase(obj);
		}
	}

	// All the objects on the screen should be checked for collisions
	// so we insert them on the quadtree
	for (auto obj : visibles) {
		// we should only add then if the object can collide
		if (obj->isCollideAble() || obj->isTriggeringCollisionEvents()) {
			quadtree.insert(obj);
		}
	}

	// All the objects on screen should be updated
	for (auto obj : visibles) {
		obj->update(elapsedTime);
	}
}

bool Map::isRectangleColliding(const Rectangle& rect, Object *owner,
		Rectangle::Surface surface) const {
	{

		// Get a list of objects around the rectangle
		std::vector<Object*> objs = quadtree.getObjectsAt(rect);

		// get a collided flag
		bool collided = false;

		// for all the objects around the rectangle
		for (auto obj : objs) {

			// check if it is not the same person, lol
			if (obj != owner) {
				// check if the Rectangles overlap
				if (obj->getBounding().overlapsRectangle(rect)) {
					// if they overlap, check if the other is collidable
					if (obj->isCollideAble()) {
						// if it is, then bingo!
						collided = true;
					}
					// Trigger Collision Events
					obj->onCollidedWith(owner);
					owner->onCollidedWith(obj);
				}
			}
		}

		// If we collided with something
		if (collided) {
			// return true
			return true;
		}
	}
	{

		// If we haven't collided with any other person (Lifeform)
		// We should if it collides with a sub-tile

		// get a vector of the points to check for collision
		std::vector<Vector2> points;

		// check which surface of our rectangle to check and add the appropriate points
		switch (surface) {
		case Rectangle::Surface::Top:
			points.push_back(Vector2(rect.getX(), rect.getY()));
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(), rect.getY()));
			break;
		case Rectangle::Surface::Left:
			points.push_back(Vector2(rect.getX(), rect.getY()));
			points.push_back(
					Vector2(rect.getX(), rect.getY() + rect.getHeight()));
			break;
		case Rectangle::Surface::Right:
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(), rect.getY()));
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(),
							rect.getY() + rect.getHeight()));
			break;
		case Rectangle::Surface::Bottom:
			points.push_back(
					Vector2(rect.getX(), rect.getY() + rect.getHeight()));
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(),
							rect.getY() + rect.getHeight()));
			break;
		case Rectangle::Surface::Every:
			points.push_back(Vector2(rect.getX(), rect.getY()));
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(), rect.getY()));
			points.push_back(
					Vector2(rect.getX(), rect.getY() + rect.getHeight()));
			points.push_back(
					Vector2(rect.getX() + rect.getWidth(),
							rect.getY() + rect.getHeight()));
			break;
		}

		// An another flag
		bool collided = false;

		// For all the points we have
		for (Vector2& point : points) {

			// Calculate the coordinates on the Sub-tile table
			unsigned int eX = point.getX() / subTileWidth;
			unsigned int eY = point.getY() / subTileHeight;

			// Check if the coordinates are within the bounds
			if (eX < subWidth && eY < subHeight) {
				// merge the Collision value
				collided |= collisions(eX, eY);
			}
		}
		// return the result
		return collided;
	}
}

void Map::setCordinateColliding(Float x, Float y, bool val) {
	// Calculate the coordinates on the Sub-tile table
	unsigned int eX = x / subTileWidth;
	unsigned int eY = y / subTileHeight;

	// Check if the coordinates are within the bounds
	if (eX < subWidth && eY < subHeight) {

		// set the collision value
		collisions(eX, eY) = val;
	}
}

void Map::parsePriorities(xmlpp::Node* rootNode) {

	// Find the unique Property 'Layer Priority'
	auto nodes = rootNode->find(
			"./properties/property[@name=\'Layer Priority\']");

	// If the property exist
	if (nodes.size() > 0) {

		std::list<std::string> tokens;

		// gGt the Property value
		std::string value =
				static_cast<xmlpp::Element*>(nodes[0])->get_attribute_value(
						"value");

		// Tokenize the property
		StringOperations::getTokens(value, ',', tokens);

		// found flag for a the special Name
		bool _OBJ_Found = false;

		// For all the Layers we have
		for (auto& token : tokens) {
			// If we haven't found the special _OBJ_ name
			if (!_OBJ_Found) {
				// Check if this token has that name
				if (token != "_OBJ_") {
					// If it not, then we should find the Layer
					// named like that, and put it on the lower layers
					auto itr = layers.find(token);
					// Search the Layer name
					if (itr != layers.end()) {
						// If we find it then put it on the lower layers
						// since we are before the _OBJ_ token
						lowerLayers.push_back(itr->second);
					} else {
						// If we haven't find that name on the Layer list
						// Report this error
						Logger::getInstance().write(
								"At parsing Map Property: " + value
										+ " -- Value " + token
										+ " is not a recognized Layer name! A Layer might be ignored during Rendering!",
								Logger::MessageType::Warning);
					}
				} else {
					// If we find that token, then continue with the
					// rest, but put them on the front
					_OBJ_Found = true;
					continue;
				}
			} else {

				// If we are past the _OBJ_
				// Search the layer name
				auto itr = layers.find(token);
				if (itr != layers.end()) {
					// If we find it then put it on the upper layers
					// since we are after the _OBJ_ token
					upperLayers.push_back(itr->second);
				} else {
					// If we haven't find that name on the Layer list
					// Report this error
					Logger::getInstance().write(
							"At parsing Map Property: " + value + " -- Value "
									+ token
									+ " is not a recognized Layer name! A Layer might be ignored during Rendering!",
							Logger::MessageType::Warning);
				}
			}
		}

		// If after we processed all the tokens, we haven't find
		// the _OBJ_ token, then probably someone forgot it
		if (!_OBJ_Found) {
			// Report that to let know
			Logger::getInstance().write(
					"At parsing Map Property: " + value
							+ " : The Reserved value /'_OBJ_/' was not found. All layers will be rendered below objects.",
					Logger::MessageType::Warning);
		}
	} else {
		// if the property does not exist
		// sing a waring on the log file
		Logger::getInstance().write(
				"Map: " + name
						+ " has not the Property 'Layer Priority' set!"
								"All Layers will be rendered below Objects. This might produce unwanted results. See the"
								"manual for proper map creation.",
				Logger::MessageType::Warning);

		// Put all the layers at the lower stack to ensure the objects are visible during
		// rendering
		for (auto lay : layers) {
			lowerLayers.push_back(lay.second);
		}
	}
}

void Map::loadCollisions() {

	// Calculate the Sub values
	subWidth = width << 1;
	subHeight = height << 1;

	// Clear the table
	collisions.clear();

	// resize the table to the new size
	collisions.resize(subHeight, subWidth);

	// For every layer we have
	for (auto layer : layers) {

		// for every tile the layer has:
		// i,j has the Tile coordinate on the Layer
		// a,b has the sub-tile coordinate on the collisions Table
		for (unsigned int i = 0, a = 0; i < height; ++i, a += 2) {
			for (unsigned int j = 0, b = 0; j < width; ++j, b += 2) {

				// Get the Tile at the coordinate and check if it exists there
				if (const Tile *tl = layer.second->getTileAt(j, i)) {

					// if it exists, then get its collision and
					// according to the value assign the value on			Tile
					// on the collision table						___________________
					switch (tl->getCollision()) {//					|   b,a  |  b+1,a |
					case Tile::Collision::N://						|________|________|
						collisions(b, a + 1) = true;//				|  a+1,b | b+1,a+1|
						collisions(b + 1, a + 1) = true;//			|________|________|
						break;
					case Tile::Collision::S:
						collisions(b + 1, a) = true;
						collisions(b, a) = true;
						break;
					case Tile::Collision::W:
						collisions(b + 1, a) = true;
						collisions(b + 1, a + 1) = true;
						break;
					case Tile::Collision::E:
						collisions(b, a + 1) = true;
						collisions(b, a) = true;
						break;
					case Tile::Collision::SE:
						collisions(b, a) = true;
						break;
					case Tile::Collision::SW:
						collisions(b + 1, a) = true;
						break;
					case Tile::Collision::NW:
						collisions(b + 1, a + 1) = true;
						break;
					case Tile::Collision::NE:
						collisions(b, a + 1) = true;
						break;
					case Tile::Collision::Full:
						collisions(b, a) = true;
						collisions(b, a + 1) = true;
						collisions(b + 1, a) = true;
						collisions(b + 1, a + 1) = true;
						break;
					case Tile::Collision::NxE:
						collisions(b, a) = true;
						collisions(b + 1, a) = true;
						collisions(b + 1, a + 1) = true;
						break;
					case Tile::Collision::NxW:
						collisions(b, a) = true;
						collisions(b + 1, a) = true;
						collisions(b, a + 1) = true;
						break;
					case Tile::Collision::SxE:
						collisions(b + 1, a) = true;
						collisions(b, a + 1) = true;
						collisions(b + 1, a + 1) = true;
						break;
					case Tile::Collision::SxW:
						collisions(b, a) = true;
						collisions(b, a + 1) = true;
						collisions(b + 1, a + 1) = true;
						break;
					default:
						break;
					}
				}
			}
		}

	}
}

void Map::addObject(Object* obj, bool toBeDeleted) {
	// If it does exist
	if (obj != nullptr) {

		// add the Object
		objects.push_back(ObjectPair(obj, toBeDeleted));
	}
}

Object* Map::getObjectAtPosition(Float x, Float y, Object* ignoreThis) {

	// Get a list of objects around the coords
	std::vector<Object*> objs = quadtree.getObjectsAt(x, y);

	// for all those objects
	for (auto obj : objs) {

		// check if we should ignore it
		if (obj == ignoreThis) {
			// continue with the next
			continue;
		}

		// check if the target area of the object overlaps the point
		if (obj->getTargetArea().overlapsPoint(x, y)) {

			// if it overlaps, the check if it is visible
			if (obj->isVisible()) {
				// if it is then return this object
				return obj;
			} else {

				// if it is not, then return null
				return nullptr;
			}
		}
	}
	return nullptr;
}

void Map::removeObject(Object *obj) {
	// search the object on the inserted ones
	auto itr = insertedObjects.find(obj);
	if (itr != insertedObjects.end()) {
		// if we find it there, then put on the execution list
		toBeDeleted.push_back(itr->second);
	}
}

void Map::insertObject(Object* obj, bool toBeDeleted) {
	// check if it is valid
	if (obj != nullptr) {
		// if it is, then insert it at end, and store its iterator
		// to remove it in the future
		insertedObjects[obj] = objects.insert(objects.end(),
				ObjectPair(obj, toBeDeleted));
	}
}

void Map::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Map");
}

void Map::load(const std::string& path) {

	// Clear the map
	clear();

	// set the name from the file path
	name = path;

	// set the camera
	camera = &WorldManager::getInstance().getView();

	// insert the player on the inView
	inView.insert(&WorldManager::getInstance().getPlayer());

	// Get a DOM Parser
	xmlpp::DomParser parser;

	try {
		File fp(path);
		// Parse the file
		parser.parse_memory_raw((unsigned char*) fp.getData(), fp.getSize());

		// Validate with the Schema from the XmlFileContainer
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::Map).validate(
				parser.get_document());

	} catch (Exception& ex) {
		throw ex;
	} catch (const std::exception &ex) {
		// If file is corrupt or invalid, let the RESCON know
		throw Exception(path, ex.what());
	}

	// If execution gets here, then the File is OK for iteration
	xmlpp::Element *root = parser.get_document()->get_root_node();

	// Get the map dimensions
	width = strTo10(root->get_attribute_value("width").c_str());
	height = strTo10(root->get_attribute_value("height").c_str());

	// Get the primary tile dimensions
	tileWidth = strTo10(root->get_attribute_value("tilewidth").c_str());
	tileHeight = strTo10(root->get_attribute_value("tileheight").c_str());
	subTileWidth = tileWidth >> 1;
	subTileHeight = tileHeight >> 1;

	// Set the Quad Tree bounds
	quadtree.setBounds(0, 0, width * tileWidth, height * tileHeight);

	// The names say it all
	getProperties(root);

	getTilesets(root);

	getLayers(root);

	parsePriorities(root);

	getInteractFields(root);

	getStaticObjects(root);

	getNpcsAndEnemies(root);

	loadCollisions();
}

void Map::nullise() {
	// Clear the map
	clear();
	// Reset the values
	width = 10;
	height = 10;
	lowerLayers.push_back(&NullReference<Layer>::getNull());
	quadtree.setBounds(0, 0, width * tileWidth, height * tileHeight);
	subWidth = width << 1;
	subHeight = height << 1;
	collisions.clear();
	collisions.resize(subHeight, subWidth);
}

void Map::clear() {

	// Delete all layers
	for (auto layer : layers) {
		delete layer.second;
	}

	// clear the layer table
	layers.clear();

	// for all our objects
	for (auto& obj : objects) {
		// check if we should destroy it
		if (obj.isToBeDeleted()) {
			// if we should, do it
			delete obj.getObject();
		}
	}

	// clear all the rest tables
	objects.clear();
	upperLayers.clear();
	lowerLayers.clear();
	visibles.clear();
	inView.clear();
	insertedObjects.clear();
	toBeDeleted.clear();
	quadtree.clear();
	tilesets.clear();
	tilesToBeUpdated.clear();
}

const Tile& Map::getTileByGID(unsigned int gid) const {

	// for all the tilesets
	for (auto itr = tilesets.rbegin(); itr != tilesets.rend(); ++itr) {
		// check if the GID is within the tilesets GID
		if ((*itr).getFirstGid() <= gid) {
			// if it is, then return the tile there
			return itr->getTileset()->getTile(gid - itr->getFirstGid());
		}
	}
	// if it does not exist anywhere, return nonsense
	return NullReference<Tile>::getNull();
}

std::vector<Object*> Map::getAllObjectsAtPosition(Float x, Float y,
		Object* ignoreThis) {

	// get the objects around the point
	std::vector<Object*> objs = quadtree.getObjectsAt(x, y);

	// get a vector to store the objects to return
	std::vector<Object*> retObjs;

	// for all the objects around
	for (auto obj : objs) {

		// check if we should ignore it
		if (obj == ignoreThis) {
			// if we should, then continue with the next
			continue;
		}

		// check if the object collides the point
		if (obj->getTargetArea().overlapsPoint(x, y)) {
			// if it does, then check if it is visible
			if (obj->isVisible()) {
				// if it is then put it on the return list
				retObjs.push_back(obj);
			}
		}
	}

	// return the list of the objects collided
	return retObjs;
}

void Map::addTileToUpdate(Tile* tile) const {

	// search the tile on the list we have for those
	auto itr = tilesToBeUpdated.find(tile);
	if (itr == tilesToBeUpdated.end()) {
		// if we don't find it, then add it and its relatives to the list
		const std::vector<Tile*>& rTiles = tile->getRelativeTiles();
		for (auto rTile : rTiles) {
			tilesToBeUpdated.insert(rTile);
		}
	}
}

void Map::clearCachedTilesets() {
	// Clear the tilesets and the tiles
	// to be updated, since the pointers will
	// be invalidated
	cachedTilesets.clear();
	tilesToBeUpdated.clear();
}

void Map::getTilesets(xmlpp::Node* rootNode) {
	// find all the referenced tilesets
	auto nodes = rootNode->find("./tileset");

	// for all the tilesets
	for (auto node : nodes) {
		// Cast to Element for getting access to Attributes
		xmlpp::Element *tilesetNope = static_cast<xmlpp::Element*>(node);

		// Get a temporary Map Tileset
		MapTileset tl;

		// Translate The path of the tileset
		std::string tilesetName = StringOperations::translateUnixPath(
				this->name, tilesetNope->get_attribute_value("source"));

		// Check if we already loaded this tileset before
		auto itr = cachedTilesets.find(tilesetName);

		if (itr != cachedTilesets.end()) {
			// If we loaded before, then get this reference
			tl.setTileset(&itr->second.getInstance());
			itr->second.increaseReference();
		} else {
			// If we haven't loaded then we should now
			SharedResource<Tileset> &tmpTl = cachedTilesets[tilesetName];

			// Try and load the tileset
			tmpTl.load(tilesetName);
			if (tmpTl.isValid()) {
				// Get the reference to the MapTileset
				tl.setTileset(&tmpTl.getInstance());
			} else {
				// Nullise the Tileset
				tmpTl.setInstance(NullReference<Tileset>::getNull());
			}
		}
		// Get The first GID
		tl.setFirstGid(
				strTo10(tilesetNope->get_attribute_value("firstgid").c_str()));

		// Push the Tileset with the GID
		tilesets.push_back(std::move(tl));
	}

	// We have to cycle through the cached tilesets to remove those
	// that haven't been used for 2 loads
	for (auto itr = cachedTilesets.begin(); itr != cachedTilesets.end();) {
		// Check if the tileset is valid (eg. not a NullTileset)
		if (itr->second.isValid()) {
			Logger::getInstance().write(
					"Tileset Ref Count: " + itr->second.getInstance().getName()
							+ " ->"
							+ std::to_string(itr->second.getReferenceCount()));
			// Decrease the reference count
			itr->second.decreaseReference();
			// Check if we need to remove it
			if (itr->second.getReferenceCount() < tilesetLifeSpan) {
				// Report the removal
				Logger::getInstance().write(
						"Released Tileset: "
								+ itr->second.getInstance().getName());
				// Remove and take the iterator to the next item
				itr = cachedTilesets.erase(itr);
				// avoid increasing the iterator
				continue;
			}
		}
		// Get the next item
		++itr;
	}
}

void Map::getLayers(xmlpp::Node* rootNode) {
	// Find all the Layers
	auto nodes = rootNode->find("./layer");

	// For all the Layers
	for (auto node : nodes) {
		// Cast to Element for getting access to Attributes
		xmlpp::Element *layerNode = static_cast<xmlpp::Element*>(node);

		// Create a new Layer by passing the node to the constructor
		// as well as the referenced tilesets and the *this (as the 'Father'
		// of the Layer)
		Layer *lay = new Layer(layerNode, tilesets, *this);
		layers[layerNode->get_attribute_value("name")] = lay;
	}
}

void Map::getInteractFields(xmlpp::Node* rootNode) {
	// Find the TouchFields object group
	auto nodes = rootNode->find(
			"./objectgroup/object[@type=\'InteractField\']");

	// If such object group exists
	if (nodes.size() > 0) {

		RenderingContext& renderCtx =
				System::getInstance().getRenderingContext();

		// For all objects found
		for (auto fieldNode : nodes) {
			// Cast to Element to gain access to the Attributes
			xmlpp::Element* field = static_cast<xmlpp::Element*>(fieldNode);

			// Add an invalid pointer to be filled
			InteractField* obj = nullptr;

			// Search for a property named 'data' which must have Lua Code
			auto data = field->find(
					"./properties/property[@name=\'onCollision\']");

			// If we found such property
			if (data.size() > 0) {

				// Cast to element the first property
				xmlpp::Element* property = static_cast<xmlpp::Element*>(data[0]);

				// Get a new TouchField from the record
				obj = new InteractField(
						strTo10(field->get_attribute_value("x").c_str()),
						strTo10(field->get_attribute_value("y").c_str()),
						strTo10(field->get_attribute_value("width").c_str()),
						strTo10(field->get_attribute_value("height").c_str()));

				obj->setName(field->get_attribute_value("name"));

				// Create a request to get a Reference to the code
				ReferenceRequest request(
						property->get_attribute_value("value"));

				// Add the request to be executed by the RenderingContext
				renderCtx.addOperationToQueue(request);

				// Wait the RenderingContext to complete it
				request.waitToBeCompleted();

				// Set the code to be executed when collided
				obj->setOnCollision(request.getReference());

			}

			data = field->find("./properties/property[@name=\'onClick\']");

			// If we found such property
			if (data.size() > 0) {

				// Cast to element the first property
				xmlpp::Element* property = static_cast<xmlpp::Element*>(data[0]);

				// Check if we already created the Object before
				if (obj == nullptr) {
					// Create the Interact Field
					obj =
							new InteractField(
									strTo10(
											field->get_attribute_value("x").c_str()),
									strTo10(
											field->get_attribute_value("y").c_str()),
									strTo10(
											field->get_attribute_value("width").c_str()),
									strTo10(
											field->get_attribute_value("height").c_str()));
					// Set its name
					obj->setName(field->get_attribute_value("name"));
				}

				// Create a request to get a Reference to the code
				ReferenceRequest request(
						property->get_attribute_value("value"));

				// Add the request to be executed by the RenderingContext
				renderCtx.addOperationToQueue(request);
				// Wait the RenderingContext to complete it
				request.waitToBeCompleted();

				// Set the code to be executed when clicked
				obj->setOnClick(request.getReference());

			}

			// Check if we actualy created the InteractField
			if (obj != nullptr) {
				// Search for a property named 'Collidable' to set the Collidable Flag
				data = field->find(
						"./properties/property[@name=\'Collidable\']");
				if (data.size() > 0) {
					obj->setCoolideAble(
							strtol(
									static_cast<xmlpp::Element*>(data[0])->get_attribute_value(
											"value").c_str(), nullptr, 0));
				}
				// Finaly add the object to the objects List (if it was filled)
				insertObject(obj, true);
			}
		}
	}
}

void Map::getStaticObjects(xmlpp::Node* rootNode) {
	auto nodes = rootNode->find("//object[@type=\'Static\']");

	// For all the found objects
	for (auto nd : nodes) {
		xmlpp::Element* objNode = static_cast<xmlpp::Element*>(nd);

		// Get the Tile that the object will have from the gid attribute
		const Tile& tile = getTileByGID(
				strTo10(objNode->get_attribute_value("gid").c_str()));

		// Create the Static Object
		StaticObject* obj = new StaticObject(std::ceil(
		strTo10(objNode->get_attribute_value("x").c_str()) + 0.5f), std::ceil(
		strTo10(objNode->get_attribute_value("y").c_str()) + 0.5f), tile,
				tileWidth, tileHeight);

		// Push the object on the list
		objects.push_back(ObjectPair(obj, true));
	}
}

void Map::getNpcsAndEnemies(xmlpp::Node* rootNode) {
	auto nodes = rootNode->find("//object[@type=\'Npc\']");

	// A vector to the Npc Requests
	std::vector<ExternalObjectRequest::ObjectSource> npcs;

	RenderingContext& renderCtx = System::getInstance().getRenderingContext();

	// for all the Npc nodes
	for (auto nd : nodes) {
		xmlpp::Element* objNode = static_cast<xmlpp::Element*>(nd);

		// Search if it has a module to load
		auto module = objNode->find("./properties/property[@name=\'Module\']");

		if (module.size() > 0) {

			// If we have a module, then we should load it on the main Thread
			ExternalObjectRequest::ObjectSource objInfo;

			// Construct a Object Request
			objInfo.module =
					static_cast<xmlpp::Element*>(module[0])->get_attribute_value(
							"value");
			objInfo.spawnX = strTo10(objNode->get_attribute_value("x").c_str());
			objInfo.spawnY = strTo10(objNode->get_attribute_value("y").c_str());
			objInfo.type = ExternalObjectRequest::ObjectSource::ObjectType::Npc;

			// Push the request on the request list
			npcs.push_back(std::move(objInfo));
		}
	}

	// Search for all Enemy Nodes
	nodes = rootNode->find("//object[@type=\'Enemy\']");

	// for all the enemies
	for (auto nd : nodes) {
		xmlpp::Element* objNode = static_cast<xmlpp::Element*>(nd);

		// Search if it has a module
		auto module = objNode->find("./properties/property[@name=\'Module\']");

		if (module.size() > 0) {

			// If it has a module, construct an Object Request
			ExternalObjectRequest::ObjectSource objInfo;

			objInfo.module =
					static_cast<xmlpp::Element*>(module[0])->get_attribute_value(
							"value");
			objInfo.spawnX = strTo10(objNode->get_attribute_value("x").c_str());
			objInfo.spawnY = strTo10(objNode->get_attribute_value("y").c_str());
			objInfo.type =
					ExternalObjectRequest::ObjectSource::ObjectType::Enemy;

			// Push the request on the list
			npcs.push_back(std::move(objInfo));
		}
	}

	// Create the Request Operation
	ExternalObjectRequest request(npcs);

	// Add the Operation on the RenderingContext
	renderCtx.addOperationToQueue(request);

	// Wait for the renderingContext to complete it
	request.waitToBeCompleted();

	// Once the objects are loaded, insert them on the list
	for (auto obj : request.getObjects()) {
		insertObject(obj, true);
	}
}

void Map::getProperties(xmlpp::Node* rootNode) {
	// Get all the Map Propreties
	xmlpp::NodeSet nodes = rootNode->find("./properties/property");

	// For all the properties found
	for (auto node : nodes) {
		// Cast the Node to Element to gain access to the Attributes
		xmlpp::Element *propertyNode = static_cast<xmlpp::Element*>(node);

		// Insert the property with its name and value
		properties.setProperty(propertyNode->get_attribute_value("name"),
				propertyNode->get_attribute_value("value"));
	}
}

} /* namespace Zeta */
