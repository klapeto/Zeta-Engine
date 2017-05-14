/*
 * AggressiveBehaviour.cpp
 *
 *  Created on: 3 Οκτ 2014
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

#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/AI/AggressiveBehaviour.hpp>
#include <Zeta/Core/RPGClasses/AI/Faction.hpp>
#include <Zeta/Core/RPGClasses/ClassifiedAbility.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <unordered_map>

namespace Zeta {
AggressiveBehaviour::AggressiveBehaviour(Lifeform& owner, Float agroRange,
		Float driftRange) :
		Behaviour(owner), target(nullptr), curAbility(nullptr), agroRange(
				agroRange), driftRange(driftRange), state(State::Scanning) {
}

AggressiveBehaviour::~AggressiveBehaviour() {

}

void AggressiveBehaviour::update(Float elapsedTime) {
		switch (state) {
		case State::Scanning:
			scan();
			break;
		case State::Attacking:
			if (target->isAlive()) {
				if (curAbility == nullptr) {
					getAbility();
				}
				attack();
			} else {
				owner->moveToPosition(initialPosition);
				state = State::FallBack;
				target = nullptr;
				break;
			}
			break;
		case State::Casting:
			if (curAbility->isDone()) {
				getAbility();
				state = State::Attacking;
			}
			break;
		case State::Moving:
			if (target->isAlive()) {
				if (owner->getDistance(*target)
						< curAbility->getClass().getRange()) {
					state = State::Attacking;
					attack();
				} else {
					owner->moveToPosition(target->getPosition());
				}
			} else {
				owner->moveToPosition(initialPosition);
				state = State::FallBack;
				target = nullptr;
				break;
			}
			if (owner->getDistance(initialPosition) > driftRange) {
				owner->moveToPosition(initialPosition);
				state = State::FallBack;
			}
			break;
		case State::FallBack:
			if (!owner->isMoving()) {
				state = State::Scanning;
				owner->setInCombat(false);
			}
			break;
		}
}

void AggressiveBehaviour::scan() {

	class ObjHandler: public Visitor {
	public:

		void handle(Lifeform& lf) {
			if (&lf != owner->owner && lf.isAlive()) {
				if (owner->owner->getFaction().isHostile(lf.getFaction())) {
					if (owner->owner->getDistance(lf) <= owner->agroRange) {
						valid = true;
					}
				}
			}
		}
		void handle(Player& lf) {
			if (&lf != owner->owner && lf.isAlive()) {
				if (owner->owner->getFaction().isHostile(lf.getFaction())) {
					if (owner->owner->getDistance(lf) <= owner->agroRange) {
						valid = true;
					}
				}
			}
		}

		bool isValid() const {
			return valid;
		}

		ObjHandler(AggressiveBehaviour* owner) :
				owner(owner), valid(false) {

		}
	private:
		AggressiveBehaviour *owner;
		bool valid;
	} handler(this);
	if (owner->getActiveAbilities().size() > 0) {
		auto& visibles =
				WorldManager::getInstance().getCurrentMap().getVisibleObjects();
		for (auto obj : visibles) {
			obj->accept(handler);
			if (handler.isValid()) {
				target = static_cast<Lifeform*>(obj);
				state = State::Attacking;
				owner->setInCombat(true);
				owner->setTarget(target);
				break;
			}
		}
	}
}

void AggressiveBehaviour::attack() {
	if (target->isAlive()) {
		if (curAbility != nullptr) {
			switch (curAbility->invoke()) {
			case Ability::Result::OutOfRange:
				state = State::Moving;
				initialPosition = owner->getPosition();
				break;
			case Ability::Result::Success:
				state = State::Casting;
				break;
			default:
				state = State::Moving;
				initialPosition = owner->getPosition();
				getAbility();
				break;
			}
		}
	} else {
		state = State::FallBack;
		owner->setInCombat(false);
	}
}

void AggressiveBehaviour::getAbility() {
	auto& abilities = owner->getActiveAbilities();

	for (auto abi : abilities) {
		if (abi.second->canBeInvoked()) {
			curAbility = abi.second;
			return;
		}
	}
	if (abilities.size() > 0) {
		for (auto abi : abilities) {
			if (abi.second->isThereEnoughMana()) {
				curAbility = abi.second;
				return;
			}
		}
	} else {
		curAbility = nullptr;
	}
}

void AggressiveBehaviour::onDeath() {
	state = State::Scanning;
}
} /* namespace Zeta */
