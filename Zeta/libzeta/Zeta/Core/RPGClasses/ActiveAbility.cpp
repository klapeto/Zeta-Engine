/*
 * ActiveAbility.cpp
 *
 *  Created on: 10 Απρ 2014
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
#include <Zeta/Core/ResourceClasses/SoundInstance.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/Projectile.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/ZMap.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <tolua++.h>

namespace Zeta {

ActiveAbility::ActiveAbility(const ActiveAbilityClass& abilityClass,
		Lifeform* owner, int level) :
		ClassifiedAbility(abilityClass, owner, level), castingSound(nullptr), releaseSound(
				nullptr), target(nullptr), ownerMana(
				owner->getAttribute("Mana")), frameCounter(
				abilityClass.getCastTime()), state(State::Ready), hasCastingAnimation(
				false), hasReleaseAnimation(false), hasCastingSound(false), hasReleaseSound(
				false), animationChanged(false), isCastingSoundPlaying(false), finished(
				false) {

	auto& resMan = System::getInstance().getResourcesManager();
	if (abilityClass.getCastAnimation() != "") {
		hasCastingAnimation = true;
	}
	if (abilityClass.getReleaseAnimation() != "") {
		hasReleaseAnimation = true;
	}
	if (abilityClass.getCastSound() != "") {
		hasCastingSound = true;
		castingSound = &resMan.getSound(abilityClass.getCastSound());
	}
	if (abilityClass.getReleaseSound() != "") {
		hasReleaseSound = true;
		releaseSound = &resMan.getSound(abilityClass.getReleaseSound());
	}
	castTime = frameCounter;
	manaCost = abilityClass.getManaCost();
	coolDown = abilityClass.getCooldown();
	range = abilityClass.getRange();
	{
		const ZMap<std::string, ProjectileClass>& projCls =
				abilityClass.getProjectileClasses();

		for (auto& projC : projCls) {
			availableProjectiles[projC.first] = projC.second.create(this);
		}

	}
}

ActiveAbility::~ActiveAbility() {
	if (hasCastingSound) {
		castingSound->stop();
		delete castingSound;
	}
	if (hasReleaseSound) {
		releaseSound->stop();
		delete releaseSound;
	}
	for (auto proj : availableProjectiles) {
		delete proj.second;
	}
}

Ability::Result ActiveAbility::invoke() {
	if (state == State::Ready) {
		if (ownerMana.getValue() >= manaCost) {
			return checkConditions();
		} else {
			return Ability::Result::NoMana;
		}
	} else {
		return Ability::Result::onCooldown;
	}
}

void ActiveAbility::update(Float elapsedTime) {
	switch (state) {
	case State::Casting:
		frameCounter -= elapsedTime;
		if (frameCounter <= 0) {
			release();
			frameCounter = coolDown;
			state = State::onCoodown;
		}
		break;
	case State::onCoodown:
		frameCounter -= elapsedTime;
		if (frameCounter <= 0) {
			state = State::Ready;
			frameCounter = castTime;
		}
		break;
	default:
		break;
	}
	{
		Map& curMap = WorldManager::getInstance().getCurrentMap();
		for (auto itr = projectiles.begin(); itr != projectiles.end();) {
			if (!(*itr)->isToBeDeleted()) {
				++itr;
			} else {
				curMap.removeObject((*itr));
				itr = projectiles.erase(itr);
			}
		}
	}
	if (animationChanged && owner->isAnimationFinished()) {
		owner->fullResetState();
		animationChanged = false;
		finished = true;
	}
}

void ActiveAbility::release() {
	if (hasReleaseAnimation) {
		owner->setActionAnimation(abilityClass.getReleaseAnimation());
	}
	if (hasReleaseSound) {
		releaseSound->play();
	}
	if (hasCastingSound) {
		castingSound->stop();
	}
	owner->offsetMana(-manaCost);
	for (auto projectile : projectiles) {
		projectile->release();
	}
	state = State::onCoodown;
	animationChanged = true;
}

Ability::Result ActiveAbility::checkConditions() {
	target = owner->getTarget();
	if (target != nullptr) {
		if (owner->isHostileWith(target)) {
			if (target->isAlive()) {
				if (owner->getDistance(*target) <= range) {
					cast();
					return Result::Success;
				} else {
					return Result::OutOfRange;
				}
			} else {
				return Result::TargetIsDead;
			}
		} else {
			return Result::TargetIsNotHostile;
		}
	} else {
		return Result::NoTarget;
	}
}

void ActiveAbility::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void ActiveAbility::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::ActiveAbility");
}

bool ActiveAbility::canBeInvoked() const {
	return (state == State::Ready) && ownerMana.getValue() >= manaCost;
}

void ActiveAbility::stopCasting() {
	Map& curMap = WorldManager::getInstance().getCurrentMap();
	for (auto itr = projectiles.begin(); itr != projectiles.end();) {
		curMap.removeObject((*itr));
		itr = projectiles.erase(itr);
	}
	if (hasCastingSound) {
		castingSound->stop();
	}
	state = State::Ready;
	animationChanged = false;
	finished = true;
	frameCounter = castTime;
}

bool ActiveAbility::isThereEnoughMana() const {
	return ownerMana.getValue() >= manaCost;
}

void ActiveAbility::cast() {
	finished = false;
	owner->face(target);
	if (hasCastingAnimation) {
		owner->setActionAnimation(abilityClass.getCastAnimation());
	}
	owner->setCastingState();
	if (hasCastingSound) {
		castingSound->play();
	}
	abilityClass.onApply(this, owner, target);
	for (auto projectile : projectiles) {
		projectile->charge();
	}
	state = State::Casting;
	WorldEvent ev;
	ev.setAsAbilityUseEvent(owner, this);
	ev.broadcast();
}

void ActiveAbility::invokeProjectile(const std::string& name, Float x,
		Float y) {
	auto itr = availableProjectiles.find(name);
	if (itr != availableProjectiles.end()) {
		Projectile* proj = itr->second;
		projectiles.insert(proj);
		proj->setPosition(owner->getPosition());
		proj->offsetPosition(x, y);
		proj->applyOffsets();
		proj->resetState();
		WorldManager::getInstance().getCurrentMap().insertObject(proj, false);
	}
}

void ActiveAbility::applyEffect(const std::string& name, Lifeform* target,
		int level) {
	abilityClass.applyEffect(name, target, level, this);
}

void ActiveAbility::onLevelChange() {
	abilityClass.onLevelChange(this);
}

} /* namespace Zeta */
