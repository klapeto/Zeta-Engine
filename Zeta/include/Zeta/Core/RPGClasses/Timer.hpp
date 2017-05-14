/*
 * Timer.hpp
 *
 *  Created on: 16 Ιαν 2015
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

#ifndef ZETA_CORE_RPGCLASSES_TIMER_HPP_
#define ZETA_CORE_RPGCLASSES_TIMER_HPP_

#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Timer: public Updateable, public LuaPushable {
public:

	Float getMaxTime() const {
		return maxTime;
	}

	void setMaxTime(Float maxTime) {
		this->maxTime = maxTime;
		if (remainingTime > maxTime) {
			remainingTime = maxTime;
		}
	}

	Float getRemainingTime() const {
		return remainingTime;
	}

	void setRemainingTime(Float remainingTime) {
		this->remainingTime = remainingTime;
	}

	bool isOver() const {
		return !running;
	}

	bool isRunning() const {
		return running;
	}

	void start() {
		running = true;
	}

	void pause() {
		running = false;
	}

	void reset() {
		remainingTime = maxTime;
	}

	inline void update(Float elapsedTime) {
		if (running) {
			remainingTime -= elapsedTime;
			if (remainingTime <= 0.0f) {
				remainingTime = maxTime;
				running = false;
				callback();
			}
		}
	}

	void setCallback(lua_Object func);
	void pushToLua(lua_State *lstate);

	Timer(Float maxTime);
	~Timer();
private:
	LuaFunctor callback;
	Float maxTime;
	Float remainingTime;
	bool running;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RPGCLASSES_TIMER_HPP_ */
