/*
 * Player.cpp
 *
 *  Created on: 15 Μαρ 2014
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
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/LuaNumber.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/View.hpp>
#include <glibmm/ustring.h>
#include <libxml++/nodes/element.h>
#include <lua.hpp>
#include <tolua++.h>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <vector>

namespace Zeta {

Player::Player() :
		Lifeform(), camera(nullptr), targetIndicator(nullptr), xp(0), xpToNextLevel(
				1) {
}

void Player::update(Float elapsedTime) {
	Lifeform::update(elapsedTime);
}

Player::Player(const std::string& classFile, Float x, Float y) :
		Lifeform(classFile, x, y), camera(
				&WorldManager::getInstance().getView()), targetIndicator(
				nullptr), xp(0), xpToNextLevel(1) {
}

void Player::setView(View& camera) {
	this->camera = &camera;
}

Player::~Player() {

}

void Player::teleportToCordinates(Float x, Float y) {
	//resetShapes();
	setPosition(x, y);
	camera->setPosition(x - (camera->getWidth() >> 1),
			y - (camera->getHeight() >> 1));
}

void Player::moveToWorldPosition(Float x, Float y) {
	Float tx = camera->getX() + x, ty = camera->getY() + y;
	moveToPosition(tx, ty);
	if (targetIndicator != nullptr) {
		targetIndicator->setPosition(tx, ty);
		targetIndicator->show();
	}
}

void Player::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void Player::setXp(Float value) {
	xp = value;
	if (xp >= xpToNextLevel) {
		levelUp();
	}
}

void Player::offsetXp(Float value) {
	xp += value;
	if (xp >= xpToNextLevel) {
		levelUp();
	}
}

void Player::setXpToNextLevel(Float value) {
	xpToNextLevel = value;
	if (xp >= xpToNextLevel) {
		levelUp();
	}
}

void Player::updateMovement(Float elapsedTime) {
	if (state.getAction() == LifeformState::Action::Moving) {
		Float speed = attributes["Speed"].getValue() * elapsedTime;
		if (position.getDistance(targetPosition) <= (speed + 0.1f)) {
			setIdleState();
			if (targetIndicator != nullptr) {
				targetIndicator->hide();
			}
		} else {

			Float off_x = direction.getX() * speed;
			Float off_y = direction.getY() * speed;
			Map& curMap = WorldManager::getInstance().getCurrentMap();

			bool moving = true;

			{
				Rectangle rect = bounding;

				rect.offsetPosition(off_x, 0);

				if (curMap.isRectangleColliding(rect, this,
						off_x > 0 ?
								Rectangle::Surface::Right :
								Rectangle::Surface::Left)) {
					off_x = 0;
					float dy = targetPosition.getY()
							- (position.getY() + off_y);
					if (std::abs(dy) < (off_y + 0.1f)) {
						moving = false;
					}
				}
			}
			{

				Rectangle rect = bounding;

				rect.offsetPosition(0, off_y);

				if (curMap.isRectangleColliding(rect, this,
						off_y > 0 ?
								Rectangle::Surface::Bottom :
								Rectangle::Surface::Top)) {
					off_y = 0;
					float dx = targetPosition.getX()
							- (position.getX() + off_x);
					if (std::abs(dx) < (off_x + 0.1f)) {
						moving = false;
					}
				}
			}

			if (moving && (off_x != 0 || off_y != 0)) {
				offsetPosition(off_x, off_y);
				camera->offsetPosition(off_x, off_y);

				if (off_x == 0 || off_y == 0) {
					calculateDirection();
					setMovingState();
				}
			} else {
				setIdleState();
				if (targetIndicator != nullptr) {
					targetIndicator->hide();
				}
			}

		}
	}
}

void Player::setTargetIndicator(const std::string& childName) {
	auto itr = childs.find(childName);
	if (itr != childs.end()) {
		targetIndicator = itr->second;
		targetIndicator->getAnimationHandler().getMainAnimationPlayer().play();
	}
}

void Player::targetLifeformPosition(Float x, Float y) {

	auto &mpMgr = WorldManager::getInstance();
	if (mpMgr.isVisible()) {
		Object *result = mpMgr.getCurrentMap().getObjectAtPosition(
				camera->getX() + x, camera->getY() + y, this);
		if (result != nullptr) {
			ClickHandler handler(this);
			result->accept(handler);
			result->onClick(this);
		} else {
			target = nullptr;
		}
	}
}

void Player::ClickHandler::handle(Lifeform& obj) {
	plyr->target = &obj;
	plyr->target->setDirty();
	plyr->dirty = true;
//	WorldEvent event;
//	event.setAsInteractEvent(plyr, &obj);
//	event.broadcast();
}

void Player::setLevelUpCallback(lua_Object func) {
	try {
		onLevelUp.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"Player was passed an invalid function for \"onlevelUp\":  is not a function",
				Logger::MessageType::LuaError);
	}
}

void Player::levelUp() {
	level += 1;
	LuaNumber num(level);
	onLevelUp( { &num });
}

void Player::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Player");
}

} /* namespace Zeta */
