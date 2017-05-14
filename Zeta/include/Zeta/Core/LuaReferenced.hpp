/*
 * LuaReferenced.hpp
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

#ifndef LUAREFERENCED_HPP_
#define LUAREFERENCED_HPP_

#include <string>
#include <Zeta/Core/LuaValue.hpp>

struct lua_State;

namespace Zeta {

/**
 * LuaReferenced Is derived by classes representing Lua Code in C++
 * This means that Objects of the derived classes have a Reference to Lua Environment
 * A LuaReferenced object can have a Name to make debugging easier.
 */
class LuaReferenced: public LuaValue {
public:

	/**
	 * Gets the references Name
	 * @return the name
	 */
	const std::string& getName() const {
		return name;
	}

	/**
	 * Sets the references Name
	 * @param name the Name
	 */
	void setName(const std::string& name) {
		this->name = name;
	}

	/**
	 * Gets the Reference Int in Lua
	 * @return the integer that represents something in Lua
	 */
	int getLuaReference() const {
		return luaReference;
	}

	/**
	 * Sets the reference according to the stack Pointer provided
	 * @param lstate The lua state
	 * @param stackIndex the StackIndex the object is in Lua
	 */
	virtual bool setFromStack(lua_State* lstate, int stackIndex);

	/**
	 * Sets the Lua Reference directly
	 * @param reference the Reference int to set
	 */
	virtual void setLuaReference(int reference);

	/**
	 * Checks if the Reference is actually pointing to something
	 * @return True if the reference can be used.
	 */
	bool isValid() const;

	/**
	 * Pushes the referenced object to Lua.
	 * @param lstate the lua_State to push it.
	 */
	void pushToLua(lua_State* lstate);

	LuaReferenced();
	LuaReferenced(const std::string& luaName);
	LuaReferenced(int stackIndex);
	LuaReferenced(LuaReferenced&& other);
	LuaReferenced(const LuaReferenced& other);
	LuaReferenced& operator=(const LuaReferenced& other);
	LuaReferenced& operator=(LuaReferenced&& other);
	virtual ~LuaReferenced();
protected:
	std::string name;
	int luaReference;
};

} /* namespace Zeta */

#endif /* LUAREFERENCED_HPP_ */
