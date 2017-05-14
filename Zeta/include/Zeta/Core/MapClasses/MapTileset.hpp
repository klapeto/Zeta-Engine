/*
 * MapTileset.hpp
 *
 *  Created on: 11 Μαρ 2016
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

#ifndef ZETA_CORE_MAPCLASSES_MAPTILESET_HPP_
#define ZETA_CORE_MAPCLASSES_MAPTILESET_HPP_

namespace Zeta {

class Tileset;

/**
 * Class for internal Tileset Ordering in the Map class
 */
class MapTileset {
public:

	/**
	 * Gets the Global ID of the first Tile
	 * @return The Gid
	 */
	unsigned int getFirstGid() const {
		return firstGid;
	}

	/**
	 * Sets the Global ID of the first Tile
	 * @param gid The Gid to assign
	 */
	void setFirstGid(unsigned int gid) {
		this->firstGid = gid;
	}

	/**
	 * Gets the Tileset
	 * @return The Tileset
	 */
	const Tileset* getTileset() const {
		return tileset;
	}

	/**
	 * Sets the Tileset
	 * @param tileset The tileset to set
	 */
	void setTileset(const Tileset* tileset) {
		this->tileset = tileset;
	}

	/**
	 * Constructs an empty MapTileset with a NullTileset
	 */
	MapTileset();

	/**
	 * Constructs and assigns the Tileset and the Gid
	 * @param tilset The Tileset to assign
	 * @param gid The Gid to assign
	 */
	MapTileset(const Tileset* tileset, unsigned int firstGid) :
			tileset(tileset), firstGid(firstGid) {

	}
	~MapTileset() {

	}
private:
	const Tileset* tileset;
	unsigned int firstGid;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_MAPCLASSES_MAPTILESET_HPP_ */
