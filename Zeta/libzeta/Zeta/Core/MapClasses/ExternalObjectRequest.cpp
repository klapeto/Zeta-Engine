/*
 * ExternalObjectRequest.cpp
 *
 *  Created on: 13 Δεκ 2014
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

#include <Zeta/Core/AnimationClasses/AnimationEffectsManager.hpp>
#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/MapClasses/ExternalObjectRequest.hpp>
#include <Zeta/Core/RPGClasses/Enemy.hpp>
#include <Zeta/Core/RPGClasses/Npc.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <lua.hpp>
#include <tolua++.h>

namespace Zeta {

void ExternalObjectRequest::handle(RenderingContext& context) {
	lua_State* lstate = LuaEngine::getInstance().getState();

	// For all the classes
	for (auto& cls : *objectClasses) {
		int stackBasePointer = lua_gettop(lstate);

		// get the require function
		lua_getglobal(lstate, "require");

		// push the  module name on the stack to be used as parameter to require
		lua_pushlstring(lstate, cls.module.c_str(), cls.module.size());

		// call the require
		if (lua_pcall(lstate, 1, 1, 0)) {
			// if anything happens, then report it
			Logger::getInstance().write(
					"During getting Map Object via Lua Class with name:"
							+ cls.module + " Reason: "
							+ std::string(lua_tostring(lstate, -1)),
					Logger::MessageType::LuaError);
			// reset the stack
			lua_settop(lstate, stackBasePointer);
			// ignore this and go to the next object
			continue;
		}

		// check if the require has returned a table
		if (lua_istable(lstate, -1)) {
			// If it is a table, the according to the type, create an Object
			switch (cls.type) {
			case ObjectSource::ObjectType::Enemy:
				getEnemy(lstate, cls.spawnX, cls.spawnY);
				break;
			case ObjectSource::ObjectType::Npc:
				getNpc(lstate, cls.spawnX, cls.spawnY);
				break;
			default:
				break;
			}
		}

		// reset the stack
		lua_settop(lstate, stackBasePointer);
	}
}

ExternalObjectRequest::ExternalObjectRequest(
		const std::vector<ObjectSource>& objectClasses) :
		objectClasses(&objectClasses) {
}

ExternalObjectRequest::~ExternalObjectRequest() {

}

void ExternalObjectRequest::getEnemy(lua_State* lstate, Float x, Float y) {

	// Get the Class field of the table
	lua_getfield(lstate, -1, "Class");
	tolua_Error err;

	// Check if the Class field is a Zeta::LifeformCLass
	if (tolua_isusertype(lstate, -1, "Zeta::LifeformClass", 0, &err)) {

		// If it is, then get that Class
		LifeformClass *lfClass = (LifeformClass*) tolua_tousertype(lstate, -1,
				0);
		// get some default values
		Float vanishTime = 10;
		Float respawnTime = 30;

		// Get the Vanish Time
		lua_getfield(lstate, -2, "VanishTime");

		// Check if it is a number
		if (lua_isnumber(lstate, -1)) {
			// If it is, then retrieve it
			vanishTime = lua_tonumber(lstate, -1);
		}

		// Get the VanishTime
		lua_getfield(lstate, -3, "RespawnTime");
		// Check if it is a number
		if (lua_isnumber(lstate, -1)) {
			// If it is, then retrieve it
			respawnTime = lua_tonumber(lstate, -1);
		}

		// Create a new enemy and push it to the list
		objects.push_back(new Enemy(*lfClass, x, y, respawnTime, vanishTime));
	} else {
		// If the Class field is not valid, report it
		Logger::getInstance().write(
				"During creating a new Enemy in Map Core: Reason: Field 'Class' is not type 'Zeta::LifeformClass'",
				Logger::MessageType::LuaError);
	}
}

void ExternalObjectRequest::getNpc(lua_State* lstate, Float x, Float y) {
	// Get the Class field of the table
	lua_getfield(lstate, -1, "Class");

	// Check if it is string
	if (lua_isstring(lstate, -1)) {

		// If it is, then create the NPC from the class provided
		Npc* npc = new Npc(std::string(lua_tostring(lstate, -1)), x, y, -2);

		// Get the Animations table
		lua_getfield(lstate, -2, "Animations");

		// Check if it is a table
		if (lua_istable(lstate, -1)) {

			// If it is, then we should get the OffAnimations to the NPC
			auto &mgr = AnimationEffectsManager::getInstance();

			// create a Lua Iteration loop
			lua_pushnil(lstate);
			while (lua_next(lstate, -2)) {
				// save the stack
				int stack = lua_gettop(lstate) - 1;

				// Check if the value is a table
				if (lua_istable(lstate, -1)) {

					// get the Function assign
					lua_getfield(lstate, -1, "assign");
					// push the table (OffAnimation) as parameter
					lua_pushvalue(lstate, -2);
					// push the npc as a parameter
					npc->pushToLua(lstate);
					// call the function
					if (lua_pcall(lstate, 2, 0, 0)) {
						// if anything happens, report it
						Logger::getInstance().write(
								"During calling \'assing\' of Lua OffAnimation: Reason: "
										+ std::string(lua_tostring(lstate, -1)),
								Logger::MessageType::LuaError);
					}
				}
				// reset the stack
				lua_settop(lstate, stack);
			}
		}

		// push the NPC on the list
		objects.push_back(npc);
	} else {
		// if "Class" is not a string, then report it
		Logger::getInstance().write(
				"During creating a new Npc in Map Core: Reason: Field 'Class' is not type 'String'",
				Logger::MessageType::LuaError);
	}

}

} /* namespace Zeta */
