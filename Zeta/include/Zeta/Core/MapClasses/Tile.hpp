/*
 * Tile.hpp
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

#ifndef TILE_HPP_
#define TILE_HPP_

#include <vector>

#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/Updateable.hpp>

namespace Zeta {

class Bitmap;

/**
 * Class for the Tile
 */
class Tile: public Drawable, public Updateable {
public:
	enum Collision {
		None = 0x0,
		N = 0x3,
		E = 0xA,
		S = 0xC,
		W = 0x5,
		NW = 0x1,
		NE = 0x2,
		SE = 0x8,
		SW = 0x4,
		NxW = 0x7,
		NxE = 0xB,
		SxE = 0xE,
		SxW = 0xD,
		NWxSE = 0x9,
		SWxNE = 0x6,
		Full = 0xF
	};

	/**
	 * Struct for containing the Frame Data
	 */
	struct TileFrame {
		Tile* tile;
		Float uptime;
	};

	/**
	 * Gets the ID of the Tile inside it's Tileset
	 * @return The tile's ID
	 */
	inline unsigned int getID() const {
		return id;
	}

	/**
	 * Sets the Collision value of the Tile
	 * @param coll The Collision value to set
	 */
	void setCollision(Collision coll) {
		collision_value = coll;
	}

	/**
	 * Gets the Collision Value of the Tile
	 * @return The Collision Value
	 */
	inline Collision getCollision() const {
		return collision_value;
	}

	/**
	 * Adds the Frame to the end of the Frames Table
	 * @param frame The frame to add
	 */
	void addFrame(TileFrame& frame) {
		frames.push_back(frame);
	}

	/**
	 * Adds the Tile to this Tile's Relative tiles
	 * \note It is not mutual. This Tile will not be added as a Relative to the other's
	 * @param other The Tile to add as a relative
	 */
	void addRelativeTile(Tile& other) {
		relativeTiles.push_back(&other);
	}

	/**
	 * Sets whether the Tile is Animated
	 * @param value true for the tile to be Animated
	 */
	void setAnimated(bool value) {
		animated = value;
	}

	/**
	 * Gets whether the Tile is Animated
	 * @return true if the Tile is Animated
	 */
	inline bool isAnimated() const {
		return animated;
	}

	/**
	 * Gets the Relative Tiles of this Tiles
	 * @return The vector of the Relative Tiles
	 */
	inline const std::vector<Tile*>& getRelativeTiles() const {
		return relativeTiles;
	}

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	/**
	 * Assigns the Image and the ID to the Tile
	 * @param bmp The Bitmap to assign
	 * @param id The ID to assign
	 */
	void set(const Bitmap& bmp, unsigned int id) {
		img = &bmp;
		this->id = id;
	}

	inline void update(Float elapsedTime) {
		frameCounter -= elapsedTime;
		if (frameCounter <= 0.0f) {
			if (++frameIndex >= frames.size()) {
				frameIndex = 0;
			}
			frameCounter = frames[frameIndex].uptime;
		}
	}

	/**
	 * Constructs a Tile with ID=0 and NullBitmap as Image
	 */
	Tile();

	/**
	 * Constructs and assigns the Bitmap and ID
	 * @param bmp The Bitmap to assign
	 * @param id The ID to assign
	 */
	Tile(const Bitmap& bmp, unsigned int id);

	virtual ~Tile() {

	}
protected:
	std::vector<TileFrame> frames;
	std::vector<Tile*> relativeTiles;
	const Bitmap *img;
	unsigned int id;
	Collision collision_value;

	unsigned int frameIndex;
	Float frameCounter;
	bool animated;

	friend class Tileset;
};

} /* namespace Zeta */

#endif /* TILE_HPP_ */
