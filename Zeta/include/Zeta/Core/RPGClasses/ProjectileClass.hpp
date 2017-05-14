/*
 * ProjectileClass.hpp
 *
 *  Created on: 20 Ιουλ 2014
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

#ifndef PROJECTILECLASS_HPP_
#define PROJECTILECLASS_HPP_

#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>

struct lua_State;

namespace Zeta {

class Object;
class Projectile;
class ActiveAbility;
class Lifeform;
class LuaTable;

class ProjectileClass {
public:

	enum class SpawnOffset {
		Up = 0, Right, Left, Down
	};

	enum class ProjectileType {
		Normal, Directional, Seeking
	};

	const LuaFunctor& getOnCollision() const {
		return onCollisionF;
	}

	void setOnCollision(const LuaFunctor& onCollisionF) {
		this->onCollisionF = onCollisionF;
	}

	const LuaFunctor& getOnDestinationReach() const {
		return onDestinationReachF;
	}

	void setOnDestinationReach(const LuaFunctor& onDestinationReachF) {
		this->onDestinationReachF = onDestinationReachF;
	}

	const LuaFunctor& getOnRelease() const {
		return onReleaseF;
	}

	void setOnRelease(const LuaFunctor& onRelease) {
		this->onReleaseF = onReleaseF;
	}

	const AnimationClass& getAnimationClass() const {
		return *animClass;
	}

	Float getSpeed() const {
		return speed;
	}

	bool isDirectionalRotate() const {
		return directionalRotate;
	}

	void load(const LuaTable& table);

	const Vector2& getOffset(SpawnOffset offset) const;

	void onCollision(Projectile *invoker, Object *obj) const;
	void onRelease(Projectile *invoker) const;
	void onDestinationReach(Projectile *invoker) const;

	ProjectileClass(ProjectileClass&&) = default;
	ProjectileClass& operator=(ProjectileClass&&) = default;

	Projectile* create(ActiveAbility *parent) const;

	ProjectileClass();
	ProjectileClass(const LuaTable& table);
	virtual ~ProjectileClass();
private:

	class ObjectHandler: public Visitor {
	public:
		void handle(Lifeform& obj);
		void handle(Player& obj);

		ObjectHandler(const ProjectileClass *cls, Projectile *proj) :
				cls(cls), proj(proj) {

		}

	private:
		const ProjectileClass *cls;
		Projectile *proj;
	};

	Vector2 spawnOffsets[4];
	std::string name;

	const AnimationClass *animClass;
	Float speed;
	LuaFunctor onReleaseF;
	LuaFunctor onCollisionF;
	LuaFunctor onDestinationReachF;
	ProjectileType type;
	bool directionalRotate;

};

} /* namespace Zeta */

#endif /* PROJECTILECLASS_HPP_ */
