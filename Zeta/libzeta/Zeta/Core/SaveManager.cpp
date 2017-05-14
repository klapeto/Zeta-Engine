/*
 * SaveManager.cpp
 *
 *  Created on: 28 Απρ 2014
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
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SaveManager.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <tolua++.h>
#include <cstdlib>
#include <exception>
#include <utility>
#include <vector>

namespace Zeta {

SaveManager::SaveManager() :
		filename("DefaultSaveFile.sav") {

}

void SaveManager::setFile(const std::string& path) {
	filename = path;
}

void SaveManager::save() {
	xmlpp::Element *root = parser.get_document()->create_root_node("SaveGame");
	savePlayer(root->add_child("Player"));
	saveMap(root->add_child("Map"));
	parser.get_document()->write_to_file(filename);
}

void SaveManager::load() {
	try {
		parser.parse_file(filename);

	} catch (std::exception &ex) {
		Logger::getInstance().write(
				"While Parsing the Save File: " + filename + " Reason:"
						+ ex.what(), Logger::MessageType::LuaError);
		return;
	}
	auto root = parser.get_document()->get_root_node();
	retrievePlayer(static_cast<xmlpp::Element*>(root->find("./Player")[0]));
	retrieveMap(static_cast<xmlpp::Element*>(root->find("./Map")[0]));
}

void SaveManager::retrievePlayer(xmlpp::Element* node) {
//	Player& plyr = WorldManager::getInstance().getPlayer();
//	auto& resCon = System::getInstance().getResourcesManager();
//	plyr.hardReset();
//	plyr.name = node->get_attribute_value("name");
//	plyr.level = strtol(node->get_attribute_value("level").c_str(), nullptr, 0);
//	plyr.xp = strtoul(node->get_attribute_value("xp").c_str(), nullptr, 0);
//	xmlpp::Element* nd = static_cast<xmlpp::Element*>(node->find(
//			"./AnimationClass")[0]);
//	plyr.setAnimationClass(nd->get_attribute_value("file"));
//	nd = static_cast<xmlpp::Element*>(node->find("./Position")[0]);
//	plyr.teleportToCordinates(
//			strtof(nd->get_attribute_value("x").c_str(), nullptr),
//			strtof(nd->get_attribute_value("y").c_str(), nullptr));
//	auto ndSet = node->find("./Abilities/Ability");
//
//	for (auto ab_nd : ndSet) {
//		xmlpp::Element *ability = static_cast<xmlpp::Element*>(ab_nd);
//		const AbilityClass &cls = resCon.getAbilityClass(
//				ability->get_attribute_value("file"));
//		plyr.abilities[cls.getAbilityName()] = cls.getNewAbility(&plyr,
//				strtol(ability->get_attribute_value("level").c_str(), nullptr,
//						0));
//	}
//
//	ndSet = node->find("./Attributes/Attribute");
//
//	for (auto at_nd : ndSet) {
//		xmlpp::Element *attribute = static_cast<xmlpp::Element*>(at_nd);
//		plyr.attributes[attribute->get_attribute_value("name")] =
//				static_cast<ZAttributeValue>(strtof(
//						attribute->get_attribute_value("baseValue").c_str(),
//						nullptr));
//	}

}

void SaveManager::retrieveMap(xmlpp::Element* node) {
	WorldManager::getInstance().changeMapWithCallback(
			node->get_attribute_value("filename").c_str());
}

void SaveManager::savePlayer(xmlpp::Element* node) {
//	Player& plyr = WorldManager::getInstance().getPlayer();
//	node->set_attribute("name", plyr.name);
//	node->set_attribute("level", std::to_string(plyr.level));
//	xmlpp::Element *child = node->add_child("Position");
//	child->set_attribute("x", std::to_string(plyr.position.getX()));
//	child->set_attribute("y", std::to_string(plyr.position.getY()));
//	child = node->add_child("AnimationClass");
//	child->set_attribute("file",
//			plyr.animHandler.getAnimationClass().getName());
//	child = node->add_child("Abilities");
//	for (auto ab : plyr.abilities) {
//		xmlpp::Element *abNd = child->add_child("Ability");
//		abNd->set_attribute("file", ab.second->getAbilityClass().getName());
//		abNd->set_attribute("level", std::to_string(ab.second->getLevel()));
//	}
//	child = node->add_child("Attributes");
//	for (auto at : plyr.attributes) {
//		xmlpp::Element *atNd = child->add_child("Attribute");
//		atNd->set_attribute("name", at.first);
//		atNd->set_attribute("baseValue",
//				std::to_string(at.second.getBaseValue()));
//	}
}

void SaveManager::saveMap(xmlpp::Element* node) {
	node->set_attribute("filename",
			WorldManager::getInstance().getCurrentMap().getName());
}

void SaveManager::write(const std::string& name, const std::string& value) {
	auto node = parser.get_document()->get_root_node()->add_child("Variable");
	node->set_attribute("name", name);
	node->set_attribute("value", value);
}

std::string SaveManager::read(const std::string& name) const {
	auto node = parser.get_document()->get_root_node()->find(
			"./Variable[@name=\"" + name + "\"]");
	if (node.size() > 0) {
		return static_cast<xmlpp::Element*>(node[0])->get_attribute_value(
				"value");
	} else {
		return "";
	}
}

xmlpp::Element* SaveManager::getSaveFileRoot() {
	return parser.get_document()->get_root_node();
}

void SaveManager::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::SaveManager");
}

SaveManager::~SaveManager() {

}

} /* namespace Zeta */
