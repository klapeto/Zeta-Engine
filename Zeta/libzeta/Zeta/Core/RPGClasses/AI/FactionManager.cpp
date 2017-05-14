/*
 * FactionManager.cpp
 *
 *  Created on: 2 Οκτ 2014
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
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/RPGClasses/AI/FactionManager.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <utility>

namespace Zeta {

const Faction& FactionManager::getFaction(const std::string& name) const {
	auto itr = factions.find(name);
	if (itr != factions.end()) {
		return itr->second;
	} else {
		return NullReference<Faction>::getNull();
	}

}

void FactionManager::parseFactionFile(const std::string& path) {

	xmlpp::DomParser parser;
	try {
		File fp(path);
		parser.parse_memory_raw(
				reinterpret_cast<const unsigned char*>(fp.getData()),
				fp.getSize());
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::Faction).validate(
				parser.get_document());
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During parsing Factions File: " + path + " Reason: "
						+ ex.reason());
		return;
	} catch (std::exception& ex) {
		Logger::getInstance().write(
				"During parsing Factions File: " + path + " Reason: "
						+ std::string(ex.what()));
		return;
	}

	xmlpp::Element* root = parser.get_document()->get_root_node();

	xmlpp::NodeSet nodes = root->find("//Faction");

	for (auto node : nodes) {
		xmlpp::Element* factNode = static_cast<xmlpp::Element*>(node);
		std::string name = factNode->get_attribute_value("name");
		Faction& fac = factions[name];
		fac.setName(name);
		xmlpp::NodeSet hostiles = factNode->find("./Hostile");
		for (auto hostile : hostiles) {
			xmlpp::Element* hostileNode = static_cast<xmlpp::Element*>(hostile);
			fac.setHostile(hostileNode->get_attribute_value("name"));
		}
	}
}

} /* namespace Zeta */

