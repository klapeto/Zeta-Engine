/*
 * LuaTable.cpp
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
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/LuaNumber.hpp>
#include <Zeta/Core/LuaBoolean.hpp>
#include <Zeta/Core/LuaString.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <lua.hpp>
#include <tolua++.h>
#include <iostream>

namespace Zeta {

LuaTable::LuaTable() :
		LuaReferenced(), lstate(LuaEngine::getInstance().getState()), stackPointer(
				0) {
}

LuaTable::LuaTable(int stackIndex) :
		LuaReferenced(), lstate(LuaEngine::getInstance().getState()), stackPointer(
				0) {
	if (!lua_istable(lstate, stackIndex)) {
		throw Exception("Internal LuaTable Class",
				"Passed a stack pointer that is not a Lua Table!");
	}
	luaReference = LuaEngine::getInstance().getReference(stackIndex);
}

int LuaTable::getFieldReference(const std::string& name) const {
	// Check if the reference is valid
	if (luaReference != LUA_NOREF) {
		// Save the Stack
		saveStack();
		// Push the table to stack
		lua_getref(lstate, luaReference);
		// Get the named field out of the table
		lua_getfield(lstate, -1, name.c_str());
		// Get a reference of the item we got
		int out = LuaEngine::getInstance().getReference(-1);
		// reset the stack
		resetStack();
		// return the reference
		return out;
	} else {
		// if there is no table, return nonsense
		return LUA_NOREF;
	}
}

int LuaTable::getFieldReference(int index) const {
	// Check if the reference is valid
	if (luaReference != LUA_NOREF) {
		// Save the Stack
		saveStack();
		// Push the table to stack
		lua_getref(lstate, luaReference);
		// push the index
		lua_pushinteger(lstate, index);
		// get the field of the table from the index
		lua_gettable(lstate, -2);
		// Get a reference of the item we got
		int out = LuaEngine::getInstance().getReference(-1);
		// reset the stack
		resetStack();
		// return the reference
		return out;
	} else {
		// if there is no table, return nonsense
		return LUA_NOREF;
	}
}

bool LuaTable::setFromStack(lua_State* lstate, int stackIndex) {
	// Check if the item on the stackIndex is indeed a table
	if (!lua_istable(lstate, stackIndex)) {
		// If it is not a table, report it and return false
		Logger::getInstance().write(
				"Tried to assign to a LuaTable a Lua Value that is not a Lua Table",
				Logger::MessageType::Warning);
		return false;
	}
	// Call the mother function
	LuaReferenced::setFromStack(lstate, stackIndex);
	// return true, since we got the reference without problem
	return true;
}

void LuaTable::setLuaReference(int reference) {
	LuaEngine& lua = LuaEngine::getInstance();
	// get the reference
	lua_getref(lstate, reference);
	// Check if the item on the reference is indeed a table
	if (!lua_istable(lstate, -1)) {
		// If it is not a table, clear the item we pushed and throw a grenade at the caller
		lua_pop(lstate, 1);
		throw Exception("Internal LuaTable Class",
				"Passed a stack pointer that is not a Lua Table!");
	}
	// if it is indeed a table, clear it from the stack
	lua_pop(lstate, 1);
	// call the super function to actually get the reference
	LuaReferenced::setLuaReference(reference);
}

void LuaTable::create(int reserve) {
	// Preserve the stack
	saveStack();
	// push a new table to stack with the reserved items
	lua_createtable(lstate, reserve, 0);
	// get a reference from the new table
	luaReference = LuaEngine::getInstance().getReference(-1);
	// reset the stack
	resetStack();
}

LuaTable::~LuaTable() {
	// Nope! Nothing is going on there.
}

void LuaTable::printContents() const {
	// Check if the reference is valid
	if (luaReference != LUA_NOREF) {
		// Print a placeholder
		std::cout << "Table: " << luaReference << std::endl;
		// Preserve the stack
		saveStack();
		// push the table to stack
		lua_getref(lstate, luaReference);
		// Push a nil to make lua_next() iterate
		lua_pushnil(lstate);
		// Iterate through all items with this loop
		while (lua_next(lstate, -2)) {
			// 2nd stage stack preservation
			int stack = lua_gettop(lstate) - 1;
			// duplicate the key and the actual value
			lua_pushvalue(lstate, -2);
			lua_pushvalue(lstate, -2);
			// Print the data
			std::cout << "  [" << lua_tostring(lstate, -2) << "] = "
					<< lua_tostring(lstate, -1) << std::endl;
			// reset the stack
			lua_settop(lstate, stack);
		}
		// Final stack reset
		resetStack();
	}
}

void LuaTable::forEach(
		const std::function<
				void(const LuaString&, const LuaValue&, LuaValue::Type)>& func) {
	// Check if the reference is valid
	if (luaReference != LUA_NOREF) {
		// Preserve the stack
		saveStack();
		// Push the table on the stack
		lua_getref(lstate, luaReference);
		// Push a nil to make lua_next() iterate
		lua_pushnil(lstate);
		// Iterate through all items with this loop
		while (lua_next(lstate, -2)) {
			// 2nd stage stack preservation
			int stack = lua_gettop(lstate) - 1;
			// duplicate the key on stack to prevent the original to be cast to string
			// if it is a number
			lua_pushvalue(lstate, -2);
			// Check what type is the value and call the lambda accordingly
			switch (lua_type(lstate, -2)) {
			case LUA_TNUMBER:
				func(LuaString(lua_tostring(lstate, -1)),
						LuaNumber(lua_tonumber(lstate, -2)),
						LuaValue::Type::Number);
				break;
			case LUA_TSTRING:
				func(LuaString(lua_tostring(lstate, -1)),
						LuaString(lua_tostring(lstate, -2)),
						LuaValue::Type::String);
				break;
			case LUA_TBOOLEAN:
				func(LuaString(lua_tostring(lstate, -1)),
						LuaBoolean(lua_toboolean(lstate, -2)),
						LuaValue::Type::Boolean);
				break;
			case LUA_TTABLE:
				func(LuaString(lua_tostring(lstate, -1)), LuaTable(-2),
						LuaValue::Type::Table);
				break;
			case LUA_TFUNCTION:
				func(LuaString(lua_tostring(lstate, -1)), LuaFunctor(-2),
						LuaValue::Type::Function);
				break;
			default:
				break;
			}
			// 2nd stage Reset (removes the duplicate key and value)
			lua_settop(lstate, stack);
		}
		// Final reset
		resetStack();
	}
}

void LuaTable::forEachI(
		const std::function<void(const LuaValue&, LuaValue::Type)>& func) {
	// Check if the reference is valid
	if (luaReference != LUA_NOREF) {
		// Save the stack pointer
		saveStack();
		// initialize the i
		int i = 1;
		// push the table on the stack
		lua_getref(lstate, luaReference);
		// 2nd stage Stack preservation
		int stack = lua_gettop(lstate);
		// push to stack 0
		lua_pushinteger(lstate, 0);
		// get the first item of the table (table[0])
		lua_rawget(lstate, -2);
		// while it actually exists, iterate
		// TODO: Will it work if the keys don't start from 0? probably no, but it is out of the bounds of the function
		while (!lua_isnil(lstate, -1)) {
			// Check the type of the value and call the lambda accordingly
			switch (lua_type(lstate, -1)) {
			case LUA_TNUMBER:
				func(LuaNumber(lua_tonumber(lstate, -1)),
						LuaValue::Type::Number);
				break;
			case LUA_TSTRING:
				func(LuaString(lua_tostring(lstate, -1)),
						LuaValue::Type::String);
				break;
			case LUA_TBOOLEAN:
				func(LuaBoolean(lua_toboolean(lstate, -1)),
						LuaValue::Type::Boolean);
				break;
			case LUA_TTABLE:
				func(LuaTable(-1), LuaValue::Type::Table);
				break;
			case LUA_TFUNCTION:
				func(LuaFunctor(-1), LuaValue::Type::Function);
				break;
			default:
				break;
			}
			// 2dn stage reset
			lua_settop(lstate, stack);
			// push the next i
			lua_pushinteger(lstate, i++);
			// get the next item (table[i++])
			lua_rawget(lstate, -2);
		}
		// Final stack reset
		resetStack();
	}
}

bool LuaTable::setValueFromStack(std::string& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_isstring(lstate, -1)) {
		value.assign(lua_tostring(lstate, -1));
		return true;
	} else {
		return false;
	}
}

bool LuaTable::setValueFromStack(Float& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_isnumber(lstate, -1)) {
		value = lua_tonumber(lstate, -1);
		return true;
	} else {
		return false;
	}
}

bool LuaTable::setValueFromStack(int& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_isnumber(lstate, -1)) {
		value = lua_tointeger(lstate, -1);
		return true;
	} else {
		return false;
	}
}

bool LuaTable::setValueFromStack(bool& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_isboolean(lstate, -1)) {
		value = lua_toboolean(lstate, -1);
		return true;
	} else {
		return false;
	}
}

bool LuaTable::setValueFromStack(LuaTable& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_istable(lstate, -1)) {
		value.setFromStack(lstate, -1);
		return true;
	} else {
		return false;
	}
}

bool LuaTable::setValueFromStack(LuaFunctor& value) const {
	// If the type of the item on the top of the stack is correct,
	// then assign and return true
	if (lua_isfunction(lstate, -1)) {
		value.setFromStack(lstate, -1);
		return true;
	} else {
		return false;
	}
}

void LuaTable::saveStack() const {
	// save the current Lua stack pointer
	stackPointer = lua_gettop(lstate);
}

void LuaTable::resetStack() const {
	// set the stackPointer of the Lua Stack to the saved stackPointer
	lua_settop(lstate, stackPointer);
}

void LuaTable::pushTable() const {
	// Push the table that the reference has
	lua_getref(lstate, luaReference);
}

void LuaTable::setTableFieldFromStack() {
	// Set the field with key at -2 of the table at -3 to value at -1
	lua_settable(lstate, -3);
}

void LuaTable::getTableFieldFromStack() const {
	// Get the field with key at -1 of the table at -2
	lua_gettable(lstate, -2);
}

} /* namespace Zeta */

