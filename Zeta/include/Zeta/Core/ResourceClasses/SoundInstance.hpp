/*
 * SoundInstance.hpp
 *
 *  Created on: 18 Απρ 2014
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

#ifndef SOUNDINSTANCE_HPP_
#define SOUNDINSTANCE_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/NonCopyable.hpp>

namespace Zeta {

class Sound;

/**
 * The SoundInstance Class
 * These objects are created by Sounds to distribute the control
 * to the rest parts of the Engine where they need this Sound, rather
 * control the Sound itself and create Havoc when many parts need it at
 * the same time. It sound behave as a copy of the sound.
 */
class SoundInstance: public LuaPushable, public NonCopyable {
public:

	/**
	 * Plays the sound
	 */
	virtual void play()=0;

	/**
	 * Stops the sound if playing
	 */
	virtual void stop()=0;

	/**
	 * Sets if the sound should repeat after it ended
	 * IMPORTANT! The field loops should set too!
	 * @param value true if the sound should loop, otherwise false
	 */
	virtual void setLoop(bool value)=0;

	/**
	 * Sets the gain of the sound (Right of left)
	 * IMPORTANT! The field gain should set too!
	 * @param value the gain of the sound to set
	 */
	virtual void setGain(float value)=0;

	/**
	 * Sets the pan of the sound
	 * The pan takes a value between -1 to 1 where
	 * -1=Left, 0=Center, 1=Right
	 * IMPORTANT! The field pan should set too!
	 * @param value the pan of the sound to set
	 */
	virtual void setPan(float value)=0;

	/**
	 * Returns the value of the Pan
	 * @return The Current pan
	 */
	float getPan() const {
		return pan;
	}

	/**
	 * Returns if the sound will Loop
	 * @return true if the sound will Loop
	 */
	bool getLoop() const {
		return loops;
	}

	/**
	 * Returns the value of the Gain
	 * @return The Current gain
	 */
	float getGain() const {
		return gain;
	}

	SoundInstance(SoundInstance&&) = default;
	SoundInstance& operator=(SoundInstance&&) = default;

	/**
	 * Pushes the Object to the Lua Environment
	 * @param lstate The Lua Environment to push to.
	 */
	void pushToLua(lua_State* lstate);

	SoundInstance();
	virtual ~SoundInstance();
protected:
	const Sound *parentSound;
	float gain;
	float pan;

	bool loops;
};

} /* namespace Zeta */

#endif /* SOUNDINSTANCE_HPP_ */
