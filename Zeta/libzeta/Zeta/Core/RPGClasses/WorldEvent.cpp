/*
 * WorldEvent.cpp
 *
 *  Created on: 17 Μαϊ 2014
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

#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <tolua++.h>

namespace Zeta {

void WorldEvent::broadcast() {
	WorldManager::getInstance().raiseEvent(*this);
}

void WorldEvent::setAsDamageEvent(Lifeform* victim, Lifeform* dealer,
		unsigned amount) {
	type = WorldEvent::Type::Damage;
	data.damageEvent.amount = amount;
	data.damageEvent.victim = victim;
	data.damageEvent.dealer = dealer;
}

void WorldEvent::setAsDeathEvent(Lifeform* victim) {
	type = WorldEvent::Type::Death;
	data.deathEvent.victim = victim;
}

void WorldEvent::setAsInteractEvent(Lifeform* user1, Lifeform* user2) {
	type = WorldEvent::Type::Interact;
	data.interactEvent.user1 = user1;
	data.interactEvent.user2 = user2;
}

void WorldEvent::setAsAbilityUseEvent(Lifeform* user, Ability* ability) {
	type = WorldEvent::Type::AbilityUse;
	data.abilityUseEvent.user = user;
	data.abilityUseEvent.ability = ability;
}

void WorldEvent::setAsWorldExitEvent(Lifeform* invoker) {
	type = WorldEvent::Type::WorldExit;
	data.worldExitEvent.invoker = invoker;
}

void WorldEvent::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::WorldEvent");
}

void WorldEvent::setAsCollisionEvent(Lifeform* invoker, Object* other) {
	type = WorldEvent::Type::Collision;
	data.collisionEvent.invoker = invoker;
	data.collisionEvent.other = other;
}

void WorldEvent::setAsCustomEvent(const std::string& channel,
		lua_Object table) {
	type = WorldEvent::Type::Custom;
	customData.channel = channel;
	try {
		customData.table.setFromStack(LuaEngine::getInstance().getState(), table);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During setting a WorldEvent to Custom Event (setAsCustomEvent()), was passed a Something that was not a Lua Table! The event will reset to /'Nothing/'",
				Logger::MessageType::Error);
		type = WorldEvent::Type::Nothing;
	}

}

} /* namespace Zeta */

