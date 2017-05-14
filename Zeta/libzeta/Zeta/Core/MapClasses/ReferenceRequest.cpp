/*
 * ReferenceRequest.cpp
 *
 *  Created on: 11 Μαρ 2016
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

#include <Zeta/Core/MapClasses/ReferenceRequest.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <lua.hpp>

namespace Zeta {

void ReferenceRequest::handle(RenderingContext& context) {
	lua_State* lstate = LuaEngine::getInstance().getState();
	if (luaL_loadstring(lstate, script.c_str())) {
		// If there is an error, log it
		Logger::getInstance().write(
				"During loading Lua String Script of Object of Map. Reason: "
						+ std::string(lua_tostring(lstate, -1)),
				Logger::MessageType::LuaError);
		lua_pop(lstate, 1);
		return;
	}
	reference = luaL_ref(lstate, LUA_REGISTRYINDEX);
}

ReferenceRequest::ReferenceRequest(const std::string& script) :
		script(script), reference(LUA_NOREF) {

}

} /* namespace Zeta */

