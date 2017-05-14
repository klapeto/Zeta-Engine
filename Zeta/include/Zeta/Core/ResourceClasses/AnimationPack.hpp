/*
 * AnimationPack.hpp
 *
 *  Created on: 25 Φεβ 2014
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

#ifndef ANIMATIONPACK_HPP_
#define ANIMATIONPACK_HPP_

#include <string>
#include <vector>

#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/ResourceClasses/SpriteSheet.hpp>
#include <Zeta/Core/ZSmallMap.hpp>

namespace Zeta {

class SpriteSheet;

/**
 * A Class for loading animation Files (*.anim)
 */
class AnimationPack: public Resource {
public:

	/**
	 * Gets the animation by name
	 * If the requested animation is not availabe, then a NullAnimation will be returned
	 * @param name The name of the animation to retrieve
	 * @return The animation requested
	 */
	const Animation& getAnimation(const std::string& name) const;

	/**
	 * Gets the referenced Spritesheet of the Animations
	 * @return The Spritesheet
	 */
	const SpriteSheet& getSpriteSheet() const {
		return *spriteSheet;
	}

	/**
	 * Gets a list of the Names of the Available animations
	 * @return A vector of the names
	 */
	std::vector<std::string> listAnimationNames() const;

	/**
	 * Default Constructor
	 * Creates a Null AnimationPack with no animations and a Null Spritesheet
	 */
	AnimationPack();

	/**
	 * Loads the Animation Pack File and Parses it
	 * If anything goes wrong, then it throws a Zeta::Exception
	 * @param path The filename to load
	 */
	AnimationPack(const std::string& path);

	/**
	 * Deconstructor
	 * Deallocates all animations and releases the Reference to the Spritesheet
	 */
	~AnimationPack();
protected:
	ZSmallMap<std::string, Animation> animations;
	const SpriteSheet *spriteSheet;
};

} /* namespace Zeta */

#endif /* ANIMATIONPACK_HPP_ */
