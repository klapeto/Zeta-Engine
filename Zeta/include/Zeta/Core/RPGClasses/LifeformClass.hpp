/*
 * LifeformClass.hpp
 *
 *  Created on: 7 Ιαν 2014
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

#ifndef LIFEFORMCLASS_HPP_
#define LIFEFORMCLASS_HPP_

#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <string>
#include <random>
#include <Zeta/Core/ZSmallMap.hpp>
#include <Zeta/Core/ZMap.hpp>

namespace Zeta {

struct Stats {
	static const std::string HP;
	static const std::string MaxHP;
	static const std::string Mana;
	static const std::string MaxMana;
	static const std::string Speed;
};

class AnimationClass;
class Ability;
class AbilityClass;
class Lifeform;
class Object;
class ChildObject;
class Faction;
class Behaviour;
class BehaviourClass;

class LifeformClass: public Resource {
public:

	const std::string& getLifeformName() const {
		return lifeform_name;
	}

	void getStats(ZMap<std::string, Attribute>& stats) const;

	void getAbilities(Lifeform *owner) const;

	void getChildObjets(Lifeform *owner) const;

	const std::string& getAnimationClassName() const {
		return animClass;
	}

	int getLevel() const {
		return level;
	}

	const LuaTable& getTable() const {
		return table;
	}

	const LuaFunctor& getOnClick() const {
		return onClickF;
	}

	const LuaFunctor& getOnCollision() const {
		return onCollisionF;
	}

	const Faction& getFaction() const {
		return *faction;
	}

	void setTable(lua_Object table);
	void setOnClick(lua_Object func);
	void setOnCollision(lua_Object func);

	Behaviour* getGeneralBehaviour(Lifeform& owner) const;
	Behaviour* getMovementBehaviour(Lifeform& owner) const;

	void levelizeStats(float levelMultiplier = 1.0f);
	void levelizeStats(float multiplier, int lowerBound, int upperBound);

	void addAbility(const AbilityClass& abClass, int level);

	LifeformClass();
	LifeformClass(const std::string& path);
	virtual ~LifeformClass();
private:

	typedef struct {
		std::string abClass;
		int level;
	} LifeformAbility;

	typedef struct {
		const AbilityClass* abClass;
		int level;
	} LuaAbility;

	class ChildParams {
	public:

		enum class ChildType {
			Sticky, Static
		};

		const std::string& getName() const {
			return name;
		}
		const std::string& getAnimationClass() const {
			return animationClass;
		}
		const std::string& getAnimationName() const {
			return animationName;
		}
		Float getDx() const {
			return dx;
		}
		Float getDy() const {
			return dy;
		}

		ChildType getType() const {
			return type;
		}
		ChildParams(const std::string& name, const std::string& animClass,
				const std::string& animName, Float dx, Float dy,
				ChildType type) :
				name(name), animationClass(animClass), animationName(animName), type(
						type), dx(dx), dy(dy) {

		}
	private:
		std::string name;
		std::string animationClass;
		std::string animationName;
		ChildType type;
		Float dx;
		Float dy;
	};

	mutable ZSmallMap<std::string, LifeformAbility> abilities;
	mutable std::vector<LuaAbility> luaAbilities;
	mutable ZSmallMap<std::string, std::uniform_int_distribution<int>> stats;
	std::vector<ChildParams> childParameters;
	std::string lifeform_name;
	std::string animClass;

	LuaTable table;
	LuaFunctor onCollisionF;
	LuaFunctor onClickF;
	const Faction* faction;
	BehaviourClass* genericAI;
	BehaviourClass* movementAI;
	int level;

};

} /* namespace Zeta */

#endif /* LIFEFORMCLASS_HPP_ */
