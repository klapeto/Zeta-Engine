/*
 * TeleportField.cpp
 *
 *  Created on: 6 Μαϊ 2014
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

#include <Zeta/Core/MapClasses/TeleportField.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <lua.hpp>
#include <string>

namespace Zeta {

TeleportField::TeleportField(const std::string& targetMap, Float x, Float y,
		int width, int height) :
		Object(x, y, width, height), targetX(0), targetY(0) {
	name = targetMap;
}

void TeleportField::onCollidedWith(Object* other) {
	CollisionHandler handler(*this);
	other->accept(handler);
}

TeleportField::~TeleportField() {

}

void Zeta::TeleportField::CollisionHandler::handle(Player& obj) {
	WorldManager::getInstance().changeMapWithCallback(caller.name);
	obj.teleportToCordinates(caller.targetX, caller.targetY);
}

} /* namespace Zeta */
