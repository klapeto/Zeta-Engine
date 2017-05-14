/*
 * CEGUIChild.cpp
 *
 *  Created on: 23 Οκτ 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#include <Zeta/Core/RPGClasses/CEGUIChild.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/View.hpp>
#include <CEGUI/Element.h>
#include <CEGUI/UDim.h>
#include <CEGUI/Vector.h>
#include <CEGUI/Window.h>

namespace Zeta {

CEGUIChild::CEGUIChild(CEGUI::Window* window, bool destroy) :
		ChildObject(), window(window), offX(0.0f), offY(0.0f), destroy(destroy) {
	toBeDeleted = false;
	Vector2 rend = this->getRenderPosition();
	window->setPosition(
			CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
					CEGUI::UDim(0.0f, rend.getY() + offY)));
}

void CEGUIChild::offsetPosition(Float dx, Float dy) {
	Object::offsetPosition(dx, dy);
	if (window != nullptr) {

		window->setPosition(
				CEGUI::UVector2(window->getXPosition() + CEGUI::UDim(0.0f, dx),
						window->getYPosition() + CEGUI::UDim(0.0f, dy)));
	}
}

void CEGUIChild::setPosition(Float x, Float y) {
	Object::setPosition(x, y);
	if (window != nullptr) {
		Vector2 rend = this->getRenderPosition();
		window->setPosition(
				CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
						CEGUI::UDim(0.0f, rend.getY() + offY)));
	}
}

void CEGUIChild::draw(Float x, Float y, Float rotation, Float scale) const {
	if (window != nullptr) {
		Vector2 rend = this->getRenderPosition();
		window->setPosition(
				CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
						CEGUI::UDim(0.0f, rend.getY() + offY)));
	}
}

void CEGUIChild::onHide() {
	if (window != nullptr) {
		window->hide();
	}
}

void CEGUIChild::onShow() {
	if (window != nullptr) {
		window->show();
	}
}

CEGUIChild::~CEGUIChild() {
	if (destroy) {
		if (window != nullptr) {
			window->getParent()->destroyChild(window);
		}
	}
}

} /* namespace Zeta */
