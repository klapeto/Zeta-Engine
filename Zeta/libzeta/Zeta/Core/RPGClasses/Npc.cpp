/*
 * Npc.cpp
 *
 *  Created on: 5 Ιουν 2014
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/Npc.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/LuaNumber.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <lua.hpp>
#include <tolua++.h>

namespace Zeta {

Npc::Npc(const std::string& classPath, Float x, Float y, lua_Object table) :
		Lifeform(classPath, x, y) {
	try {
		this->table.setFromStack(LuaEngine::getInstance().getState(), table);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting the Lua Table for " + name
						+ ": Table is invalid", Logger::MessageType::LuaError);
	}
	this->table.getField(LuaString("onClick"), onClickF);
	this->table.getField(LuaString("onCollision"), onCollisionF);
	//this->table.setField("Internal", this, "Zeta::Npc");
	LuaTable instances;
	if (!this->table.getField(LuaString("Instances"), instances)) {
		instances.create(1);
		this->table.setField(LuaString("Instances"), instances);
	}
	instances.setField(LuaNumber((long int) this), LuaNumber((long int) this));
	visible = false;
}

void Npc::onClick(Object* other) {
	onClickF( { &table, this, other });
}

void Npc::onCollidedWith(Object* other) {
	onCollisionF( { &table, this, other });
}

Npc::~Npc() {
	LuaTable instances;
	table.getField(LuaString("Instances"), instances);
	instances.niliseField(LuaNumber((long int) this));
}

void Npc::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Npc");
}

} /* namespace Zeta */
