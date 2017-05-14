/*
 * Projectile.hpp
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

#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/RPGClasses/LifeformState.hpp>
#include <list>
#include <Zeta/Core/ZSet.hpp>

namespace Zeta {

class ActiveAbility;
class ProjectileClass;
class View;

class Projectile: public Object {
public:

	enum class ProjectileState {
		Charging, Moving, Dying, Dead, Inactive
	};

	void update(Float elapsedTime);
	virtual void onCollidedWith(Object *other);
	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;
	void accept(Visitor& visitor);
	void clearCollidedObjects() {
		collidedObjects.clear();
	}
	void onClick(Object *other) {

	}
	void destroy();
	void charge();
	void release();

	void abort();

	void applyOffsets();

	bool isToBeDeleted() const {
		return (state == ProjectileState::Dead);
	}

	void setTargetLocation(Float x, Float y) {
		targetPosition.set(x, y);
	}

	ActiveAbility* getParentAbility() {
		return parentAbility;
	}

	virtual void resetState() {

	}

	virtual void pushToLua(lua_State* lstate);

	Projectile(const ProjectileClass *cls, ActiveAbility *parent, Float x,
			Float y);
	virtual ~Projectile();
protected:
	enum class AnimationDirection {
		Right, Left, Up, Down
	};
	ZSet<Object*> collidedObjects;
	AnimationHandler animation;
	const ProjectileClass *projectileClass;
	ActiveAbility *parentAbility;
	View *camera;
	Vector2 targetPosition;
	Vector2 direction;
	ProjectileState state;
	LifeformState animDir;
	Float rotation;

	virtual void move(Float elapsedTime);
	void calculateAnimationDirection(LifeformState::Action action,
			bool changeAnimation = false);
};

} /* namespace Zeta */

#endif /* PROJECTILE_HPP_ */
