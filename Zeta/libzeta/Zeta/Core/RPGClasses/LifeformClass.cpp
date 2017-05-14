/*
 * LifeformClass.cpp
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/RPGClasses/StickyObject.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <Zeta/Core/RPGClasses/AI/FactionManager.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/RPGClasses/AI/Behaviour.hpp>
#include <Zeta/Core/RPGClasses/AI/BehaviourClass.hpp>
#include <Zeta/Core/RPGClasses/AI/PassiveBehaviourClass.hpp>
#include <Zeta/Core/RPGClasses/AI/AggressiveBehaviourClass.hpp>
#include <Zeta/Core/RPGClasses/AI/WanderingMovementClass.hpp>
#include <Zeta/Core/RPGClasses/AI/IdleMovementClass.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <utility>
#include <chrono>
#include <vector>

namespace Zeta {

const std::string Stats::HP = "HP";
const std::string Stats::MaxHP = "MaxHP";
const std::string Stats::Mana = "Mana";
const std::string Stats::MaxMana = "MaxMana";

LifeformClass::LifeformClass() :
		Resource("null LifeformClass"), faction(
				&NullReference<Faction>::getNull()), genericAI(
				new AggressiveBehaviourClass(300, 600)), movementAI(
				new PassiveBehaviourClass), level(1) {

}

LifeformClass::LifeformClass(const std::string& path) :
		Resource(path), level(1) {
	auto& resources = System::getInstance().getResourcesManager();

	xmlpp::DomParser parser;

	try {
		File fp(path);

		parser.parse_memory_raw((unsigned char*) fp.getData(), fp.getSize());
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::LifeformClass).validate(
				parser.get_document());
	} catch (const std::exception &ex) {
		throw Exception(path, ex.what());
	}

	xmlpp::Element *root = parser.get_document()->get_root_node();

	lifeform_name = root->get_attribute_value("name");

	faction = &FactionManager::getInstance().getFaction(
			root->get_attribute_value("faction"));

	xmlpp::Element *node = static_cast<xmlpp::Element*>(root->find(
			"./AnimationClass")[0]);

	animClass = node->get_attribute_value("filename");

	{

		xmlpp::NodeSet nodes = root->find("./AI/General");
		if (nodes.size() > 0) {
			xmlpp::Element* general = static_cast<xmlpp::Element*>(nodes[0]);
			auto str = general->get_attribute_value("type");

			if (str == "Aggressive") {

				Float aggroRange = 300.0f;
				Float driftRange = 600.0f;

				auto aggro = general->find("./Setting[@name=\'aggroRange\']");

				if (aggro.size() > 0) {
					aggroRange =
							strtof(
									static_cast<xmlpp::Element*>(aggro[0])->get_attribute_value(
											"value").c_str(), nullptr);
				}

				aggro = general->find("./Setting[@name=\'driftRange\']");

				if (aggro.size() > 0) {
					driftRange =
							strtof(
									static_cast<xmlpp::Element*>(aggro[0])->get_attribute_value(
											"value").c_str(), nullptr);
				}

				if (aggroRange > driftRange) {
					aggroRange = 300.0f;
					driftRange = 600.0f;
				}

				genericAI = new AggressiveBehaviourClass(aggroRange,
						driftRange);
			} else {
				genericAI = new PassiveBehaviourClass;
			}
		} else {
			genericAI = new PassiveBehaviourClass;
		}

		nodes = root->find("./AI/Movement");
		if (nodes.size() > 0) {
			xmlpp::Element* general = static_cast<xmlpp::Element*>(nodes[0]);

			auto str = general->get_attribute_value("type");

			if (str == "Wandering") {
				auto minTimeSetting = general->find(
						"./Setting[@name=\'minWaitTime\']");
				auto maxTimeSetting = general->find(
						"./Setting[@name=\'maxWaitTime\']");
				auto maxDistanceSetting = general->find(
						"./Setting[@name=\'maxDistance\']");
				auto idleActionSetting = general->find(
						"./Setting[@name=\'IdleAction\']");

				if (minTimeSetting.size() > 0 && maxTimeSetting.size() > 0
						&& maxDistanceSetting.size() > 0) {
					movementAI =
							new WanderingMovementClass(
									strtof(
											static_cast<xmlpp::Element*>(minTimeSetting[0])->get_attribute_value(
													"value").c_str(), nullptr),
									strtof(
											static_cast<xmlpp::Element*>(maxTimeSetting[0])->get_attribute_value(
													"value").c_str(), nullptr),
									strtof(
											static_cast<xmlpp::Element*>(maxDistanceSetting[0])->get_attribute_value(
													"value").c_str(), nullptr),
									idleActionSetting.size() > 0 ?
											static_cast<xmlpp::Element*>(idleActionSetting[0])->get_attribute_value(
													"value") :
											"");
				} else {
					Logger::getInstance().write(
							"At Lifeform class: " + path
									+ " -> Invalid settings set for Wandering Movement. Reseting to defaults",
							Logger::MessageType::Warning);
					movementAI = new WanderingMovementClass(0.0f, 5.0f, 500.0f);
				}
			} else {
				movementAI = new IdleMovementClass;
			}
		} else {
			movementAI = new IdleMovementClass;
		}
	}

	node = static_cast<xmlpp::Element*>(root->find("./Stats")[0]);

	level = strtol(node->get_attribute_value("level").c_str(), nullptr, 0);

	levelizeStats();

	xmlpp::NodeSet nds = node->find("./Stat");
	for (auto nd : nds) {
		xmlpp::Element *stat = static_cast<xmlpp::Element*>(nd);
		float val = strtof(stat->get_attribute_value("value").c_str(), nullptr);
		stats[stat->get_attribute_value("name")].param(
				std::uniform_int_distribution<int>::param_type(val, val));

	}

	nds = node->find("./Levelize");

	for (auto nd : nds) {
		xmlpp::Element *lvlizeNd = static_cast<xmlpp::Element*>(nd);
		float multiplier = strtof(lvlizeNd->get_attribute_value("mul").c_str(),
				nullptr);
		int lowerBound = strtol(
				lvlizeNd->get_attribute_value("lowBound").c_str(), nullptr, 0);

		int upperBound = strtol(
				lvlizeNd->get_attribute_value("upBound").c_str(), nullptr, 0);

		xmlpp::NodeSet attrs = nd->find("./Stat");

		if (attrs.size() > 0) {
			int lowValue = std::abs((level + lowerBound));
			int upValue = std::abs((level + upperBound));
			if (lowValue >= upValue) {
				++upValue;
			}

			lowValue *= multiplier;
			upValue *= multiplier;

			for (auto st : attrs) {
				xmlpp::Element *stat = static_cast<xmlpp::Element*>(st);
				stats[stat->get_attribute_value("name")].param(
						std::uniform_int_distribution<int>::param_type(lowValue,
								upValue));
			}
		} else {
			levelizeStats(multiplier, lowerBound, upperBound);
			break;
		}

	}

	stats["HP"] = stats["MaxHP"];
	stats["Mana"] = stats["MaxMana"];

	nds = root->find("./Abilities/Ability");

	for (auto abilityNode : nds) {
		xmlpp::Element *ab = static_cast<xmlpp::Element*>(abilityNode);
		LifeformAbility lfAb;

		lfAb.abClass = ab->get_attribute_value("file");
		lfAb.level = strtol(ab->get_attribute_value("level").c_str(), nullptr,
				0);
		abilities[lfAb.abClass] = lfAb;
	}

	nds = root->find("./ChildObjects/Sticky");

	for (auto childNode : nds) {
		xmlpp::Element *ab = static_cast<xmlpp::Element*>(childNode);
		ChildParams params(ab->get_attribute_value("name"),
				ab->get_attribute_value("classPath"),
				ab->get_attribute_value("animName") + "/Up",
				strtol(ab->get_attribute_value("x").c_str(), nullptr, 0),
				strtol(ab->get_attribute_value("y").c_str(), nullptr, 0),
				ChildParams::ChildType::Sticky);
		childParameters.push_back(std::move(params));
	}

	nds = root->find("./ChildObjects/Static");

	for (auto childNode : nds) {
		xmlpp::Element *ab = static_cast<xmlpp::Element*>(childNode);
		ChildParams params(ab->get_attribute_value("name"),
				ab->get_attribute_value("classPath"),
				ab->get_attribute_value("animName") + "/Up",
				strtol(ab->get_attribute_value("x").c_str(), nullptr, 0),
				strtol(ab->get_attribute_value("y").c_str(), nullptr, 0),
				ChildParams::ChildType::Static);
		childParameters.push_back(std::move(params));
	}
}

void LifeformClass::levelizeStats(float levelMultiplier) {

	std::default_random_engine generator(
			std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> rnd(level * levelMultiplier,
			(level + 1) * levelMultiplier);
	stats["HP"] = rnd;
	stats["MaxHP"] = stats["HP"];
	stats["Mana"] = rnd;
	stats["MaxMana"] = stats["Mana"];
	stats["Speed"] = std::uniform_int_distribution<int>(200, 200);

}

void LifeformClass::getAbilities(Lifeform *owner) const {
	for (auto ab : abilities) {
		owner->addAbility(ab.second.abClass, ab.second.level);
	}
	for (auto ab : luaAbilities) {
		owner->addAbility(*ab.abClass, ab.level);
	}
}

void LifeformClass::getChildObjets(Lifeform *owner) const {
	for (auto& child : owner->childs) {
		delete child.second;
	}
	owner->childs.clear();
	for (auto& param : childParameters) {
		switch (param.getType()) {
		case ChildParams::ChildType::Sticky:
			owner->childs[param.getName()] = new StickyObject(param.getDx(),
					param.getDy(), owner, param.getName(),
					param.getAnimationClass(), param.getAnimationName());
			break;
		case ChildParams::ChildType::Static:
			owner->childs[param.getName()] = new ChildObject(param.getDx(),
					param.getDy(), owner, param.getName(),
					param.getAnimationClass(), param.getAnimationName());
			break;
		}
	}
}

Behaviour* LifeformClass::getGeneralBehaviour(Lifeform& owner) const {
	return genericAI->getNewBehaviour(owner);
}

Behaviour* LifeformClass::getMovementBehaviour(Lifeform& owner) const {
	return movementAI->getNewBehaviour(owner);
}

void LifeformClass::addAbility(const AbilityClass& abClass, int level) {
	LuaAbility lAb;
	lAb.abClass = &abClass;
	lAb.level = level;
	luaAbilities.push_back(std::move(lAb));
}

LifeformClass::~LifeformClass() {
	delete movementAI;
	delete genericAI;
}

void LifeformClass::getStats(ZMap<std::string, Attribute>& stats) const {
	std::default_random_engine generator(
			std::chrono::system_clock::now().time_since_epoch().count());
	for (auto stat : this->stats) {
		stats[stat.first] = stat.second(generator);
	}
	stats["MaxHP"] = stats["HP"];
	stats["MaxMana"] = stats["Mana"];
}

void LifeformClass::levelizeStats(float multiplier, int lowerBound,
		int upperBound) {
	int lowValue = std::abs((level + lowerBound));
	int upValue = std::abs((level + upperBound));
	if (lowValue >= upValue) {
		++upValue;
	}

	lowValue *= multiplier;
	upValue *= multiplier;
	for (auto &stat : stats) {
		stat.second.param(
				std::uniform_int_distribution<int>::param_type(lowValue,
						upValue));
	}
	stats["Speed"].param(
			std::uniform_int_distribution<int>::param_type(200, 200));
}

void LifeformClass::setTable(lua_Object table) {
	this->table.setFromStack(LuaEngine::getInstance().getState(), table);
}

void LifeformClass::setOnClick(lua_Object func) {
	this->onClickF.setFromStack(LuaEngine::getInstance().getState(), func);
}

void LifeformClass::setOnCollision(lua_Object func) {
	this->onClickF.setFromStack(LuaEngine::getInstance().getState(), func);
}

} /* namespace Zeta */
