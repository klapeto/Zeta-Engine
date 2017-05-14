/*
 * Tileset.hpp
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

#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <string>
#include <vector>

#include <Zeta/Core/MapClasses/Tile.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>

namespace Zeta {

class Bitmap;

/**
 * Class for loading and storing External Tiled Tilesets
 */
class Tileset: public Resource {
public:

	/**
	 * Gets the Tile defined by the ID
	 * If the ID is invalid, then the NullTile is returned
	 * @param id The id of the tile to return
	 * @return The tile of the ID provided or NullTile on invalid ID
	 */
	const Tile& getTile(unsigned int id) const;

	/**
	 * Gets the Tile defined by the ID
	 * If the ID is invalid, then the NULL is returned
	 * @param id The id of the tile to return
	 * @return The tile of the ID provided or NULL on invalid ID
	 */
	const Tile* getMapTile(unsigned int id) const;

	/**
	 * Loads the Tileset from the File
	 * @param path The filename to load
	 */
	void load(const std::string& path);

	Tileset(Tileset&&) = default;
	Tileset(const Tileset&) = default;
	Tileset& operator=(const Tileset&) = default;
	Tileset& operator=(Tileset&&) = default;

	/**
	 * Constructs an Empty Tileset
	 */
	Tileset();

	/**
	 * Constructs and Loads the Tileset from the File provided
	 * @param path The filename to Load
	 */
	Tileset(const std::string& path);

	virtual ~Tileset();
protected:

	std::vector<Tile> tiles;
	const Bitmap *img;
	int tileWidth;
	int tileHeight;
	unsigned int numTiles;
};

} /* namespace Zeta */

#endif /* TILESET_HPP_ */
