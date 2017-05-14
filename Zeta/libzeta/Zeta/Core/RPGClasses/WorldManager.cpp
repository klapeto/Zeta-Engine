/*
 * WorldManager.cpp
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/LuaReferenced.hpp>
#include <Zeta/Core/LuaString.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <lua.hpp>
#include <tolua++.h>
#include <algorithm>
#include <initializer_list>

namespace Zeta {

WorldManager::WorldManager() :
		player(nullptr), visible(false), running(true) {
	std::string names[] = { "ChangeMap Callback", "LoadBegin Callback",
			"LoadEnd Callback", "QuestAdd Callback", "QuestComplete Callback",
			"StateComplete Callback", "ObjectiveComplete Callback",
			"ObjectiveStep Callback" };
	int i = 0;
	for (auto& name : names) {
		callbacks[i].setName(name);
		++i;
	}
	createPlayer();
	mapLoader.getMap().setView(camera);
}

void WorldManager::changeMapWithCallback(const std::string& path) {
	if (callbacks[static_cast<int>(Callback::ChangeMap)].isValid()) {
		LuaString temp(path);
		callbacks[static_cast<int>(Callback::ChangeMap)]( { &temp });
	} else {
		changeMap(path);
	}
}

WorldManager::~WorldManager() {

}

void WorldManager::changeMap(const std::string& path) {
	visible = false;
	running = false;
	mapLoader.setNextMap(path);
	mapLoader.startLoad();
}

void WorldManager::draw(Float x, Float y, Float rotation, Float scale) const {
	if (visible) {
		mapLoader.getMap().draw(camera);
	}
}

void WorldManager::update(Float elapsedTime) {
	if (visible) {
		if (running) {
			for (auto pair : worldListenersToBeErased) {
				eventChannel[static_cast<int>(pair.type)].erase(pair.listener);
			}
			for (auto pair : customListenersToBeErased) {
				customChannel[pair.channel].erase(pair.listener);
			}
			for (auto listener : frameListenersToBeRemoved) {
				frameListeners.erase(listener);
			}
			for (auto listener : frameListeners) {
				listener->update(elapsedTime);
			}
			callbacks[static_cast<int>(Callback::FrameBegin)]( { });
			mapLoader.getMap().update(elapsedTime);
			callbacks[static_cast<int>(Callback::FrameEnd)]( { });
		}
	}
}

void WorldManager::addListener(WorldListener* listener,
		WorldEvent::Type eventType) {
	if (listener != nullptr) {
		if (static_cast<int>(eventType) < 10) {
			eventChannel[static_cast<int>(eventType)].insert(listener);
		}
	}
}

void WorldManager::removeListener(WorldListener* listener,
		WorldEvent::Type eventType) {
	if (listener != nullptr) {
		if (static_cast<int>(eventType) < 10) {
			//eventChannel[static_cast<int>(eventType)].erase(listener);
			WorldListenerPair pair;
			pair.listener = listener;
			pair.type = eventType;
			worldListenersToBeErased.push_back(std::move(pair));
		}
	}
}

void WorldManager::raiseEvent(const WorldEvent& event) {
	if (event.type != WorldEvent::Type::Custom
			&& event.type != WorldEvent::Type::Nothing) {
		for (auto listener : eventChannel[static_cast<int>(event.type)]) {
			listener->acceptEvent(event);
		}
	} else if (event.type == WorldEvent::Type::Custom) {
		auto itr = customChannel.find(event.customData.channel);
		if (itr != customChannel.end()) {
			for (auto listener : itr->second) {
				listener->acceptEvent(event);
			}
		} else {
			Logger::getInstance().write(
					"During broadcasting a Custom Event on channel: /'"
							+ event.customData.channel
							+ "/'. The channel does not exist, which means that no Listener was registered for this channel until this broadcast.",
					Logger::MessageType::Warning);
		}
	} else {
		Logger::getInstance().write(
				"An Event with type /'Nothing/' was broadcasted. Nothing will happen.");
	}
}

void WorldManager::getStringCallback(const std::string& name, int& var) {
	auto& lua = LuaEngine::getInstance();
	int x = lua.getReference(name);
	if (x != LUA_NOREF && x != LUA_REFNIL) {
		lua_State *lstate = lua.getState();
		lua_getref(lstate, x);
		if (lua_isfunction(lstate, -1)) {
			var = x;
		} else {
			Logger::getInstance().write(
					"WorldManager call: A CallBack was passed "
							+ std::string(lua_typename(lstate, -1))
							+ " instead of a function",
					Logger::MessageType::Warning);
			lua_unref(lstate, x);
		}
	}
}

void WorldManager::setCallback(Callback call, const std::string& name) {
	if (static_cast<int>(call) < 10) {
		int ref = LuaEngine::getInstance().getReference(name);
		try {
			callbacks[static_cast<int>(call)].setLuaReference(ref);
		} catch (Exception& ex) {
			Logger::getInstance().write(
					"During setting the callback: "
							+ callbacks[static_cast<int>(call)].getName()
							+ " Reason: " + ex.reason(),
					Logger::MessageType::LuaError);
		}
	}
}

void WorldManager::setCallback(Callback call, lua_Object func) {
	if (static_cast<int>(call) < 10) {
		try {
			callbacks[static_cast<int>(call)].setFromStack(
					LuaEngine::getInstance().getState(), func);
		} catch (Exception& ex) {
			Logger::getInstance().write(
					"During setting the callback: "
							+ callbacks[static_cast<int>(call)].getName()
							+ " Reason: " + ex.reason(),
					Logger::MessageType::LuaError);
		}
	}
}

void WorldManager::getFuncCallBack(lua_Object func, int& var) {
	lua_State *lstate = LuaEngine::getInstance().getState();
	if (lua_isfunction(lstate, func)) {
		lua_pushvalue(lstate, func);
		var = luaL_ref(lstate, LUA_REGISTRYINDEX);
	} else {
		Logger::getInstance().write(
				"WorldManager call: A CallBack was passed "
						+ std::string(lua_typename(lstate, func))
						+ " instead of a function",
				Logger::MessageType::Warning);
	}
}

const LuaFunctor& WorldManager::getCallback(Callback call) const {
	if (static_cast<int>(call) < 10) {
		return callbacks[static_cast<int>(call)];
	} else {
		return callbacks[0];
	}
}

void WorldManager::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::WorldManager");
}

void WorldManager::callCallback(Callback call,
		std::initializer_list<LuaPushable*> args) {
	if (static_cast<int>(call) < 10) {
		callbacks[static_cast<int>(call)](args);
	}
}

void WorldManager::addFrameListener(Updateable* listener) {
	frameListeners.insert(listener);
}

void WorldManager::removeFrameListener(Updateable* listener) {
	frameListenersToBeRemoved.push_back(listener);
}

void WorldManager::createPlayer() {
	if (player == nullptr) {
		player = new Player;
	}
	player->setClass("Null");
	player->setView(camera);
}
void WorldManager::destroyPlayer() {
	if (player != nullptr) {
		delete player;
	}
}

void WorldManager::addListener(WorldListener* listener,
		const std::string& channel) {
	customChannel[channel].insert(listener);
}

void WorldManager::removeListener(WorldListener* listener,
		const std::string& channel) {
	auto itr = customChannel.find(channel);
	if (itr != customChannel.end()) {
		CustomListenerPair pair;
		pair.channel = channel;
		pair.listener = listener;
		customListenersToBeErased.push_back(std::move(pair));
	}
}

} /* namespace Zeta */

