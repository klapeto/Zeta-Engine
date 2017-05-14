/*
 * LuaBoolean.hpp
 *
 *  Created on: 23 Αυγ 2014
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

#ifndef LUABOOLEAN_HPP_
#define LUABOOLEAN_HPP_

#include <Zeta/Core/LuaValue.hpp>

namespace Zeta {

/**
 * LuaBoolean wrapper Class
 * Used to be used as a LuaPushable on Lua Modules
 */
class LuaBoolean: public LuaValue {
public:

	void pushToLua(lua_State* lstate);
	bool setFromStack(lua_State* lstate, int stackIndex);

	/**
	 * Sets the Boolean to be pushed to Lua
	 * @param value The Boolean
	 */
	void setValue(bool value) {
		this->value = value;
	}

	/**
	 * Gets the Boolean that will be pushed to Lua
	 * @return The Boolean
	 */
	bool getValue() const {
		return value;
	}

	/**
	 * A boolean with value=false
	 */
	constexpr LuaBoolean() :
			value(false) {
	}

	/**
	 * Assigns the value
	 */
	constexpr LuaBoolean(bool value) :
			value(value) {
	}

	~LuaBoolean() {

	}
private:
	bool value;
};

} /* namespace Zeta */

#endif /* LUABOOLEAN_HPP_ */
