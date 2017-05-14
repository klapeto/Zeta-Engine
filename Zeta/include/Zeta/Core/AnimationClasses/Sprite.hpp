/*
 * Sprite.hpp
 *
 *  Created on: 1 Μαρ 2016
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

#ifndef ZETA_CORE_ANIMATIONCLASSES_SPRITE_HPP_
#define ZETA_CORE_ANIMATIONCLASSES_SPRITE_HPP_

#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/ResourceClasses/Bitmap.hpp>

namespace xmlpp {
class Node;
}

namespace Zeta {

class SpriteSheet;

/**
 * Class for constructing and Drawing sprites
 */
class Sprite: public Drawable {
public:

	/**
	 * Gets the Z Index
	 * The Z index is a number that defines the position
	 * inside the Cell
	 * @return The Z value
	 */
	inline int getZ() const {
		return z;
	}

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	/**
	 * Empty drawable Sprite
	 */
	Sprite();

	/**
	 * Constructs and Loads the Sprite according to the information
	 * provided by the xml node <spr> and the SpriteSheet
	 * @param the Node that has the <spr> node
	 * @param The SpriteSheet that has the image of the Sprite
	 */
	Sprite(xmlpp::Node *node, const SpriteSheet& spriteSheet);
	~Sprite() {

	}
protected:
	const Bitmap *image;
	int x;
	int y;
	int z;
	float angle;
	Bitmap::FlipFlag flip;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_ANIMATIONCLASSES_SPRITE_HPP_ */
