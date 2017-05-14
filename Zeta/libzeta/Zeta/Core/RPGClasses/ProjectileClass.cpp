/*
 * ProjectileClass.cpp
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/LuaReferenced.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/DirectionalProjectile.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/SeekingProjectile.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <string>

namespace Zeta {

ProjectileClass::ProjectileClass() :
		speed(4.0f), type(ProjectileType::Directional), directionalRotate(false) {
	animClass = &NullReference<AnimationClass>::getNull();
	name = "null ProjectileClass";
}

ProjectileClass::ProjectileClass(const LuaTable& table) :
		name("Unamed Projectile"), speed(4.0f), type(
				ProjectileType::Directional), directionalRotate(false) {
	load(table);

}

const Vector2& ProjectileClass::getOffset(SpawnOffset offset) const {
	if (static_cast<int>(offset) >= 0 and static_cast<int>(offset) <= 3) {
		return spawnOffsets[static_cast<int>(offset)];
	} else {
		return spawnOffsets[0];
	}
}

ProjectileClass::~ProjectileClass() {
	ResourceContext* resources = &System::getInstance().getResourcesManager();
	if (resources != nullptr) {
		System::getInstance().getResourcesManager().releaseResource(*animClass);
	}
}

void ProjectileClass::onCollision(Projectile* invoker, Object* obj) const {
	ObjectHandler handler(this, invoker);
	obj->accept(handler);
}

void ProjectileClass::onRelease(Projectile* invoker) const {
	onReleaseF( { invoker });
}

void ProjectileClass::onDestinationReach(Projectile* invoker) const {
	onDestinationReachF( { invoker });
}

Projectile* ProjectileClass::create(ActiveAbility *parent) const {
	switch (type) {
	case ProjectileType::Directional:
		return new DirectionalProjectile(this, parent,
				parent->getOwner().getPosition().getX(),
				parent->getOwner().getPosition().getY());
		break;
	case ProjectileType::Seeking:
		return new SeekingProjectile(this, parent,
				parent->getOwner().getPosition().getX(),
				parent->getOwner().getPosition().getY());
	case ProjectileType::Normal:
		return new Projectile(this, parent,
				parent->getOwner().getPosition().getX(),
				parent->getOwner().getPosition().getY());
		break;
	}
	return nullptr;
}

void ProjectileClass::ObjectHandler::handle(Lifeform& obj) {
	cls->onCollisionF( { proj, &obj });
}

void ProjectileClass::ObjectHandler::handle(Player& obj) {
	cls->onCollisionF( { proj, &obj });
}

void Zeta::ProjectileClass::load(const LuaTable& table) {
	{

		if (animClass != nullptr) {
			System::getInstance().getResourcesManager().releaseResource(
					*animClass);
		}
		std::string animClassPath;
		if (table.getField(LuaString("AnimationClass"), animClassPath)) {
			animClass =
					&System::getInstance().getResourcesManager().getAnimationClass(
							animClassPath);
		} else {
			animClass = &NullReference<AnimationClass>::getNull();
		}
	}

	table.getField(LuaString("Name"), name);
	table.getField(LuaString("Speed"), speed);
	table.getField(LuaString("DirectionalRotate"), directionalRotate);
	table.getField(LuaString("onCollision"), onCollisionF);
	onCollisionF.setName(name + ": onCollision");
	table.getField(LuaString("onRelease"), onReleaseF);
	onReleaseF.setName(name + ": onRelease");
	table.getField(LuaString("onDestinationReach"), onDestinationReachF);
	onDestinationReachF.setName(name + ": onDestinationReach");

	{
		LuaTable offsets;
		table.getField(LuaString("Offsets"), offsets);
		LuaTable direction;
		if (offsets.getField(LuaString("Up"), direction)) {
			int x = 0, y = -1;
			direction.getField(LuaString("x"), x);
			direction.getField(LuaString("y"), y);
			spawnOffsets[static_cast<int>(SpawnOffset::Up)].set(x, y);
		}
		if (offsets.getField(LuaString("Down"), direction)) {
			int x = 0, y = 1;
			direction.getField(LuaString("x"), x);
			direction.getField(LuaString("y"), y);
			spawnOffsets[static_cast<int>(SpawnOffset::Down)].set(x, y);
		}
		if (offsets.getField(LuaString("Right"), direction)) {
			int x = 1, y = 0;
			direction.getField(LuaString("x"), x);
			direction.getField(LuaString("y"), y);
			spawnOffsets[static_cast<int>(SpawnOffset::Right)].set(x, y);
		}
		if (offsets.getField(LuaString("Left"), direction)) {
			int x = -1, y = 0;
			direction.getField(LuaString("x"), x);
			direction.getField(LuaString("y"), y);
			spawnOffsets[static_cast<int>(SpawnOffset::Left)].set(x, y);
		}
	}

	{
		int tempT;
		if (table.getField(LuaString("Type"), tempT)) {
			if (tempT <= 3 && tempT >= 0) {
				type = static_cast<ProjectileType>(tempT); // The root of ALL EVIL!!
			}
		} else {
			Logger::getInstance().write(
					"At Projectile data named: " + name
							+ " the field \"Type\" has invalid number! Defaulting to Directional Projectile",
					Logger::MessageType::Warning);
			type = ProjectileType::Directional;
		}
	}
}

} /* namespace Zeta */
