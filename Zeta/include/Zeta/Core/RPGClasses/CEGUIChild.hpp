/*
 * CEGUIChild.hpp
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

#ifndef ZETA_CORE_RPGCLASSES_CEGUICHILD_HPP_
#define ZETA_CORE_RPGCLASSES_CEGUICHILD_HPP_

#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace CEGUI {
class Window;
}  // namespace CEGUI

namespace Zeta {

class CEGUIChild: public ChildObject {
public:
	void setOffesets(Float offX, Float offY) {
		this->offX = offX;
		this->offY = offY;
	}

	bool isDestroy() const {
		return destroy;
	}

	void setDestroy(bool destroy) {
		this->destroy = destroy;
	}

	Float getOffsetX() const {
		return offX;
	}

	void setOffsetX(Float offX) {
		this->offX = offX;
	}

	Float getOffsetY() const {
		return offY;
	}

	void setOffsetY(Float offY) {
		this->offY = offY;
	}

	CEGUI::Window* getWindow() const {
		return window;
	}

	void setWindow(CEGUI::Window* window) {
		this->window = window;
	}

	void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	void onHide();
	void onShow();

	void setPosition(Float x, Float y);
	void offsetPosition(Float dx, Float dy);
	CEGUIChild(CEGUI::Window* window, bool destroy = false);
	~CEGUIChild();
private:
	CEGUI::Window *window;
	Float offX;
	Float offY;
	bool destroy;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RPGCLASSES_CEGUICHILD_HPP_ */
