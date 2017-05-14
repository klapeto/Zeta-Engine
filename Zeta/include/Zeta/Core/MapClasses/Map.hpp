/*
 * Map.hpp
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

#ifndef MAP_HPP_
#define MAP_HPP_

#include <list>
#include <string>
#include <vector>

#include <Zeta/Core/ZSmallMap.hpp>
#include <Zeta/Core/ZSmallSet.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/PropertyList.hpp>
#include <Zeta/Core/MapClasses/Tileset.hpp>
#include <Zeta/Core/UtilityClasses/Vector2D.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/MapClasses/MapTileset.hpp>
#include <Zeta/Core/MapClasses/StaticQuadtree.hpp>
#include <Zeta/Core/ResourceClasses/SharedResource.hpp>
#include <Zeta/Core/MapClasses/ObjectPair.hpp>

namespace xmlpp {
class Node;
}

namespace Zeta {

class View;
class Lifeform;
class Layer;
class Player;
class Quadtree;
class Object;
class Tile;


/**
 * Class for handling a Map
 * Maps contain The map data, and handle the Objects inserted to them
 */
class Map: public Resource, public Updateable, public LuaPushable {
public:

	/**
	 * Gets the Height of the map in tiles
	 * @return The height of the map
	 */
	unsigned int getHeight() const {
		return height;
	}

	/**
	 * Gets the PropertyList of the Map
	 * @return The PropertyList
	 */
	const PropertyList& getProperties() const {
		return properties;
	}

	/**
	 * Gets the Tile Height of the map
	 */
	unsigned int getTileHeight() const {
		return tileHeight;
	}

	/**
	 * Gets the Tile Width of the map
	 */
	unsigned int getTileWidth() const {
		return tileWidth;
	}

	/**
	 * Gets the Width of the map in Tiles
	 */
	unsigned int getWidth() const {
		return width;
	}

	/**
	 * Sets the View of the Map
	 * The View is like a Camera
	 */
	void setView(View &camera) {
		this->camera = &camera;
	}

	/**
	 * Gets the Tile according to its GID on the Map
	 * The GID (Global ID) is the ID of a Tile on the Combined Tilesets
	 * that are referenced on the Map.
	 * @param gid The Global ID of the Tile to return
	 * @return The Tile, or NullTile if the GID is invalid
	 */
	const Tile& getTileByGID(unsigned int gid) const;

	/**
	 * Gets whether the provided Rectangle collides with anything on the map
	 * The Object provided will be ignored form the check. The on the surfaces
	 * provided will be tested for collisions.
	 * @param rect The Rectangle to check for collisions
	 * @param owner The Object to ignore from the checks
	 * @param surface The Rectangle::Surface to check. Default is Rectangle::Surface::Every
	 * @return true if the rectagnle collides with anything
	 */
	bool isRectangleColliding(const Rectangle& rect, Object *owner,
			Rectangle::Surface surface = Rectangle::Surface::Every) const;

	/**
	 * Sets the sub-Tile in the provided Coordinate to be collidable or not
	 * Every tile is split in 4 sub-tiles for collision mapping
	 * @param x the X coordinate of the subtile
	 * @param y the Y coordinate of the subtile
	 * @param val true if to set collidable, false to set it to non-collidable
	 */
	void setCordinateColliding(Float x, Float y, bool val);

	/**
	 * Gets the first Object to be found on the coordinate provided
	 * the Object ignoreThis will be ignored from the checks, if the parameter is set.
	 * @param x The X coordinate to check
	 * @param y The Y coordinate to check
	 * @param ignoreThis The Object to Ignore from the checks. Default is nullptr
	 * @return The Object tha was found, or nullptr if nothing was found
	 */
	Object* getObjectAtPosition(Float x, Float y, Object* ignoreThis = nullptr);

	/**
	 * Gets all the Objects to be found on the coordinate provided
	 * the Object ignoreThis will be ignored from the checks, if the parameter is set.
	 * @param x The X coordinate to check
	 * @param y The Y coordinate to check
	 * @param ignoreThis The Object to Ignore from the checks. Default is nullptr
	 * @return the std::vector of the Objects that were fount
	 */
	std::vector<Object*> getAllObjectsAtPosition(Float x, Float y,
			Object* ignoreThis = nullptr);

	/**
	 * Gets a Set of the Objects that are on the Screen
	 */
	const ZSmallSet<Object*>& getVisibleObjects() const {
		return inView;
	}

	/**
	 * Adds an Animated Tile to the list to be updated
	 * The relative Tiles will be added too.
	 * @param tile The Tile too add
	 */
	void addTileToUpdate(Tile* tile) const;

	/**
	 * Loads the Map from the filename provided
	 * @param path The path to the file to load
	 */
	void load(const std::string& path);

	/**
	 * Resets the Map
	 * It destroys all the objects, and releases all the Tileset References
	 * \note the cached Tilesets are not released
	 */
	void nullise();

	/**
	 * Releases all the cached Tilesets
	 * The cached Tilesets are tilesets that are not released
	 * every time the map is loaded, but checks if they will be used again.
	 */
	void clearCachedTilesets();

	/**
	 * Adds an Object to Map
	 * The object will not be able to explicitly remove later.
	 * If you want to do so, then \see insertObject(Object*, bool)
	 * @param obj The Object to add
	 * @param toBeDeleted If set to true, the when the map is cleared, the object will be destroyed
	 */
	void addObject(Object *obj, bool toBeDeleted);

	/**
	 * Inserts a Object to map and registers it as an Inserted Object
	 * The inserted Objects can be removed explicitly via its pointer
	 * @param obj The Object to add
	 * @param toBeDeleted If set to true, the when the map is cleared, the object will be destroyed
	 */
	void insertObject(Object *obj, bool toBeDeleted);

	/**
	 * Removes the Object from the Map
	 * \note It only has effect if the Object was inserted
	 * with the insertObject(Object*, bool) function. If the Object's
	 * flag toBeDeleted is true, then the object will be destroyed on the next
	 * Frame.
	 * @param obj The object to remove
	 */
	void removeObject(Object *obj);

	/**
	 * Gets the Tileset Life span
	 * The tileset Life Span is the number of Loads for a Tileset
	 * to be unused before the engine destroys it
	 * @return the Number of Loads before destruction
	 */
	int getTilesetLifespan() const {
		return -tilesetLifeSpan;
	}

	/**
	 * Gets the Tileset Life span
	 * The tileset Life Span is the number of Loads for a Tileset
	 * to be unused before the engine destroys it
	 * @param tilesetLifeSpan the Number of Loads before destruction
	 */
	void setTilesetLifespan(int tilesetLifeSpan) {
		this->tilesetLifeSpan = -tilesetLifeSpan;
	}

	/**
	 * Draws the Map, accordin to the View provided
	 * @param camera The View to use
	 */
	void draw(const View& camera) const;

	/**
	 * Updates the Map
	 * @param elapsedTime The time in second that passed since the last call
	 */
	void update(Float elapsedTime);

	void pushToLua(lua_State* lstate);

	/**
	 * Constructs an Empty Map
	 */
	Map();

	/**
	 * Constructs and Loads a Map
	 * @param path The file to load
	 */
	Map(const std::string& path);

	~Map();
protected:

	ZSmallMap<std::string, SharedResource<Tileset>> cachedTilesets;
	std::vector<MapTileset> tilesets;

	ZSmallMap<std::string, Layer*> layers;

	std::vector<Layer*> upperLayers;
	std::vector<Layer*> lowerLayers;

	std::list<ObjectPair> objects;
	std::list<Object*> visibles;
	ZSmallSet<Object*> inView;
	mutable ZSmallSet<Tile*> tilesToBeUpdated;
	ZSmallMap<Object*, std::list<ObjectPair>::iterator> insertedObjects;
	std::vector<std::list<ObjectPair>::iterator> toBeDeleted;

	Vector2D<int> collisions;
	PropertyList properties;
	StaticQuadtree quadtree;

	View *camera;

	unsigned int width;
	unsigned int height;

	unsigned int tileWidth;
	unsigned int tileHeight;

	unsigned int subWidth;
	unsigned int subHeight;
	unsigned int subTileWidth;
	unsigned int subTileHeight;

	int tilesetLifeSpan;

	void getProperties(xmlpp::Node* rootNode);
	void getTilesets(xmlpp::Node* rootNode);
	void getLayers(xmlpp::Node* rootNode);
	void parsePriorities(xmlpp::Node* rootNode);
	void getInteractFields(xmlpp::Node* rootNode);
	void getStaticObjects(xmlpp::Node* rootNode);
	void getNpcsAndEnemies(xmlpp::Node* rootNode);
	void loadCollisions();
	void clear();

};

} /* namespace Zeta */

#endif /* MAP_HPP_ */
