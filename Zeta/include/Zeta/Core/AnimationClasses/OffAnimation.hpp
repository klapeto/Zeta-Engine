/*
 * OffAnimation.hpp
 *
 *  Created on: 7 Νοε 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#ifndef ZETA_CORE_ANIMATIONCLASSES_OFFANIMATION_HPP_
#define ZETA_CORE_ANIMATIONCLASSES_OFFANIMATION_HPP_

#include <Zeta/Core/AnimationClasses/AnimationPlayer.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * Class for Creating OffAnimations
 * for AnimationHandlers
 */
class OffAnimation: public AnimationPlayer {
public:

	/**
	 * Gets the offset on the x axis
	 * @return The offset
	 */
	Float getDx() const {
		return dx;
	}

	/**
	 * Sets the offset on the x axis
	 * @param dx The offset to set
	 */
	void setDx(Float dx) {
		this->dx = dx;
	}

	/**
	 * Gets the offset on the y axis
	 * @return The offset
	 */
	Float getDy() const {
		return dy;
	}

	/**
	 * Sets the offset on the y axis
	 * @param dy The offset to set
	 */
	void setDy(Float dy) {
		this->dy = dy;
	}

	/**
	 * Sets the offsets on both axis
	 * @param dx The offset on the x axis
	 * @param dy The offset on the y axis
	 */
	void setOffsets(Float dx, Float dy) {
		this->dx = dx;
		this->dy = dy;
	}

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const {
		AnimationPlayer::draw(x + dx, y + dy, rotation, scale);
	}

	/**
	 * Constructs an OffAnimation with NullAnimation as the Animation
	 */
	OffAnimation() :
			AnimationPlayer(), dx(0.0f), dy(0.0f) {

	}

	/**
	 * Constructs an OffAnimation and asigns the Animation
	 * @param animation The Animation to assign
	 */
	OffAnimation(const Animation& animation) :
			AnimationPlayer(animation), dx(0.0f), dy(0.0f) {
	}

	OffAnimation(OffAnimation&&) = default;
	OffAnimation(const OffAnimation&) = default;
	OffAnimation& operator=(OffAnimation&&) = default;
	OffAnimation& operator=(const OffAnimation&) = default;

	~OffAnimation() {

	}

private:
	Float dx;
	Float dy;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_ANIMATIONCLASSES_OFFANIMATION_HPP_ */
