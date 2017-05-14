/*
 * AbilityClass.cpp
 *
 *  Created on: 3 Απρ 2014
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
#include <Zeta/Core/LuaReferenced.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/PassiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/RegenerationAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <lua.hpp>
#include <tolua++.h>

namespace Zeta {

AbilityClass::AbilityClass() :
		Resource("null AbilityClass"), implementation(nullptr), parent(nullptr), levels(
				1), type(Type::Active) {
}

AbilityClass::AbilityClass(const std::string& path) :
		Resource(path), implementation(nullptr), parent(nullptr), levels(1), type(
				Type::Active) {

	Logger &log = Logger::getInstance();

	lua_State* lstate = LuaEngine::getInstance().getState();

	try {
		File fp(path);
		if (luaL_loadbuffer(lstate, fp.getData(), fp.getSize(), path.c_str())) {
			throw std::string(lua_tostring(lstate, -1));
		}
		if (lua_pcall(lstate, 0, 1, 0)) {
			throw std::string(lua_tostring(lstate, -1));
		}
	} catch (std::string &err) {
		lua_pop(lstate, 1);
		log.write(err, Logger::MessageType::LuaError);
		throw Exception("Lua Script had an Error", err);
	} catch (Exception& ex) {
		throw ex;
	}

	if (!lua_istable(lstate, -1)) {
		lua_pop(lstate, 1);
		throw Exception(path, "The Script did not return Ability Table");
	}

	table.setFromStack(lstate, -1);

	getData(table);

	switch (type) {
	case Type::Active:
		implementation = new ActiveAbilityClass(*this, table);
		break;
	case Type::Passive:
		implementation = new PassiveAbilityClass(*this, table);
		break;
	case Type::Regeneration:
		implementation = new RegenerationAbilityClass(*this, table);
		break;
	default:
		implementation = new ActiveAbilityClass(*this, table);
		break;
	}
}

AbilityClass::AbilityClass(lua_Object table) :
		Resource("Lua Generated Ability Class"), implementation(nullptr), parent(
				nullptr), levels(1) {
	try {
		this->table.setFromStack(LuaEngine::getInstance().getState(), table);
		getData(this->table);
		switch (type) {
		case Type::Active:
			implementation = new ActiveAbilityClass(*this, this->table);
			break;
		case Type::Passive:
			implementation = new PassiveAbilityClass(*this, this->table);
			break;
		case Type::Regeneration:
			implementation = new RegenerationAbilityClass(*this, this->table);
			break;
		default:
			implementation = new ActiveAbilityClass(*this, this->table);
			break;
		}
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting table for ability class: Reason: "
						+ ex.reason());
		nullise();
	}
}

AbilityClass::AbilityClass(AbilityClass& parent, LuaTable& table) :
		Resource("Implementation of AbilityClass"), implementation(nullptr), parent(
				nullptr), levels(1), type(Type::Active) {
	this->parent = &parent;
	this->table.setLuaReference(table.getLuaReference());
	getData(table);
}

void AbilityClass::getData(LuaTable& table) {
	Logger &log = Logger::getInstance();

	if (!table.getField(LuaString("Name"), abilityName)) {
		log.write(
				"Ability Class: " + abilityName
						+ " : has no or invalid \"Name\" field. Reseting to default",
				Logger::MessageType::Warning);
	}

	if (!table.getField(LuaString("Levels"), levels)) {
		log.write(
				"Ability Class: " + abilityName
						+ " : has no or invalid \"Levels\" field. Reseting to 1",
				Logger::MessageType::Warning);
	}

	if (!table.getField(LuaString("onApply"), onApplyF)) {
		log.write(
				"Ability Class: " + abilityName
						+ " : has no or invalid \"onApply\" field. Reseting to default",
				Logger::MessageType::Warning);
	}
	onApplyF.setName(abilityName + ": onApply");

	if (!table.getField(LuaString("onRemove"), onRemoveF)) {
		log.write(
				"Ability Class: " + abilityName
						+ " : has no or invalid \"onRemove\" function.");
	}
	onRemoveF.setName(abilityName + ": onRemove");

	if (!table.getField(LuaString("onLevelChange"), onLevelChangeF)) {
		log.write(
				"Ability Class: " + abilityName
						+ " : has no or invalid \"onLevelChange\" function.");
	}
	onLevelChangeF.setName(abilityName + ": onLevelChange");

	{
		int tmp_type = 0;
		table.getField(LuaString("Type"), tmp_type);
		if (tmp_type >= 0
				and tmp_type <= static_cast<int>(Type::Regeneration)) {
			type = static_cast<Type>(tmp_type);
		} else {
			log.write(
					"Ability Class: " + abilityName
							+ " : has invalid \'Type\' field.");
		}
	}
}

AbilityClass::~AbilityClass() {
	if (implementation != nullptr) {
		delete implementation;
	}
}

void AbilityClass::onApply(Ability *invoker, Lifeform* caster,
		Lifeform* target) const {
	onApplyF( { invoker, caster, target });
}

void AbilityClass::onRemove(Ability *invoker, Lifeform* caster,
		Lifeform* target) const {
	onRemoveF( { invoker, caster, target });
}

void AbilityClass::onLevelChange(Ability* invoker) const {
	onLevelChangeF( { invoker });
}

Ability* AbilityClass::getNewAbility(Lifeform* caster, int level) const {
	if (implementation != nullptr) {
		return implementation->getNewAbility(caster, level);
	} else {
		return nullptr;
	}
}

void AbilityClass::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::AbilityClass");
}

void AbilityClass::nullise() {
	abilityName = "Null Ability";
	onApplyF = "print(\"Null Ability onApply\")";
	onRemoveF = "print(\"Null Ability onRemove\")";
	onLevelChangeF = "print(\"Null Ability onLevelChange\")";
}

lua_Object AbilityClass::getLuaTable() const {
	table.pushToLua(LuaEngine::getInstance().getState());
	return -1;
}

} /* namespace Zeta */
