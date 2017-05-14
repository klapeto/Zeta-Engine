/*
 * LuaListener.cpp
 *
 *  Created on: 21 Δεκ 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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
#include <Zeta/Core/RPGClasses/LuaListener.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <tolua++.h>
#include <string>

namespace Zeta {

void LuaListener::acceptEvent(const WorldEvent& event) {
	switch (type) {
	case WorldEvent::Type::Death:
		callback( { event.data.deathEvent.victim, this });
		break;
	case WorldEvent::Type::Interact:
		callback(
				{ event.data.interactEvent.user1,
						event.data.interactEvent.user2, this });
		break;
	case WorldEvent::Type::AbilityUse:
		callback(
				{ event.data.abilityUseEvent.ability,
						event.data.abilityUseEvent.user, this });
		break;
	case WorldEvent::Type::WorldExit:
		callback( { event.data.worldExitEvent.invoker, this });
		break;
	case WorldEvent::Type::Collision:
		callback(
				{ event.data.collisionEvent.invoker,
						event.data.collisionEvent.other, this });
		break;
	case WorldEvent::Type::Custom:
		callback( { &event.customData.table, this });
		break;
	default:
		callback( { });
		break;
	}
}

LuaListener::LuaListener(lua_Object func, WorldEvent::Type type) :
		type(type), active(true) {
	try {
		callback.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting Lua function for LuaListener: Reason: "
						+ ex.reason(), Logger::MessageType::LuaError);
		return;
	}
	WorldManager::getInstance().addListener(this, type);
}

LuaListener::LuaListener(const std::string& channel, lua_Object func) :
		type(WorldEvent::Type::Custom), active(true) {
	try {
		callback.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting Lua function for LuaListener: Reason: "
						+ ex.reason(), Logger::MessageType::LuaError);
		return;
	}
	WorldManager::getInstance().addListener(this, channel);
}

void LuaListener::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::LuaListener");
}

void LuaListener::deactivate() {
	if (active) {
		active = false;
		if (type == WorldEvent::Type::Custom) {
			WorldManager::getInstance().removeListener(this, customChannel);
		} else {
			WorldManager::getInstance().removeListener(this, type);
		}
	}
}

void LuaListener::activate() {
	if (!active) {
		active = true;
		if (type == WorldEvent::Type::Custom) {
			WorldManager::getInstance().addListener(this, customChannel);
		} else {
			WorldManager::getInstance().addListener(this, type);
		}
	}
}

LuaListener::~LuaListener() {
	deactivate();
}

} /* namespace Zeta */
