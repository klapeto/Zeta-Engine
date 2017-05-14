/*
 * Player.hpp
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

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <unordered_set>
#include <string>

namespace Zeta {

class View;
class LuaEngine;
class Visitor;

class Player: public Lifeform {
public:

	void onShow() {

	}
	void onHide() {

	}
	void update(Float elapsedTime);
	void setView(View& camera);
	void teleportToCordinates(Float x, Float y);
	void targetLifeformPosition(Float x, Float y);
	void moveToWorldPosition(Float x, Float y);
	void setTargetIndicator(const std::string& childName);

	Float getXp() const {
		return xp;
	}

	void setXp(Float value);
	void offsetXp(Float value);
	void setXpToNextLevel(Float value);

	Float getXpToNextLevel() const {
		return xpToNextLevel;
	}

	void pushToLua(lua_State* lstate);
	void setLevelUpCallback(lua_Object func);
	void accept(Visitor& visitor);

	Player();
	Player(const std::string& classFile, Float x, Float y);
	virtual ~Player();
private:

	LuaFunctor onLevelUp;
	View *camera;
	ChildObject *targetIndicator;
	Float xp;
	Float xpToNextLevel;

	void updateMovement(Float elapsedTime);

	class ClickHandler: public Visitor {
	public:
		void handle(Lifeform& obj);

		ClickHandler(Player *plyr) :
				plyr(plyr) {

		}
	private:
		Player *plyr;
	};

	friend class SaveManager;

	void levelUp();
};

} /* namespace Zeta */

#endif /* PLAYER_HPP_ */
