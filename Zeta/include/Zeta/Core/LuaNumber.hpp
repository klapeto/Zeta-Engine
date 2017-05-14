/*
 * LuaNumber.hpp
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

#ifndef LUANUMBER_HPP_
#define LUANUMBER_HPP_

#include <Zeta/Core/LuaValue.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * LuaNumber Wrapper class to be used by LuaFunctor and LuaTable
 */
class LuaNumber: public LuaValue {
public:

	void pushToLua(lua_State* lstate);
	bool setFromStack(lua_State* lstate, int stackIndex);

	/**
	 * Sets the Number to be pushed to Lua
	 * @param value The Number
	 */
	void setValue(Float value) {
		this->value = value;
	}

	/**
	 * Gets the Number that will be pushed to Lua
	 * @return The Number
	 */
	Float getValue() const {
		return value;
	}

	/**
	 * An Number with value 0.0
	 */
	constexpr LuaNumber() :
			value(0.0f) {
	}

	/**
	 * Assigns the value to pushed
	 */
	constexpr LuaNumber(Float value) :
			value(value) {

	}

	~LuaNumber() {

	}
private:
	Float value;
};

} /* namespace Zeta */

#endif /* LUANUMBER_HPP_ */
