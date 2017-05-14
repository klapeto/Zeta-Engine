/*
 * SeekingProjectile.cpp
 *
 *  Created on: 23 Ιουλ 2014
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

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/SeekingProjectile.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/View.hpp>
#include <unordered_set>
#include <tolua++.h>
#include <utility>

namespace Zeta {

SeekingProjectile::SeekingProjectile(const ProjectileClass *cls,
		ActiveAbility *parent, Float x, Float y) :
		Projectile(cls, parent, x, y), target(nullptr), destinationReached(
				false) {
}

SeekingProjectile::~SeekingProjectile() {
}

void SeekingProjectile::move(Float elapsedTime) {
	if (target == nullptr) {
		target = parentAbility->getOwner().getTarget();
		if (target == nullptr) {
			state = ProjectileState::Dead;
			return;
		}
	}
	if (destinationReached) {
		projectileClass->onDestinationReach(this);
	}
	Float speed = projectileClass->getSpeed() * elapsedTime;
	targetPosition = target->getPosition();
	direction = targetPosition - position;
	if (direction.getLength() < (speed + 0.1f)) {
		setPosition(targetPosition.getX(), targetPosition.getY());
		destinationReached = true;
	}
	direction.normalize();
	offsetPosition(direction.getX() * speed, direction.getY() * speed);
	// TODO: Seperate Class
	if (projectileClass->isDirectionalRotate()) {
		rotation = std::atan2(direction.getY(), direction.getX()) * 57.2957795f;
	} else {
		calculateAnimationDirection(LifeformState::Action::Moving);
	}
	if (!camera->isInView(*this)) {
		state = ProjectileState::Dead;
	}
}

void SeekingProjectile::onCollidedWith(Object* other) {
	if (state == ProjectileState::Moving) {
		if (other != &parentAbility->getOwner()) {
			if (collidedObjects.find(other) == collidedObjects.end()) {
				projectileClass->onCollision(this, other);
				collidedObjects.insert(other);
			}
			//if (other == target) {
			//projectileClass->onDestinationReach(this);
			//destroy();
			//}
		}
	}
}

void SeekingProjectile::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::SeekingProjectile");
}

void SeekingProjectile::resetState() {
	target = parentAbility->getOwner().getTarget();
	collidedObjects.clear();
	destinationReached = false;
}

} /* namespace Zeta */
