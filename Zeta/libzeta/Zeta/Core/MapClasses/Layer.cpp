/*
 * Layer.cpp
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

#include <Zeta/Core/MapClasses/Layer.hpp>
#include <Zeta/Core/MapClasses/Tile.hpp>
#include <Zeta/Core/MapClasses/Tileset.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <glibmm/ustring.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/textnode.h>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/ShapeRenderer.hpp>
#include <Zeta/Core/UtilityClasses/base64.h>
#include <zconf.h>
#include <zlib.h>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <string>

namespace Zeta {

Layer::Layer() :
		parent(nullptr), width(10), height(10), tileWidth(64), tileHeight(64) {
	nullise();
}

Layer::Layer(xmlpp::Element *layerNode, const std::vector<MapTileset> &tilesets,
		Map &parrent) :
		parent(&parrent) {

	// Get the tile dimensions
	tileWidth = parrent.getTileWidth();
	tileHeight = parrent.getTileHeight();

	// Get the dimensions of the Layer
	width = strTo10(layerNode->get_attribute_value("width").c_str());
	height = strTo10(layerNode->get_attribute_value("height").c_str());

	// Resize the Tiles table to the Layer Dimensions
	tiles.resize(height, width);

	// Get the Layer Raw Data node
	layerNode = static_cast<xmlpp::Element*>(layerNode->find("./data")[0]);

	// The pointer that will contain all the Layer's GID reference Numbers
	unsigned int *gids = nullptr;

	{

		// Get the Data String
		auto data = layerNode->get_child_text()->get_content();
		// We have to clean the RAW data from spaces and line breaks
		// So this i will have the number of chars to discard from
		// the beginning
		int i = 0;
		// For all the character on the string
		for (auto c : data) {
			// check if the char is a whitespace
			if (c == ' ' || c == '\n' || c == '\t') {
				// if it is, then increase the i
				++i;
			} else {
				// if it is not, then we reached the actual data
				break;
			}
		}

		// clean the data from the initial whitespace
		data = data.substr(i);

		// Decode the data from the Base64
		const std::string &decoded = base64_decode(data);

		// get The size of the GID will have (size * 4 bytes (int))
		uLongf size = (width * height) << 2;

		// Allocate memory for the GIDS
		gids = new unsigned int[size];

		// try to uncompress the Decoded data
		if (uncompress((Bytef*) gids, &size, (const Bytef*) decoded.data(),
				decoded.size()) != Z_OK) {
			// If something happened report it
			Logger::getInstance().write(
					"During uncompressing the Decoded Data from a Layer of the Map: "
							+ parrent.getName(), Logger::MessageType::Error);
			// Delete the allocated data
			delete[] gids;
			// return
			return;
		}
	}

	// If everything was allright when uncompressing
	// we have to get the referenced tiles
	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < width; ++j) {

			// Calculate the Index of the tile on the Table
			int index = i * width + j;

			// check if the GID there has a reference
			if (gids[index] == 0) {
				// if it does not, then do not assign anything
				continue;
			}

			// Remove the flags of the Tile
			gids[index] &= ~(0x80000000u | 0x40000000u | 0x20000000u);

			// We have to find in which Tileset this GID residents
			// We have to itertate The tilesets in reverse, to get first the
			// Tileset with the larger First GID
			for (auto itr = tilesets.rbegin(); itr != tilesets.rend(); ++itr) {
				// Check if this Tileset's First GID is bellow the Tile's GID
				if ((*itr).getFirstGid() <= gids[index]) {
					// If it does, then assign the Tile to the Table's pointer
					tiles(j, i) = (*itr).getTileset()->getMapTile(
							gids[index] - (*itr).getFirstGid());
					// We need to go no further since we found it
					break;
				}
			}

		}
	}

	// deallocate the data
	delete[] gids;
}

void Layer::draw(float dx, float dy, int numTilesX, int numTilesY) const {

	// Calculate the start Tile Coordinates (Top Left Tile)
	int startTileX = (dx / tileWidth);
	int startTileY = (dy / tileHeight);
	// Calculate the End Tile coordinates (Bottom Right Tile)
	unsigned int endTileX = startTileX-- + numTilesX;
	unsigned int endTileY = startTileY-- + numTilesY;

	// Check if the Coordinates are valid
	// and if they are not, correct them
	if (startTileX < 0) {
		startTileX = 0;
	}
	if (startTileY < 0) {
		startTileY = 0;
	}
	if (endTileX >= width) {
		if (width > 0) {
			endTileX = width - 1;
		} else {
			endTileX = 0;
		}
	}
	if (endTileY >= height) {
		if (height > 0) {
			endTileY = height - 1;
		} else {
			endTileY = 0;
		}
	}

	// Get the Renderer and apply the Hold Optimization
	auto& renderer = System::getInstance().getShapeRenderer();
	renderer.holdBitmapDraw(true);
	// for all the Tiles we calculated
	for (unsigned int i = startTileY; i <= endTileY; ++i) {
		for (unsigned int j = startTileX; j <= endTileX; ++j) {
			// Get the tile at the coordinates
			const Tile* tile = tiles(j, i);
			// Check if the tile exists
			if (tile != nullptr) {
				// if it exists, then check if it animated
				if (tile->isAnimated()) {
					// if it is animated, let the Parrent Map
					// that this tile must be updated
					parent->addTileToUpdate(const_cast<Tile*>(tile));
				}
				// Draw the Tile on the appropriate coordinates
				tile->draw(std::ceil(((j * tileWidth) - dx) + 0.5f),
						std::ceil(((i * tileHeight) - dy) + 0.5f));
			}
		}
	}
	// Stop the optimization
	renderer.holdBitmapDraw(false);

}

const Tile* Layer::getTileAt(unsigned int x, unsigned int y) const {
	// Check if the coordinates a valid
	if (x < width && y < height) {
		// if they are valid, return the tile there
		return tiles(x, y);
	} else {
		// if they are not valid, return nullptr
		return nullptr;
	}
}
Layer::~Layer() {

}

void Layer::nullise() {
	tiles.resize(height, width);
	// Assign a NullTile to every tile the layer has
	auto* nullTile = &NullReference<Tile>::getNull();
	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < width; ++j) {
			tiles(j, i) = nullTile;
		}
	}
}

} /* namespace Zeta */
