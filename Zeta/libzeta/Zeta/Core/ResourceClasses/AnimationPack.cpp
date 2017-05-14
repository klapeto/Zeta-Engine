/*
 * AnimationPack.cpp
 *
 *  Created on: 25 Φεβ 2014
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

#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceContext.hpp>
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
#include <utility>

namespace Zeta {

AnimationPack::AnimationPack() :
		Resource("null AnimationPack"), spriteSheet(
				&NullReference<SpriteSheet>::getNull()) {

}

AnimationPack::AnimationPack(const std::string& path) :
		Resource(path) {
	// Ask the RESCON for the file the path says.
	auto& resMan = System::getInstance().getResourcesManager();
	xmlpp::DomParser parser;

	try {
		File animFile(path);

		// Parse the file
		parser.parse_memory_raw((unsigned char*) (animFile.getData()),
				animFile.getSize());
		// Validate the XML through the pre-parsed XSD Schema
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::Animations).validate(
				parser.get_document());
	} catch (const std::exception &ex) {
		// If execution comes here, then maybe file is corrupt or is not valid
		throw Exception(path, ex.what());
	}

	xmlpp::Element *root = parser.get_document()->get_root_node();

	// Get the Referenced SpriteSheet from RESCON
	spriteSheet = &resMan.getSpriteSheet(
			StringOperations::translateUnixPath(path,
					root->get_attribute_value("spriteSheet").c_str()));
	// Execute the XPATH Query to find all <anims>
	xmlpp::NodeSet anims = root->find("//anim");

	// For all the anims
	for (auto node : anims) {
		animations[static_cast<xmlpp::Element*>(node)->get_attribute_value(
				"name").c_str()].set(node, *this);
	}
}

const Animation& AnimationPack::getAnimation(const std::string& name) const {
	// Find the animation with that name
	auto itr = animations.find(name);
	if (itr != animations.end()) {
		// if exists in the pack, return it
		return itr->second;
	} else {
		// if it does not exist in the pack return the NullAnimation
		return NullReference<Animation>::getNull();
	}
}

AnimationPack::~AnimationPack() {
	// Finaly, release the Spritesheet
	ResourceContext* resources = &System::getInstance().getResourcesManager();
	if (resources != nullptr) {
		resources->releaseResource(*spriteSheet);
	}
}

std::vector<std::string> AnimationPack::listAnimationNames() const {
	std::vector<std::string> list;
	for (auto& anim : animations) {
		list.push_back(anim.first);
	}
	return list;
}

} /* namespace Zeta */

