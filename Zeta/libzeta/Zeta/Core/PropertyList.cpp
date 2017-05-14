/*
 * PropertyList.cpp
 *
 *  Created on: 6 Μαρ 2014
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
#include <Zeta/Core/PropertyList.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <glibmm/ustring.h>
#include <libxml++/nodes/element.h>
#include <lua.hpp>
#include <utility>

namespace Zeta {

std::string PropertyList::nullProperty = "null";

PropertyList::PropertyList() :
		properties() {

}

const std::string& PropertyList::getProperty(const std::string& name) const {
	auto itr = properties.find(name);
	if (itr != properties.end()) {
		return itr->second;
	} else {
		return nullProperty;
	}
}

void PropertyList::setProperty(const std::string& name,
		const std::string& value) {
	properties[name].assign(value);
}

lua_Object PropertyList::getLuaTable() const {
	lua_State *lstate = LuaEngine::getInstance().getState();
	lua_createtable(lstate, 0, properties.size());

	for (auto& property : properties) {
		lua_pushstring(lstate, property.second.c_str());
		lua_setfield(lstate, -2, property.first.c_str());
	}
	return 1;
}

PropertyList::~PropertyList() {

}

} /* namespace Zeta */
