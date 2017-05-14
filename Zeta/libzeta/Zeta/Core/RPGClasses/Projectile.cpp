/*
 * Projectile.cpp
 *
 *  Created on: 19 Ιουλ 2014
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

#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Projectile.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <Zeta/Core/View.hpp>
#include <unordered_map>
#include <tolua++.h>
#include <utility>

namespace Zeta {

Projectile::Projectile(const ProjectileClass *cls, ActiveAbility *parent,
		Float x, Float y) :
		Object(x, y, 10, 10), projectileClass(cls), parentAbility(parent), state(
				ProjectileState::Inactive), animDir(
				LifeformState::Direction::Down) {
	camera = &WorldManager::getInstance().getView();
	animation.setAnimationClass(cls->getAnimationClass());
	animation.setReleaseResources(false);
	bounding = animation.getAnimationClass().getBoundBox();
	collideAble = false;
	triggersCollisionEvents = true;
	addShapesToBeOffseted();
	bounding.offsetPosition(x, y);
	//setPosition(x, y);
	applyOffsets();
}

void Projectile::destroy() {
	calculateAnimationDirection(LifeformState::Action::Dying, true);
	state = ProjectileState::Dying;
}

void Projectile::charge() {
	animation.setAnimation(
			animDir.getDirection() | LifeformState::Action::Dead);
	animation.getMainAnimationPlayer().play();
	state = ProjectileState::Charging;
}

void Projectile::release() {
	animation.setAnimation(
			animDir.getDirection() | LifeformState::Action::Moving);
	projectileClass->onRelease(this);
	animation.getMainAnimationPlayer().play();
	state = ProjectileState::Moving;
}

Projectile::~Projectile() {

}

void Projectile::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void Projectile::update(Float elapsedTime) {
	switch (state) {
	case ProjectileState::Charging:
		if (!animation.getMainAnimationPlayer().isPlaying()) {
			animation.setAnimation(
					animDir.getDirection()
							| LifeformState::Action::Idle);
			animation.getMainAnimationPlayer().play();
		}
		break;
	case ProjectileState::Moving:
		move(elapsedTime);
		WorldManager::getInstance().getCurrentMap().isRectangleColliding(
				bounding, this);
		break;
	case ProjectileState::Dying:
		if (!animation.getMainAnimationPlayer().isPlaying()) {
			visible = false;
			state = ProjectileState::Dead;
		}
		break;
	case ProjectileState::Dead:
	case ProjectileState::Inactive:
		break;
	}
	animation.update(elapsedTime);
}

void Projectile::onCollidedWith(Object* other) {
	if (state == ProjectileState::Moving) {
		if (other != &parentAbility->getOwner()) {
			if (collidedObjects.find(other) == collidedObjects.end()) {
				projectileClass->onCollision(this, other);
				collidedObjects.insert(other);
			}
		}
	}
}

void Projectile::draw(Float x, Float y, Float rotation, Float scale) const {
	if (visible) {
		if (state == ProjectileState::Moving) {
			animation.draw(position.getX() - x, position.getY() - y,
					rotation + this->rotation, scale);
		} else {
			animation.draw(position.getX() - x, position.getY() - y, rotation,
					scale);
		}
	}
}

void Projectile::move(Float elapsedTime) {
	Float speed = projectileClass->getSpeed() * elapsedTime;
	offsetPosition(direction.getX() * speed, direction.getY() * speed);
	if (projectileClass->isDirectionalRotate()) {
		rotation = std::atan2(direction.getY(), direction.getX()) * 57.2957795f;
	} else {
		calculateAnimationDirection(LifeformState::Action::Moving);
	}
	if (!camera->isInView(*this)) {
		state = ProjectileState::Dead;
	}
	if (position.getDistance(targetPosition) < (speed + 0.1f)) {
		setPosition(targetPosition.getX(), targetPosition.getY());
		projectileClass->onDestinationReach(this);
	}
}

void Projectile::calculateAnimationDirection(LifeformState::Action action,
		bool changeAnimation) {
	LifeformState::Direction dir = LifeformState::Direction::Left;
	if (direction.getX() > 0.5f) {
		dir = LifeformState::Direction::Right;
	} else if (direction.getX() < -0.5f) {
		dir = LifeformState::Direction::Left;
	} else {
		if (direction.getY() >= 0.5f) {
			dir = LifeformState::Direction::Down;
		} else if (direction.getY() <= -0.5f) {
			dir = LifeformState::Direction::Up;
		}
	}
	if (animDir.getDirection() != dir || changeAnimation) {
		animDir = dir;
		animation.setAnimation(dir | action);
		animation.getMainAnimationPlayer().play();
	}
}

void Projectile::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Projectile");
}

void Projectile::abort() {
	state = ProjectileState::Dead;
}

void Projectile::applyOffsets() {
	switch (parentAbility->getOwner().getState().getDirection()) {
	case LifeformState::Direction::Down:
		offsetPosition(
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Down).getX(),
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Down).getY());
		break;
	case LifeformState::Direction::Up:
		offsetPosition(
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Up).getX(),
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Up).getY());
		break;
	case LifeformState::Direction::Left:
		offsetPosition(
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Left).getX(),
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Left).getY());
		break;
	case LifeformState::Direction::Right:
		offsetPosition(
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Right).getX(),
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Right).getY());
		break;
	default:
		offsetPosition(
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Down).getX(),
				projectileClass->getOffset(ProjectileClass::SpawnOffset::Down).getY());
		break;
	}
}

} /* namespace Zeta */

