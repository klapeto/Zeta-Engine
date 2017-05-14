/*
 * SpriteSheet.cpp
 *
 *  Created on: 8 Ιαν 2014
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

#include <Zeta/Core/ResourceClasses/Bitmap.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/ResourceClasses/SpriteSheet.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

namespace Zeta {

SpriteSheet::SpriteSheet(const std::string& path) :
		Resource(path), image(nullptr) {
	// Get The ResourceContaier Instance
	auto& resources = System::getInstance().getResourcesManager();

	// Setup the parser
	xmlpp::DomParser parser;

	try {
		File spriteFile(path);
		// Parse the data the File has
		parser.parse_memory_raw((const unsigned char*) spriteFile.getData(),
				spriteFile.getSize());
		// Validate the data
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::Sprites).validate(
				parser.get_document());
	} catch (const std::exception &e) {
		// Na Mpainei stin thesi tou Empty Spritesheet
		throw Exception(path, e.what());
	}

	// If Excecution comes here then File is ok to Iterate through

	// Get the <img ...> node
	xmlpp::Element *node = parser.get_document()->get_root_node();

	// Ask for the File the node name says
	image = &resources.getBitmap(
			StringOperations::translateUnixPath(path,
					node->get_attribute_value("name")));

	// Handle recursively all nodes
	// TODO: Maybe there are more than one root <dir>??
	handleNode("",
			static_cast<xmlpp::Element*>(node->get_first_child("definitions")->get_first_child(
					"dir")));
}

SpriteSheet::SpriteSheet() :
		Resource("null SpriteSheet"), image(
				&System::getInstance().getResourcesManager().getNullBitmap()) {
	// This constructor is only called by RESCON to Generate nullSpriteSheet

}

SpriteSheet::~SpriteSheet() {
	// Release the Image we got, if any
	if (image != nullptr) {
		ResourceContext* resources =
				&System::getInstance().getResourcesManager();
		if (resources != nullptr) {
			for (auto spr : sprites) {
				image->eraseSubBitmap(*spr.second);
			}
			resources->releaseResource(*image);
		}
	}
}

const Bitmap& SpriteSheet::getSprite(const std::string& path) const {
	// Search for the path in the u_map
	auto itr = sprites.find(path);
	if (itr != sprites.end()) {
		// If found, return it
		return *itr->second;
	} else {
		// If not Found, return the NullBitmap
		return System::getInstance().getResourcesManager().getNullBitmap();
	}
}

void SpriteSheet::handleNode(const std::string& curName,
		xmlpp::Element* curNode) {

	// For all the <spr... /> Nodes that exist in this <dir>
	for (xmlpp::Element* nd =
			static_cast<xmlpp::Element*>(curNode->get_first_child("spr"));
			nd != nullptr;
			nd = static_cast<xmlpp::Element*>(nd->get_next_sibling())) {

		// Create a new subbitmap with the attributes the <spr> defines
		// The key name is full path so far + the <spr> "name" attribute
		sprites[curName + "/" + nd->get_attribute_value("name")] =
				&image->createSubBitmap(
						strtol(nd->get_attribute_value("x").c_str(), nullptr,
								0),
						strtol(nd->get_attribute_value("y").c_str(), nullptr,
								0),
						strtol(nd->get_attribute_value("w").c_str(), nullptr,
								0),
						strtol(nd->get_attribute_value("h").c_str(), nullptr,
								0));
	}

	// For all the <spr... /> Nodes that exist in this <dir>
	for (xmlpp::Element* nd =
			static_cast<xmlpp::Element*>(curNode->get_first_child("dir"));
			nd != nullptr;
			nd = static_cast<xmlpp::Element*>(nd->get_next_sibling())) {

		// Call the same function for this <dir> and with the new name
		handleNode(curName + "/" + nd->get_attribute_value("name"), nd);
	}
}

} /* namespace Zeta */
