/*
 * LuaEngine.cpp
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

#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/toLua_Binders/Binder.hpp>
#include <lua.hpp>
#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <list>
#include <utility>

namespace Zeta {

LuaEngine::LuaEngine() :
		lstate(nullptr) {

	// Create A Lua State
	createState();
}

void LuaEngine::excecuteScriptFile(const std::string& path, bool force) {
	if (!force) {
		// If not forced to execute, then search if we already executed it
		auto itr = excecutedScripts.find(path);
		if (itr == excecutedScripts.end()) {
			// If we did not executed it
			executeScriptImpl(path);
		}
	} else {
		// If we have to execute it anyway (force == true)
		executeScriptImpl(path);
	}
}

void LuaEngine::registerFunction(const std::string& name, lua_CFunction func) {
	// Register the Function to the Lua Symbol
	lua_register(lstate, name.data(), func);
}

LuaEngine::~LuaEngine() {
	// Close the Lua Machine
	lua_close(lstate);
}

int LuaEngine::getReference(const std::string& fullName) {
	// Get a Reference to the Named Value
	int ref = getReferenceImpl(fullName);

	// Register the reference to the References Table to know
	// what references we gave
	sharedReferences[ref] = 1;

	// Return the Reference
	return ref;
}
void LuaEngine::pushToStackValue(const std::string& fullName) {
	// Get a Reference to the Named Value
	int ref = getReferenceImpl(fullName);

	// Bring the Referenced value to the Top of the stack
	lua_getref(lstate, ref);

	// Release the reference, since we don't need it anymore
	lua_unref(lstate, ref);
}

int LuaEngine::getReference(int index) {
	// Check if there is a value there
	if (!lua_isnoneornil(lstate, index)) {
		// Duplicate the Value on the Stack to preserve it
		lua_pushvalue(lstate, index);

		// Get a reference from the value on top (duplicated value)
		int ret = luaL_ref(lstate, LUA_REGISTRYINDEX);

		// Register the Reference on the References Table
		sharedReferences[ret] = 1;

		// Return the Reference
		return ret;
	} else {
		return LUA_NOREF;
	}
}

void LuaEngine::increaseReference(int reference) {

	// Check if the Reference is valid
	if (reference != LUA_NOREF && reference != LUA_REFNIL) {

		// Search the Reference on the References Table
		auto itr = sharedReferences.find(reference);
		if (itr != sharedReferences.end()) {

			// If we found it, then increase The reference count
			++sharedReferences[reference];
		} else {

			// If we did not find it, then set it to 1
			sharedReferences[reference] = 1;
		}
	}
}

void LuaEngine::decreaseReference(int reference) {

	// Check if the Reference is valid
	if (reference != LUA_NOREF && reference != LUA_REFNIL) {

		// Search the Reference on the References Table
		auto itr = sharedReferences.find(reference);
		if (itr != sharedReferences.end()) {

			// If we found it, then decrease the reference Count and check if it is 0
			if (--(itr->second) <= 0) {
				// If the Reference Count reached 0 or below, then we need to release it

				// Erase the record on the References Table
				sharedReferences.erase(itr);

				// Release the Reference
				lua_unref(lstate, reference);
			}
		} else {
			// If we did not find it, then something evil happened
			// and we should make the corpse disappear, before the cops find it
			lua_unref(lstate, reference);
		}
	}
}

void LuaEngine::includePath(std::string path) {

	// Check if the last symbol of the path is '/'
	if ((*path.end()) == '/') {
		// If it is, then we need to erase is
		path.erase(path.end());
	}

	// Create a lua script to include the path to require search paths
	std::string buildInScript = "package.path = package.path .. \";" + path
			+ "/?.lua;" + path + "/?/init.lua\"\n";

	// Load the Script and check of errors
	if (luaL_loadbuffer(lstate, buildInScript.data(), buildInScript.size(),
			"buildin")) {

		// If errors occurred, Report them!
		Logger::getInstance().write(
				"During compiling the predefined script. Reason: "
						+ std::string(lua_tostring(lstate, -1)),
				Logger::MessageType::LuaError);

		// Remove the Lua Error from stack
		lua_pop(lstate, 1);
	}

	// Call the script and check for errors
	if (lua_pcall(lstate, 0, 0, 0)) {

		// If errors occurred, Report them!
		Logger::getInstance().write(
				"During calling the predefined script. Reason: "
						+ std::string(lua_tostring(lstate, -1)),
				Logger::MessageType::LuaError);

		// Remove the Lua Error from stack
		lua_pop(lstate, 1);
	}
}

void LuaEngine::performGarbageCollection() {
	// Perform GC Cycle on Lua Environment
	lua_gc(lstate, LUA_GCCOLLECT, 0);
}

void LuaEngine::createState() {

	// Check if there is already a State alive
	if (lstate != nullptr) {
		// If a state is already alive, destroy it!
		destroyState();
	}

	// Create a new state
	lstate = luaL_newstate();

	// Load the Lua Libraries
	luaL_openlibs(lstate);

	// Register the Zeta API to Lua Environment
	tolua_Zeta_open(lstate);
}

void LuaEngine::destroyState() {

	// Close the State
	lua_close(lstate);

	// Set the state pointer to NULL
	lstate = nullptr;
}

void LuaEngine::executeScriptImpl(const std::string& path) {
	try {
		// Try load the file
		File src(path);
		std::string err;
		// Load the File code to Lua Machine and check for errors
		switch (luaL_loadbuffer(lstate, src.getData(), src.getSize(),
				path.c_str())) {
		case LUA_ERRSYNTAX:
			// Get the Error Message from Lua Stack
			err = lua_tostring(lstate, -1);
			// Clear the Lua Error Message from Lua Stack
			lua_pop(lstate, 1);
			throw Exception("Lua Syntax Error during Loading: " + path, err);
			break;
		case LUA_ERRMEM:
			// Get the Error Message from Lua Stack
			err = lua_tostring(lstate, -1);
			// Clear the Lua Error Message from Lua Stack
			lua_pop(lstate, 1);
			// Throw an Exception
			throw Exception("Lua Memory Error during Loading: " + path, err);
			break;
		default:
			break;
		}
		// If it loaded fine, then execute the code and check for errors
		switch (lua_pcall(lstate, 0, 0, 0)) {
		case LUA_ERRRUN:
			// Get the Error Message from Lua Stack
			err = lua_tostring(lstate, -1);
			// Clear the Lua Error Message from Lua Stack
			lua_pop(lstate, 1);
			// Throw an Exception
			throw Exception("Runtime Error during Lua Script Execution: ", err);
			break;
		case LUA_ERRMEM:
			// Get the Error Message from Lua Stack
			err = lua_tostring(lstate, -1);
			// Clear the Lua Error Message from Lua Stack
			lua_pop(lstate, 1);
			// Throw an Exception
			throw Exception(
					"Memory Allocation Error during Lua Script Execution: "
							+ path, err);
			break;
		case LUA_ERRSYNTAX:
			// Get the Error Message from Lua Stack
			err = lua_tostring(lstate, -1);
			// Clear the Lua Error Message from Lua Stack
			lua_pop(lstate, 1);
			// Throw an Exception
			throw Exception("Lua Syntax Error during Execution: " + path, err);
			break;
		}
	} catch (Exception& ex) {
		// If anything happened, report it
		Logger::getInstance().write(
				std::string(ex.what()) + ". Reason: "
						+ std::string(ex.reason()),
				Logger::MessageType::LuaError);
	}
	// Set that we executed that script
	excecutedScripts.insert(path);
}

int LuaEngine::getReferenceImpl(const std::string& fullName) {
	std::list<std::string> tokens;
	// Break the String into tokens separated by '.'
	StringOperations::getTokens(fullName, '.', tokens);

	// Get the First token
	std::string table = *tokens.begin();

	// Remove the taken token from List to prevent requesting it again
	tokens.erase(tokens.begin());

	// Save the Lua Stack Pointer
	int stackTop = lua_gettop(lstate);

	// Initialize the return value
	int ret = LUA_NOREF;

	// Get the first Token name from Global
	lua_getglobal(lstate, table.c_str());

	if (!lua_isnoneornil(lstate, -1)) {
		// For the rest tokens
		for (auto &token : tokens) {

			// If the item at the top of the Stack is a Lua Table
			if (lua_istable(lstate, -1)) {
				// Put that table on the top of the stack
				lua_getfield(lstate, -1, token.c_str());
			} else {
				// If it is not a Lua Table, then we found the Last item
				break;
			}
		}

		// Check if the value is valid
		if (!lua_isnoneornil(lstate, -1)) {
			// Get a reference to to item on the top of the stack that is
			// the last item retrieved from the previous for()
			ret = luaL_ref(lstate, LUA_REGISTRYINDEX);
		}
	}

	// Reset the Lua Stack
	lua_settop(lstate, stackTop);

	// Return the Lua reference
	return ret;
}

} /* namespace Zeta */

