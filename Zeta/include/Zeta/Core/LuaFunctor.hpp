/*
 * LuaFunctor.hpp
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

#ifndef LUAFUNCTOR_HPP_
#define LUAFUNCTOR_HPP_

#include <Zeta/Core/LuaReferenced.hpp>
#include <initializer_list>
#include <string>

namespace Zeta {

/**
 * Lua Function Object
 * Used to store Lua Code to C++ Memory to be called fast when needed.
 */
class LuaFunctor: public LuaReferenced {
public:

	/**
	 * Calls the Lua Function with the arguments provided
	 * @param argList an std::initializer_list<LuaPushable> of arguments to pass
	 */
	void operator()(std::initializer_list<LuaPushable*> argList) const;

	/**
	 * A more Optimized version of the original operator()
	 * This takes no arguments
	 */
	void operator()() const {
		operator ()( { });
	}

	/**
	 * References the Lua Functor at the Lua Stack Pointer
	 * This function can throw Zeta::Exeption if the object at the Stack is not valid.
	 * Notice: This does not remove the Object from stack.
	 * @param stackIndex the index at Lua Stack the Function is.
	 */
	bool setFromStack(lua_State* lstate, int stackIndex);

	/**
	 * Loads and stores the script provided in the String
	 * @param script the String with the script to store
	 */
	void set(const std::string& script);

	/**
	 * /see set(const std::string&)
	 */
	void operator =(const std::string& script) {
		set(script);
	}

	/**
	 * Sets the LuaReference.
	 * This is different with set()
	 * The reference should be already taken.
	 * @param reference the Reference to Lua Code
	 */
	void setLuaReference(int reference);

	/**
	 * Default Constructor
	 * No reference is stored, so calling this won't do anything.
	 */
	LuaFunctor();

	/**
	 * Constructs a LuaFunctor with the function at the provided Index
	 * It also assigns a name if provided.
	 * @param stackIndex the Stack index where the Lua Function is
	 * @param (Optional) a name for the function
	 */
	LuaFunctor(int stackIndex, const std::string& name = "");

	/**
	 * Constructs a LuaFunctor with the String as script
	 * @param script the String that has the script
	 */
	LuaFunctor(const std::string& script) :
			LuaReferenced() {
		set(script);
	}

	/**
	 * Move Constructor
	 */
	LuaFunctor(LuaFunctor&& other) = default;

	/**
	 * Copy Constructor
	 */
	LuaFunctor(const LuaFunctor& other) = default;

	/**
	 * Copy assignment operator
	 */
	LuaFunctor& operator=(const LuaFunctor& other) = default;

	/**
	 * Move assignment operator
	 */
	LuaFunctor& operator=(LuaFunctor&& other) = default;

	~LuaFunctor() {

	}
};

} /* namespace Zeta */

#endif /* LUAFUNCTOR_HPP_ */
