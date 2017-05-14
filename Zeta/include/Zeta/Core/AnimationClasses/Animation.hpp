/*
 * Animation.hpp
 *
 *  Created on: 7 Ιαν 2014
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

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <Zeta/Core/AnimationClasses/Cell.hpp>
#include <string>
#include <vector>

namespace xmlpp {
class Node;
}

namespace Zeta {

class AnimationPack;
class SpriteSheet;

/**
 * Class for loading and handling Animations
 */
class Animation {
public:

	/**
	 * Get the name of the Animation
	 * @return The name of the animation
	 */
	const std::string& getName() const {
		return name;
	}

	/**
	 * Sets the name of the Animation
	 * @param name The name to assign
	 */
	void setName(const std::string& name) {
		this->name = name;
	}

	/**
	 * Gets whether the animation Loops after the last Cell
	 * @return true If it loops
	 */
	bool isLooping() const {
		return loops;
	}

	/**
	 * Returns the AnimationPack that contains this animations
	 * @return The animation pack
	 */
	const AnimationPack& getAnimationPack() const {
		return *parentPack;
	}

	/**
	 * Gets the number of the frames (Cells) the animation Has
	 * @return The number of Frames
	 */
	inline int getNumFrames() const {
		return cells.size();
	}

	/**
	 * Gets the Frame (Cell) of the target Index
	 * \note use the function with caution. It does no bound check
	 * @param index The index of the Frame to return
	 * @return The Cell
	 */
	inline const Cell& getFrame(unsigned int index) const {
		return cells[index];
	}

	/**
	 * Loads the animation the xml node describes from the AnimationPack provided
	 * @param node The node that has the <anim> value
	 * @param parent The AnimationPack that will have this Animation
	 */
	void set(xmlpp::Node *node, const AnimationPack &parent);

	Animation(Animation&&) = default;
	Animation& operator=(Animation&&) = default;

	/**
	 * Constructs an Empty Animation
	 */
	Animation();
	/**
	 * \see set()
	 */
	Animation(xmlpp::Node *node, const AnimationPack &parent);
	virtual ~Animation();
protected:
	std::string name;
	std::vector<Cell> cells;
	const AnimationPack *parentPack;
	bool loops;
};

} /* namespace Zeta */

#endif /* ANIMATION_HPP_ */
