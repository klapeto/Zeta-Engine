/*
 * Timer.cpp
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/RPGClasses/Timer.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <tolua++.h>
#include <string>

namespace Zeta {

Timer::Timer(Float maxTime) :
		maxTime(maxTime), remainingTime(maxTime), running(false) {
	WorldManager::getInstance().addFrameListener(this);
}

void Timer::setCallback(lua_Object func) {
	try {
		callback.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During assigning a Lua function to a Timer Lua Callback: "
						+ ex.reason());
	}
}

Timer::~Timer() {
	WorldManager::getInstance().removeFrameListener(this);
}

void Timer::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Timer");
}
} /* namespace Zeta */
