/*
 * AnimationPlayer.hpp
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

#ifndef ZETA_CORE_ANIMATIONCLASSES_ANIMATIONPLAYER_HPP_
#define ZETA_CORE_ANIMATIONCLASSES_ANIMATIONPLAYER_HPP_

#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Animation;

/**
 * AnimationPlayer Class
 * Objects of this class play and draw an Animation
 */
class AnimationPlayer: public Drawable, public Updateable {
public:

	/**
	 * Gets whether the Animation is playing
	 * @return true if the animation is playing
	 */
	bool isPlaying() const {
		return playing;
	}

	/**
	 * Gets whether the Animation will be drawn
	 * when the draw() will be called
	 * @return true if the animation will be drawn
	 */
	bool isVisible() const {
		return visible;
	}

	/**
	 * Sets whether the animation will be drawn
	 * when the draw() will be called
	 * @param visible true if the Animation must be drawn
	 */
	void setVisible(bool visible) {
		this->visible = visible;
	}

	/*
	 * Gets the Animation that will be handled
	 * @return The animation
	 */
	const Animation& getAnimation() const {
		return *animation;
	}

	/**
	 * Causes the Animation not to be drawn
	 */
	void hide() {
		visible = false;
	}

	/**
	 * Causes the Animation to be drawn when
	 * it should
	 */
	void show() {
		visible = true;
	}

	/**
	 * Causes the Animation to play
	 */
	void play() {
		playing = true;
	}

	/**
	 * Causes the Animation to stop
	 * and reset the to the first Cell (Frame)
	 * \note it does not hide it, it will just freeze on the first frame
	 */
	void stop() {
		playing = false;
		frameTimer = 0;
		frameIndex = 0;
	}

	/**
	 * Causes the Animation to stop
	 * \note it does not hide it, it will just freeze on the frame it is when this function was called
	 */
	void pause() {
		playing = false;
	}

	/**
	 * Causes the Animation to reset to the first frame
	 */
	void reset() {
		frameTimer = 0;
		frameIndex = 0;
	}

	/**
	 * Sets the animation that will be played
	 * @param animation The Animation object to be played
	 */
	void setAnimation(const Animation& animation);

	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	/**
	 * Updates the animation if it is played
	 * It changes its frames when it should
	 */
	void update(Float elapsedTime);

	/**
	 * It assigns a Null animation
	 */
	AnimationPlayer();

	/**
	 * It assigns the Animation provided
	 * @param animation The animation to be played
	 */
	AnimationPlayer(const Animation& animation) :
			animation(&animation), frameIndex(0), frameTimer(0), playing(true), visible(
					true) {

	}
	AnimationPlayer(AnimationPlayer&&) = default;
	AnimationPlayer(const AnimationPlayer&) = default;
	AnimationPlayer& operator=(AnimationPlayer&&) = default;
	AnimationPlayer& operator=(const AnimationPlayer&) = default;
	virtual ~AnimationPlayer() {

	}
private:
	const Animation* animation;
	int frameIndex;
	Float frameTimer;
	bool playing;
	bool visible;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_ANIMATIONCLASSES_ANIMATIONPLAYER_HPP_ */
