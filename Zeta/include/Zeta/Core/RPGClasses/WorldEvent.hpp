/*
 * WorldEvent.hpp
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

#ifndef WORLDEVENT_HPP_
#define WORLDEVENT_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <string>

namespace Zeta {

class Lifeform;
class Ability;
class Object;

class WorldEvent: public LuaPushable {
public:

	enum class Type {
		Damage,
		Death,
		Interact,
		AbilityUse,
		WorldExit,
		Collision,
		Custom,
		Nothing
	};

	typedef struct {
		Lifeform *victim;
		Lifeform *dealer;
		unsigned amount;
	} DamageEvent;

	typedef struct {
		Lifeform *victim;
	} DeathEvent;

	typedef struct {
		Lifeform *user1;
		Lifeform *user2;
	} InteractEvent;

	typedef struct {
		Lifeform *user;
		Ability *ability;
	} AbilityUseEvent;

	typedef struct {
		Lifeform *invoker;
	} WorldExitEvent;

	typedef struct {
		Lifeform* invoker;
		Object* other;
	} CollisionEvent;

	union Event {
		DamageEvent damageEvent;
		DeathEvent deathEvent;
		InteractEvent interactEvent;
		AbilityUseEvent abilityUseEvent;
		WorldExitEvent worldExitEvent;
		CollisionEvent collisionEvent;
	} data;

	void broadcast();

	void setAsDamageEvent(Lifeform *victim, Lifeform *dealer, unsigned amount);
	void setAsDeathEvent(Lifeform *victim);
	void setAsInteractEvent(Lifeform *user1, Lifeform *user2);
	void setAsAbilityUseEvent(Lifeform *user, Ability *ability);
	void setAsWorldExitEvent(Lifeform *invoker);
	void setAsCollisionEvent(Lifeform *invoker, Object* other);
	void setAsCustomEvent(const std::string& channel, lua_Object table);

	void pushToLua(lua_State* lstate);

	static Type toEventType(int num) {
		switch (static_cast<Type>(num)) {
		case Type::Damage:
		case Type::Death:
		case Type::Interact:
		case Type::AbilityUse:
		case Type::WorldExit:
		case Type::Nothing:
		case Type::Collision:
		case Type::Custom:
			return static_cast<Type>(num);
			break;
		default:
			return Type::Nothing;
			break;
		}
		return Type::Nothing;
	}

	Type getType() const {
		return type;
	}

	Type type;
	struct CustomEvent {
		std::string channel;
		mutable LuaTable table;
	} customData;

	WorldEvent() :
			type(Type::Nothing) {

	}
	WorldEvent(Type type) :
			type(type) {

	}
	~WorldEvent() {

	}
};

} /* namespace Zeta */

#endif /* WORLDEVENT_HPP_ */
