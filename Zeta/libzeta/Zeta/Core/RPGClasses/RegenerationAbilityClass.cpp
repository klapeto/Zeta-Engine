/*
 * RegenerationAbilityClass.cpp
 *
 *  Created on: 25 Σεπ 2014
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

#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Regeneration.hpp>
#include <Zeta/Core/RPGClasses/RegenerationAbilityClass.hpp>
#include <Zeta/Core/Logger.hpp>
#include <tolua++.h>

namespace Zeta {

RegenerationAbilityClass::RegenerationAbilityClass(AbilityClass& parent,
		LuaTable& table) :
		AbilityClass(parent, table), triggerEvery(5.0f) {
	if (!table.getField(LuaString("Attribute"), attribute)) {
		Logger::getInstance().write(
				"At Regeneration Class: " + abilityName
						+ ". The Lua table field: \'Attribute\' does not exist or is not string. Reseting to \'HP\'",
				Logger::MessageType::LuaError);
		attribute = "HP";
	}
	if (!table.getField(LuaString("MaxValue"), maxValue)) {
		Logger::getInstance().write(
				"At Regeneration Class: " + abilityName
						+ ". The Lua table field: \'MaxValue\' does not exist or is not string. Reseting to \'MaxHP\'",
				Logger::MessageType::LuaError);
		maxValue = "MaxHP";
	}
	if (!table.getField(LuaString("Modifier"), modifier)) {
		Logger::getInstance().write(
				"At Regeneration Class: " + abilityName
						+ ". The Lua table field: \'Modifier\' does not exist or is not string. Reseting to \'HP5\'",
				Logger::MessageType::LuaError);
		modifier = "HP5";
	}
	if (!table.getField(LuaString("TriggerEvery"), triggerEvery)) {
		Logger::getInstance().write(
				"At Regeneration Class: " + abilityName
						+ ". The Lua table field: \'TriggerEvery\' does not exist or is not string. Reseting to \'5 secs\'",
				Logger::MessageType::LuaError);
		triggerEvery = 5.0f;
	}
}

Ability* RegenerationAbilityClass::getNewAbility(Lifeform* caster,
		int level) const {
	return new Regeneration(*this, *caster, level,
			caster->getAttribute(attribute), caster->getAttribute(maxValue),
			caster->getAttribute(modifier), triggerEvery);
}

void RegenerationAbilityClass::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::RegenerationAbilityClass");
}

RegenerationAbilityClass::~RegenerationAbilityClass() {

}

} /* namespace Zeta */
