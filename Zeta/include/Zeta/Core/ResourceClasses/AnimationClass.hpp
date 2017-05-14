/*
 * AnimationClass.hpp
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

#ifndef ANIMATIONCLASS_HPP_
#define ANIMATIONCLASS_HPP_

#include <string>

#include <Zeta/Core/UtilityClasses/Ellipsis.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/RPGClasses/LifeformState.hpp>
#include <Zeta/Core/UtilityClasses/Vector2D.hpp>
#include <Zeta/Core/ZSmallMap.hpp>

namespace Zeta {

class Animation;

/**
 * Class for Animation Classes
 * Animation Classes are a group of Animations that can be
 * assigned to a Lifeform. Usually the animations are related
 */
class AnimationClass: public Resource {
public:

	/**
	 * Gets the named animation
	 * If the animation does not exist, then the fallback
	 * animation will be returned. If not defined, the fallback
	 * is IDLE+DOWN.
	 * @param name The name of the animation to return
	 * @param fallbackAnimation The animation State to return if the animation does not exist
	 * @return the Animation to be returned
	 */
	const Animation& getAnimation(const std::string& name,
			LifeformState::CombinedState fallbackAnimation =
					LifeformState::Action::Idle
							| LifeformState::Direction::Down) const;

	/**
	 * Gets the Animation defined by the State
	 * @param state The state that has the animation
	 * @return the Animation to be returned
	 */
	const Animation& getAnimation(LifeformState::CombinedState state) const;

	/**
	 * Gets the Boundary Rectangle of this Class
	 * This rectangle is used for Collision Detection
	 * @return The Boundary Rectangle
	 */
	const Rectangle& getBoundBox() const {
		return boundBox;
	}

	/**
	 * Gets the Target Rectangle of this Class
	 * This rectangle is used for Targeting
	 * @return The Target Rectangle
	 */
	const Rectangle& getTargetBox() const {
		return targetBox;
	}

	/**
	 * Gets the Shadow Ellipsis of this Class
	 * @return The Shadow Ellipsis
	 */
	const Ellipsis& getShadow() const {
		return shadow;
	}

	/**
	 * Get whether this Class has a Shadow
	 * @return true if it has Shadow
	 */
	bool hasShadow() const {
		return has_Shadow;
	}

	/**
	 * Default Constructor
	 * Constructs a Null AnimationClass that contains no Animations
	 * and all State Animations are NullAnimations
	 */
	AnimationClass();

	/**
	 * Loads the Animation Class File
	 */
	AnimationClass(const std::string& path);
	virtual ~AnimationClass();
protected:

	ZSmallMap<std::string, const Animation*> animations;
	Vector2D<const Animation*> primAnimations;
	Rectangle boundBox;
	Rectangle targetBox;
	Ellipsis shadow;
	const Animation* nullAnimation;

	bool has_Shadow;

	void retrivePrimitives();
};

} /* namespace Zeta */

#endif /* ANIMATIONCLASS_HPP_ */
