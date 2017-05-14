/*
 * LuaReferenced.cpp
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

#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/LuaReferenced.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <lua.hpp>

namespace Zeta {

LuaReferenced::LuaReferenced() :
		luaReference(LUA_NOREF) {

}

LuaReferenced::LuaReferenced(const std::string& luaName) :
		name(luaName), luaReference(
				LuaEngine::getInstance().getReference(luaName)) {
}

LuaReferenced::LuaReferenced(int stackIndex) :
		luaReference(LuaEngine::getInstance().getReference(stackIndex)) {
}

LuaReferenced::LuaReferenced(LuaReferenced&& other) :
		name(std::move(other.name)), luaReference(other.luaReference) {
	// When moving the object, invalidate the other reference
	// to prevent releasing it
	other.luaReference = LUA_NOREF;
}

LuaReferenced::LuaReferenced(const LuaReferenced& other) {
	// When copying, copy everything except the luaReference
	name = other.name;
	luaReference = other.luaReference;
	// Increase the Reference Count for this reference
	LuaEngine::getInstance().increaseReference(luaReference);
}

LuaReferenced& LuaReferenced::operator =(const LuaReferenced& other) {
	// When copying, copy everything except the luaReference
	name = other.name;
	luaReference = other.luaReference;
	// Increase the Reference Count for this reference
	LuaEngine::getInstance().increaseReference(luaReference);
	return *this;
}

bool LuaReferenced::isValid() const {
	// Check if the lua Reference has valid number
	return luaReference != LUA_NOREF;
}
LuaReferenced::~LuaReferenced() {
	// When this object is destroyed, let the LuaEngine
	// that we don't need the reference anymore by
	// decreasing the reference count
	LuaEngine::getInstance().decreaseReference(luaReference);
}

LuaReferenced& LuaReferenced::operator =(LuaReferenced&& other) {
	// Move everything
	name = std::move(other.name);
	luaReference = other.luaReference;
	// Invalidate the others Lua reference to prevent releasing
	other.luaReference = LUA_NOREF;
	return *this;
}

void LuaReferenced::pushToLua(lua_State* lstate) {
	// Push the reference to stack
	lua_getref(lstate, luaReference);
}

bool LuaReferenced::setFromStack(lua_State* lstate, int stackIndex) {
	// Check if the member has already a reference
	if (luaReference != LUA_NOREF) {
		// If it does, release it
		LuaEngine::getInstance().decreaseReference(luaReference);
	}
	// get the reference
	luaReference = LuaEngine::getInstance().getReference(stackIndex);
	// Check if we got the reference (We might got a stackIndex pointing to nothing)
	if (luaReference != LUA_NOREF) {
		return true;
	} else {
		return false;
	}
}

void LuaReferenced::setLuaReference(int reference) {
	// Check if the member has already a reference
	if (luaReference != LUA_NOREF) {
		// If it does, release it
		LuaEngine::getInstance().decreaseReference(luaReference);
	}
	// Increase this reference count
	LuaEngine::getInstance().increaseReference(reference);
	// copy the reference
	luaReference = reference;
}

} /* namespace Zeta */

