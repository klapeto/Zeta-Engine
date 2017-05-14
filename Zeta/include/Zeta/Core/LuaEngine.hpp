/*
 * LuaEngine.hpp
 *
 *  Created on: 21 Φεβ 2014
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

#ifndef LUAENGINE_HPP_
#define LUAENGINE_HPP_

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/ZMap.hpp>
#include <Zeta/Core/ZSmallSet.hpp>
#include <string>

struct lua_State;

namespace Zeta {

/**
 * The global Lua State. (Singleton)
 * TODO: Cleanup...
 */
class LuaEngine: public SingleInstanced<LuaEngine> {
public:

	/**
	 * Gets the Engine's lua_State
	 * @return the Lua_State.
	 */
	lua_State* getState() {
		return lstate;
	}

	/**
	 * Includes the Path to the path that
	 * Lua will search when calling require()
	 * @param path The Path to include
	 */
	void includePath(std::string path);

	/**
	 * Gets a Reference from the Lua Stack Index
	 * The value is preserved after the Reference retrieval.
	 * @param index The Lua stack index that contains the Value to reference
	 * @return The Reference
	 */
	int getReference(int index);

	/**
	 * Gets a Reference from a String that represents a value in Lua
	 * For instance it will reference the Member2 lua value in string "Table.Member1.Member2"
	 * @param fullName The Lua Symbol
	 * @return The Reference
	 */
	int getReference(const std::string& fullName);

	/**
	 * Increases the Reference Count of a Lua Reference
	 * @param reference The Lua Reference
	 */
	void increaseReference(int reference);

	/**
	 * Decreases the Reference Count of a Lua Reference
	 * @param reference The Lua Reference
	 */
	void decreaseReference(int reference);

	/**
	 * Pushes the Lua value represended by the string
	 * For instance it will push the Member2 lua value in string "Table.Member1.Member2"
	 * @param fullName The Lua Symbol
	 */
	void pushToStackValue(const std::string& fullName);

	/**
	 * Registers the function to be called when the Lua Symbol is called
	 * The signature of the function is int (*func) (lua_State *L)
	 * @param name The Lua Symbol to register the function to
	 * @param func the C Function to register
	 */
	void registerFunction(const std::string &name, lua_CFunction func);

	/**
	 * Executes the Script Fill
	 * @param path The filepath to the script
	 * @param force If true, the script will be executed even if it was executed before, otherwise it will be ignored
	 */
	void excecuteScriptFile(const std::string& path, bool force = false);

	/**
	 * Forces the Lua Environment to perform Garbage Collection
	 */
	void performGarbageCollection();

	~LuaEngine();
private:
	LuaEngine();

	ZSmallSet<std::string> excecutedScripts;
	ZMap<int, int> sharedReferences;

	lua_State *lstate;

	void createState();
	void destroyState();
	void executeScriptImpl(const std::string& path);
	int getReferenceImpl(const std::string& fullName);

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* LUAENGINE_HPP_ */
