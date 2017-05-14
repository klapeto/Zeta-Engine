/*
 * AnimationPlayer.cpp
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

#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/AnimationClasses/AnimationPlayer.hpp>
#include <Zeta/Core/AnimationClasses/Cell.hpp>
#include <Zeta/Core/NullReference.hpp>

namespace Zeta {

AnimationPlayer::AnimationPlayer() :
		animation(&NullReference<Animation>::getNull()), frameIndex(0), frameTimer(
				0), playing(true), visible(true) {
}

void AnimationPlayer::setAnimation(const Animation& animation) {
	// Check if an evil guy called the function
	if (&animation != nullptr) {
		// set the new animation reference
		this->animation = &animation;
		// set to the first frame
		frameIndex = 0;
		// get the animations first frame delay
		frameTimer = animation.getFrame(0).getDelay();
	}
}

void AnimationPlayer::draw(Float x, Float y, Float rotation,
		Float scale) const {
	// Check if the animation should be drawn
	if (visible) {
		// If it should, the draw the Animation's frame pointed by the frameIndex
		animation->getFrame(frameIndex).draw(x, y, rotation, scale);
	}
}

void AnimationPlayer::update(Float elapsedTime) {
	// Check if the animation is playing. We should only update it if
	// it is playing
	if (playing) {
		// subtract the time elapsed from the frame's remaining time
		frameTimer -= elapsedTime;
		// check if the remaining time has reached 0
		if (frameTimer <= 0.0f) {
			// if there is no remaining time, then we should switch to
			// Animation's next frame. Before we do that, we should check if
			// we reached beyond the last frame. We do that by checking
			// if the frameIndex is greater than the animations frame count
			if (++frameIndex >= animation->getNumFrames()) {
				// If we passed the last frame, check if the animation loops
				if (!animation->isLooping()) {
					// If it does not loop, then stop it
					playing = false;
					// we should decrease the frameIndex because it points
					// beyond the last frame. So it should point to last.
					--frameIndex;
				} else {
					// if the animation should loop, then set the frameIndex
					// to the first frame
					frameIndex = 0;
				}
			}
			// set the frame remaining time to the new frame's delay
			frameTimer = animation->getFrame(frameIndex).getDelay();
		}
	}
}

} /* namespace Zeta */
