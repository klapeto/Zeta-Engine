/*
 * LuaString.hpp
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

#ifndef LUASTRING_HPP_
#define LUASTRING_HPP_

#include <Zeta/Core/LuaValue.hpp>
#include <string>

namespace Zeta {

/**
 * LuaString Wrapper class to be used as LuaPushable
 */
class LuaString: public LuaValue {
public:

	void pushToLua(lua_State* lstate);
	bool setFromStack(lua_State* lstate, int stackIndex);

	/**
	 * Sets the String to be pushed to Lua
	 * @param value The string
	 */
	void setValue(const std::string& value) {
		str = value;
	}

	/**
	 * Gets the string that will be pushed to Lua
	 * @return The string
	 */
	const std::string& getValue() const {
		return str;
	}

	/**
	 * Default Constructor
	 * It's an empty string
	 */
	LuaString() {
	}

	/**
	 * Assigns the passed string
	 */
	LuaString(const std::string& str) :
			str(str) {
	}

	~LuaString() {

	}
private:
	std::string str;
};

} /* namespace Zeta */

#endif /* LUASTRING_HPP_ */
