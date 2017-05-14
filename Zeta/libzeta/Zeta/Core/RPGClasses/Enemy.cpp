/*
 * Enemy.cpp
 *
 *  Created on: 16 Ιουλ 2014
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

#include <Zeta/Core/RPGClasses/AI/WanderingMovement.hpp>
#include <Zeta/Core/RPGClasses/Enemy.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <tolua++.h>

namespace Zeta {

Enemy::Enemy(const std::string& lifeClass, Float x, Float y, Float respawnTime,
		Float vanishTime) :
		Lifeform(lifeClass, x, y), spawnPosition(x, y), respawnTime(
				respawnTime), respawnCounter(0.0f), vanishTime(vanishTime), vanishCounter(
				0.0f) {
	if (this->respawnTime < this->vanishTime) {
		this->respawnTime = this->vanishTime;
	}
	setState(rand() % 4);
	setIdleState();
	visible = false;
}

Enemy::Enemy(const LifeformClass& lifeClass, Float x, Float y,
		Float respawnTime, Float vanishTime) :
		Lifeform(lifeClass, x, y), spawnPosition(x, y), respawnTime(
				respawnTime), respawnCounter(0.0f), vanishTime(vanishTime), vanishCounter(
				0.0f) {
	if (this->respawnTime < this->vanishTime) {
		this->respawnTime = this->vanishTime;
	}
	setState(rand() % 4);
	setIdleState();
	visible = false;
}

void Enemy::update(Float elapsedTime) {
	Lifeform::update(elapsedTime);
	if (!isAlive()) {
		if (visible) {
			vanishCounter -= elapsedTime;
			if (vanishCounter <= 0) {
				hide();
			}
		}
		respawnCounter -= elapsedTime;
		if (respawnCounter <= 0) {
			respawn();
		}
	}
}

void Enemy::die() {
	Lifeform::die();
	respawnCounter = respawnTime;
	vanishCounter = vanishTime;

}

Enemy::~Enemy() {
}

void Enemy::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Enemy");
}

void Enemy::respawn() {
	teleportToCordinates(spawnPosition.getX(), spawnPosition.getY());
	collideAble = true;
	triggersCollisionEvents = true;
	resurect();
	show();
}

} /* namespace Zeta */
