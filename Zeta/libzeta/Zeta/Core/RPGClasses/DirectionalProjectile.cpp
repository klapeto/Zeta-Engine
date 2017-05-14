/*
 * DirectionalProjectile.cpp
 *
 *  Created on: 21 Ιουλ 2014
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

#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/DirectionalProjectile.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/View.hpp>

namespace Zeta {

DirectionalProjectile::DirectionalProjectile(const ProjectileClass* cls,
		ActiveAbility* parent, Float x, Float y) :
		Projectile(cls, parent, x, y) {
	calculateTargetPosition();
	calculateAnimationDirection(LifeformState::Action::Idle);
}

DirectionalProjectile::~DirectionalProjectile() {

}

void DirectionalProjectile::move() {
	offsetPosition(direction.getX() * projectileClass->getSpeed(),
			direction.getY() * projectileClass->getSpeed());
	if (!camera->isInView(*this)) {
		projectileClass->onDestinationReach(this);
		state = ProjectileState::Dead;
	}
}

void DirectionalProjectile::calculateTargetPosition() {
	switch (parentAbility->getOwner().getState().getDirection()) {
	case LifeformState::Direction::Down:
		direction.set(0.0f, 1.0f);
		break;
	case LifeformState::Direction::Up:
		direction.set(0.0f, -1.0f);
		break;
	case LifeformState::Direction::Left:
		direction.set(-1.0f, 0.0f);
		break;
	case LifeformState::Direction::Right:
		direction.set(1.0f, 0.0f);
		break;
	default:
		break;
	}
}

} /* namespace Zeta */
