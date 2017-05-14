/*
 * LuaFunctor.cpp
 *
 *  Created on: 20 Αυγ 2014
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
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <iostream>
#include <lua.hpp>

namespace Zeta {

LuaFunctor::LuaFunctor() :
		LuaReferenced() {

}

LuaFunctor::LuaFunctor(int stackIndex, const std::string& name) :
		LuaReferenced() {
	LuaEngine& lua = LuaEngine::getInstance();
	// Check if the item on stack is a Lua Function
	if (!lua_isfunction(lua.getState(), stackIndex)) {
		// If it is not, then let the caller know
		throw Exception("Internal LuaFunctor Class",
				"Passed a stack pointer that is not a Lua Function!");
	}
	// If it is a Function then get a reference to it
	luaReference = lua.getReference(stackIndex);
	// Set the name
	this->name = name;
}

void LuaFunctor::setLuaReference(int reference) {
	lua_State* lstate = LuaEngine::getInstance().getState();
	// Get the referenced item to the stack
	lua_getref(lstate, reference);
	// Check if it is a function
	if (!lua_isfunction(lstate, -1)) {
		// if it is not, remove it from stack
		lua_pop(lstate, 1);
		// Let the caller know
		throw Exception("Internal LuaFunctor Class",
				"Passed a Lua Reference that is not a Lua Function!");
	}
	// if it is function, remove it from stack
	lua_pop(lstate, 1);
	// Set the reference to it
	LuaReferenced::setLuaReference(reference);
}

void LuaFunctor::set(const std::string& script) {
	lua_State* lstate = LuaEngine::getInstance().getState();
	// Load the script to Lua
	if (luaL_loadstring(lstate, script.c_str())) {
		// If there was an error on loading, Report it on Log File
		Logger::getInstance().write(
				"During loading Lua String: " + script + " Reason: "
						+ std::string(lua_tostring(lstate, -1)),
				Logger::MessageType::LuaError);
		// Remove the script from stack
		lua_pop(lstate, 1);
		return;
	}
	// Set the name to the script data
	name = script;
	// Get a reference to the code on stack
	luaReference = LuaEngine::getInstance().getReference(-1);
}

void LuaFunctor::operator ()(
		std::initializer_list<LuaPushable*> argList) const {
	// Check if we have a valid reference
	if (luaReference != LUA_NOREF) {
		lua_State* lstate = LuaEngine::getInstance().getState();
		// Push the function o stack
		lua_getref(lstate, luaReference);
		// Initialize the argument count to 0
		int argC = 0;
		// For all the arguments on the argList
		for (auto arg : argList) {
			// Check if it not a Null
			if (arg != nullptr) {
				// If it is not a null, then push it to the stack
				arg->pushToLua(lstate);
				// Increase the argument count
				++argC;
			}
		}
		// Once we pushed all the arguments on the Lua stack,
		// call the referenced function with all the arguments
		if (lua_pcall(lstate, argC, 0, 0)) {
			// If there was an error while calling the function, then
			// report it!
			Logger::getInstance().write(
					"During calling Lua Function: " + name + " Reason:"
							+ std::string(lua_tostring(lstate, -1)));
			// Remove the error message from stack
			lua_pop(lstate, 1);
		}
	}
}

bool LuaFunctor::setFromStack(lua_State* lstate, int stackIndex) {
	LuaEngine& lua = LuaEngine::getInstance();
	// Check if the item on stack is a function
	if (!lua_isfunction(lua.getState(), stackIndex)) {
		// if it is not, then report ti
		Logger::getInstance().write(
				"Tried to assign to a LuaFunctor a Lua Value that is not a Lua Function",
				Logger::MessageType::Warning);
		// return false, to let know we did not assign it
		return false;
	}
	// If it is a function, set the reference
	LuaReferenced::setFromStack(lstate, stackIndex);
	// return true to let know we made it!
	return true;
}

} /* namespace Zeta */
