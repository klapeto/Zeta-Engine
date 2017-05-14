/*
 * Tileset.cpp
 *
 *  Created on: 6 Μαρ 2014
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

#include <Zeta/Core/MapClasses/Tileset.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/PropertyList.hpp>
#include <Zeta/Core/ResourceClasses/Bitmap.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <cstdlib>

namespace Zeta {

Tileset::Tileset() :
		Resource("null Tileset"), img(
				&System::getInstance().getResourcesManager().getNullBitmap()), tileWidth(
				64), tileHeight(64), numTiles(0) {

}

Tileset::Tileset(const std::string& path) :
		Resource(path) {
	load(path);
}

const Tile& Tileset::getTile(unsigned int id) const {
	// Check if the id is valid
	if (id < numTiles) {
		// If it is valid, return the tile
		return tiles[id];
	} else {
		// If it is not, then return the NullTile
		return NullReference<Tile>::getNull();
	}
}

const Tile* Tileset::getMapTile(unsigned int id) const {
	// Check if the id is valid
	if (id < numTiles) {
		// If it is valid, return the tile
		return &tiles[id];
	} else {
		// if it is not valid return NULL
		return nullptr;
	}
}

void Tileset::load(const std::string& path) {
	name = path;
	xmlpp::DomParser parser;

	// Parse and validate the file
	try {
		File fp(path);

		parser.parse_memory_raw((unsigned char*) fp.getData(), fp.getSize());

		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::Tileset).validate(
				parser.get_document());
	} catch (const std::exception &ex) {
		throw Exception(path, ex.what());
	}

	// Get the root element
	xmlpp::Element *root = parser.get_document()->get_root_node();

	// Get the vital data
	tileWidth = strTo10(root->get_attribute_value("tilewidth").c_str());
	tileHeight = strTo10(root->get_attribute_value("tileheight").c_str());

	// Get the main Image
	img =
			&System::getInstance().getResourcesManager().getBitmap(
					StringOperations::translateUnixPath(this->name,
							static_cast<xmlpp::Element*>(root->get_first_child(
									"image"))->get_attribute_value("source")));

	{
		// Calculate the tiles that exist in every axis
		int numTiles_W = img->getWidth() / tileWidth;
		int numTiles_H = img->getHeight() / tileHeight;

		// Calculate the number of tiles
		numTiles = numTiles_W * numTiles_H;

		// Reserver the subBitmaps
		img->reserveSubBitmaps(numTiles + 1);
		tiles.resize(numTiles + 2);

		{
			unsigned int index = 0;
			// for all the Tiles on both axis
			for (int i = 0; i < numTiles_H; ++i) {
				for (int j = 0; j < numTiles_W; ++j) {
					// Get the tile from the calculated coordinates
					tiles[index].set(
							img->createSubBitmap(j * tileWidth, i * tileHeight,
									tileWidth, tileHeight), index);
					// increase the table index
					++index;
				}
			}
		}

		// Find all the animation nodes
		xmlpp::NodeSet props = root->find("//animation");

		// for all the Nodes
		for (auto node : props) {

			// Get the tile that has this ID
			Tile& tile = tiles[strTo10(
					node->get_parent()->get_attribute_value("id").c_str())];

			// Set that this Tile is animated
			tile.setAnimated(true);

			// Get all the frame nodes
			xmlpp::NodeSet frameNodes = node->find("./frame");

			// For all the frame nodes
			for (auto frameNode : frameNodes) {
				xmlpp::Element* element =
						static_cast<xmlpp::Element*>(frameNode);

				// Create a Tile frame
				Tile::TileFrame frame;

				// Get the tile that this Frame will have
				frame.tile = &tiles[strTo10(
						element->get_attribute_value("tileid").c_str())];
				// Get the delay of this frame
				frame.uptime = strTo10(
						element->get_attribute_value("duration").c_str())
						/ 1000.0f;

				// Add the frame to the tile
				tile.addFrame(frame);
			}
		}

		// get tall the properties Nodes
		props = root->find("//properties");

		// For all the nodes
		for (auto node : props) {

			// Get the Tile that is referenced
			Tile& tile = tiles[strTo10(
					node->get_parent()->get_attribute_value("id").c_str())];

			// Get the Collision Property
			xmlpp::NodeSet propsNodes = node->find(
					"./property[@name='Collision']");

			// If the property is found
			if (propsNodes.size() > 0) {

				// Get the collision Value
				int coll =
						strTo10(
								static_cast<xmlpp::Element*>(propsNodes[0])->get_attribute_value(
										"value").c_str());
				tile.setCollision((Tile::Collision) coll);

			}

			// Check if the tile is animated
			if (tile.isAnimated()) {

				// Check for Relative tiles
				propsNodes = node->find("./property[@name='Relatives']");

				// Check if there is any relatives
				if (propsNodes.size() > 0) {

					// We have to tokenize the value
					std::list<std::string> tokens;

					// Tokenize with the , value
					StringOperations::getTokens(
							static_cast<xmlpp::Element*>(propsNodes[0])->get_attribute_value(
									"value"), ',', tokens);
					// For all the Tokens
					for (auto& token : tokens) {
						// Add to the Tile the Relative
						unsigned int index = strTo10(token.c_str());
						if (index <= tiles.size()) {
							tile.addRelativeTile(tiles[index]);
						}
					}
				}
			}
		}

	}
}

Tileset::~Tileset() {
	// Get the Resources Context
	ResourceContext* resources = &System::getInstance().getResourcesManager();
	// Check if the resource Context exists
	if (resources != nullptr) {
		// If the resources Context exist, then release the main Image
		resources->releaseResource(*img);
	}
}

} /* namespace Zeta */

