/*
 * LuaTable.hpp
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

#ifndef LUATABLE_HPP_
#define LUATABLE_HPP_

#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaReferenced.hpp>
#include <Zeta/Core/LuaNil.hpp>
#include <Zeta/Core/LuaString.hpp>
#include <functional>
#include <string>

namespace Zeta {

class LuaFunctor;

/**
 * LuaTable class for easy Lua table management in C++
 * Lua tables are used as References.
 */
class LuaTable: public LuaReferenced {
public:

	/**
	 * getField from the Lua Table
	 * this Function uses an overloaded version depending on what type you pass.
	 * Eg. if you call getField("tade", <std::string>) will check if the field
	 * exists. If exists, checks if it is string. If it is string, it assigns to the argument passed
	 * and returns true, else returns false.
	 * @param key the Field to get
	 * @param value a reference to value to put the value got from FieldName
	 * @return True if successful assigned value, or false if invalid FieldName or FieldType
	 */
	template<typename ValueT>
	bool getField(const LuaValue& key, ValueT& value) const {
		if (isValid()) {
			saveStack();
			pushTable();
			const_cast<LuaValue&>(key).pushToLua(lstate);
			getTableFieldFromStack();
			bool ret = setValueFromStack(value);
			resetStack();
			return ret;
		} else {
			return false;
		}
	}

	/**
	 * Gets a Lua Reference for the specified field
	 * @param field the field to get the Reference
	 * @return an Valid Integer referencing the field or LUA_NOREF in invalid index
	 */
	int getFieldReference(const std::string& name) const;
	int getFieldReference(int index) const;

	/**
	 * Sets the Table Field with the value provided
	 * @param key the field to set the value
	 * @param value the Value to set.
	 */
	void setField(const LuaValue& key, const LuaValue& value) {
		if (isValid()) {
			saveStack();
			pushTable();
			const_cast<LuaValue&>(key).pushToLua(lstate);
			const_cast<LuaValue&>(value).pushToLua(lstate);
			setTableFieldFromStack();
			resetStack();
		}
	}

	/**
	 * Sets the field of the Lua Table to nil
	 */
	void niliseField(const LuaValue& key) {
		setField(key, LuaNil());
	}

	/**
	 * Calls the provided lambda function for every table Element
	 * The lambda function should have this signature: void f(const LuaString&, const LuaValue&, LuaValue::Type)
	 * Where the first argument is the key, the second is the Value, and the third is the Type of the value
	 * so that you can cast it.
	 * \note If the key is integer, it will passed as string when calling the lambda function
	 * @param func the function to call.
	 */
	void forEach(
			const std::function<
					void(const LuaString&, const LuaValue&, LuaValue::Type)>& func);

	/**
	 * Same with forEach() but indexes table by integer Keys
	 * Eg. table[0], table[1]
	 * @param func the function to call
	 */
	void forEachI(
			const std::function<void(const LuaValue&, LuaValue::Type)>& func);

	LuaTable(LuaTable&& other) = default;
	LuaTable(const LuaTable& other) = default;
	LuaTable& operator=(const LuaTable& other) = default;
	LuaTable& operator=(LuaTable&& other) = default;

	/**
	 * Implementation of LuaReferenced
	 */
	bool setFromStack(lua_State* lstate, int stackIndex);
	void setLuaReference(int reference);

	/**
	 * Prints all elements of the Table.
	 * It prints whatever can be printed.
	 */
	void printContents() const;

	/**
	 * Creates and references a Lua Table
	 * @param reserve Reserve at least this number of elements
	 */
	void create(int reserve = 0);

	/**
	 * Constructs a default table with no reference.
	 * Until a reference is assigned, any member call will do nothing.
	 */
	LuaTable();

	/**
	 * Constructs a Table with the table at the Lua Stack at stackIntex
	 * This can throw Zeta::Exception if the object at pointer is not a table.
	 * @param stackIndex the index at stack the Table is.
	 */
	LuaTable(int stackIndex);
	~LuaTable();
private:
	lua_State* lstate;
	mutable int stackPointer;

	/**
	 * Save the stack pointer of the Lua
	 */
	void saveStack() const;

	/**
	 * Reset the Lua stack
	 */
	void resetStack() const;

	/**
	 * Pushes this table to stack from the reference
	 */
	void pushTable() const;

	/**
	 * Sets the field of the table with key the
	 * second item on stack, and value the first item
	 */
	void setTableFieldFromStack();

	/**
	 * Pushes on the stack the field of the table
	 * that has key the first item of the stack
	 */
	void getTableFieldFromStack() const;

	/**
	 * Assigns the value the value that has the first
	 * item on the stack
	 */
	bool setValueFromStack(std::string& value) const;
	bool setValueFromStack(Float& value) const;
	bool setValueFromStack(int& value) const;
	bool setValueFromStack(bool& value) const;
	bool setValueFromStack(LuaTable& value) const;
	bool setValueFromStack(LuaFunctor& value) const;
};

} /* namespace Zeta */

#endif /* LUATABLE_HPP_ */
