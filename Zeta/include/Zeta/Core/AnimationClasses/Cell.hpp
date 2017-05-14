/*
 * Cell.hpp
 *
 *  Created on: 8 Ιαν 2014
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

#ifndef CELL_HPP_
#define CELL_HPP_

#include <Zeta/Core/AnimationClasses/Sprite.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <list>

namespace xmlpp {
class Node;
}

namespace Zeta {

class SpriteSheet;

/**
 * Cell class for creating and Handling Animation Cells
 * Cells are actually the Animation Frames. They can contain several Sprites.
 */
class Cell: public Drawable {
public:

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	/**
	 * Adds the created Sprite on the appropriate position
	 * The position is calculated based on the Sprites Z value
	 * @param spr The Sprite to add
	 */
	void addSprite(const Sprite& spr);

	/**
	 * Creates and adds a sprite based on the information of the xml node provided
	 * The sprite is created from the spritesheet provided.
	 * \note The node must be a valid <anim> node. If you don't know what that means, stop here.
	 * @param sprNode The xml <anim> node that will be processed
	 * @param spriteSheet The SpriteSheet that has the Image the Sprite will use
	 */
	void addSprite(xmlpp::Node *sprNode, const SpriteSheet& spriteSheet) {
		addSprite(Sprite(sprNode, spriteSheet));
	}

	/**
	 * Gets the Duration of the Cell
	 * @return The duration
	 */
	inline Float getDelay() const {
		return delay;
	}

	/**
	 * Clears and destroys any sprite that the Cell has
	 * \note It should be called every time a Cell is constructed!
	 */
	void clearSprites() {
		sprites.clear();
	}

	Cell(Cell&&) = default;
	Cell& operator=(Cell&&) = default;

	/**
	 * Empty Cell with a empty Sprite
	 */
	Cell() :
			delay(1) {
		sprites.push_back(Sprite());
	}

	/**
	 * Empty Cell with a empty Sprite and duration provided
	 */
	Cell(Float delay) :
			delay(delay) {
		sprites.push_back(Sprite());
	}

	/**
	 * Adds the Sprite to list and the duration
	 */
	Cell(Float delay, const Sprite& sprite) :
			delay(delay) {
		sprites.push_back(sprite);
	}
	~Cell() {

	}
protected:
	std::list<Sprite> sprites;
	Float delay;
};

} /* namespace Zeta */

#endif /* CELL_HPP_ */
