/*
 * ActiveAbilityClass.cpp
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

#include <Zeta/Core/RPGClasses/ActiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Effect.hpp>
#include <lua.hpp>
#include <tolua++.h>

namespace Zeta {

ActiveAbilityClass::ActiveAbilityClass(AbilityClass& parent, LuaTable& table) :
		AbilityClass(parent, table), range(80.0f), manaCost(0.0f), castTime(
				0.0f), cooldown(1.0f) {
	table.getField(LuaString("CoolDown"), cooldown);
	table.getField(LuaString("ManaCost"), manaCost);
	table.getField(LuaString("CastAnimation"), castAnimation);
	table.getField(LuaString("CastSound"), castSound);
	table.getField(LuaString("ReleaseAnimation"), releaseAnimation);
	table.getField(LuaString("ReleaseSound"), releaseSound);
	table.getField(LuaString("Range"), range);
	table.getField(LuaString("CastTime"), castTime);

	{
		LuaTable effects;
		if (table.getField(LuaString("Effects"), effects)) {
			effects.forEach(
					[this](const LuaString& key, const LuaValue& value, LuaValue::Type type) {
						if (type==LuaValue::Type::Table) {
							this->effects[key.getValue()] = std::move(EffectClass(static_cast<const LuaTable&>(value)));
						}
					});
		}
	}
	{
		LuaTable projectiles;
		if (table.getField(LuaString("Projectiles"), projectiles)) {
			projectiles.forEach(
					[this](const LuaString& key, const LuaValue& value, LuaValue::Type type) {
						if (type==LuaValue::Type::Table) {
							this->projectiles[key.getValue()].load(static_cast<const LuaTable&>(value));
						}
					});
		}
	}
}

const ProjectileClass* ActiveAbilityClass::getProjectileClass(
		const std::string& name) const {
	auto itr = projectiles.find(name);
	if (itr != projectiles.end()) {
		return &itr->second;
	} else {
		return nullptr;
	}
	return nullptr;
}

void ActiveAbilityClass::applyEffect(const std::string& name, Lifeform* target,
		int level, ActiveAbility* ability) const {
	if (target != nullptr) {
		auto itr = effects.find(name);
		if (itr != effects.end()) {
			Effect* eff = itr->second.getNewEffect(target, level);
			eff->setSource(ability);
			target->addEffect(eff);
		} else {
			Logger::getInstance().write(
					"At Ability " + name
							+ ". Called \'applyEffect\' with invalid name",
					Logger::MessageType::LuaError);
		}
	} else {
		Logger::getInstance().write(
				"At Ability " + name
						+ ". Called \'applyEffect\' with NULL Target",
				Logger::MessageType::LuaError);
	}
}

void ActiveAbilityClass::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::ActiveAbilityClass");
}

Ability* ActiveAbilityClass::getNewAbility(Lifeform* caster, int level) const {
	return new ActiveAbility(*this, caster, level);
}

ActiveAbilityClass::~ActiveAbilityClass() {

}

} /* namespace Zeta */
