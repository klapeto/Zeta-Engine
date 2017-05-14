/*
 * AnimationClass.cpp
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

#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <libxml++/validators/schemavalidator.h>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

namespace Zeta {

AnimationClass::AnimationClass() :
		Resource("null AnimationClass"), nullAnimation(
				&NullReference<Animation>::getNull()), has_Shadow(false) {
	// fill the Primitives with NullAnimations
	primAnimations.resize(LifeformState::maxDirectionValue,
			LifeformState::maxActionValue);
	for (auto& anim : primAnimations.getInternal()) {
		anim = nullAnimation;
	}
}

AnimationClass::AnimationClass(const std::string& path) :
		Resource(path), has_Shadow(false) {

	// Get the NullAnimation
	nullAnimation = &NullReference<Animation>::getNull();

	// Fill all the Primitives with NullAnimations
	primAnimations.resize(LifeformState::maxDirectionValue,
			LifeformState::maxActionValue);
	for (auto& anim : primAnimations.getInternal()) {
		anim = nullAnimation;
	}

	// Get the RESCON
	auto& resources = System::getInstance().getResourcesManager();

	// Generate a xml Parser
	xmlpp::DomParser parser;

	// try parse and validate
	try {
		File fp(path);

		parser.parse_memory_raw((unsigned char*) fp.getData(), fp.getSize());
		XMLSchemaValidator::getInstance().getValidator(
				XMLSchemaValidator::ResourceValidator::AnimationClass).validate(
				parser.get_document());
	} catch (std::exception &ex) {
		// if something bad happened (Bad data,0 invalid data, or no file), let RESCON handle this
		throw Exception(path, ex.what());
	}

	// From there, file is OK to iterate through

	// get the Bounding for this class
	xmlpp::NodeSet results = parser.get_document()->get_root_node()->find(
			"//Bounding/Rectangle");

	// Cast to Element to get the attributes
	xmlpp::Element *node = static_cast<xmlpp::Element*>(results[0]);

	// Assign the BoundBox with the Data
	boundBox = std::move(
			Rectangle(
					strtol(node->get_attribute_value("x").c_str(), nullptr, 0),
					strtol(node->get_attribute_value("y").c_str(), nullptr, 0),
					strtol(node->get_attribute_value("width").c_str(), nullptr,
							0),
					strtol(node->get_attribute_value("height").c_str(), nullptr,
							0)));

	// Set the outline color
	boundBox.setOutlineColor(0x000000BA);

	// Get the TargetArea Rectangle node
	results = parser.get_document()->get_root_node()->find(
			"//TargetArea/Rectangle");

	node = static_cast<xmlpp::Element*>(results[0]);

	// Create the TargetBox from the data
	targetBox = std::move(
			Rectangle(
					strtol(node->get_attribute_value("x").c_str(), nullptr, 0),
					strtol(node->get_attribute_value("y").c_str(), nullptr, 0),
					strtol(node->get_attribute_value("width").c_str(), nullptr,
							0),
					strtol(node->get_attribute_value("height").c_str(), nullptr,
							0)));

	// Get the Shadow Ellipsis node
	results = parser.get_document()->get_root_node()->find("//Shadow/Ellipsis");

	// Check if it does exist
	if (results.size() > 0) {
		node = static_cast<xmlpp::Element*>(results[0]);

		// Create he ellipsis
		shadow = std::move(
				Ellipsis(
						strtol(node->get_attribute_value("centreX").c_str(),
								nullptr, 0),
						strtol(node->get_attribute_value("centreY").c_str(),
								nullptr, 0),
						strtol(node->get_attribute_value("radiusX").c_str(),
								nullptr, 0),
						strtol(node->get_attribute_value("radiusY").c_str(),
								nullptr, 0)));
		// Set the flag to let the Lifeform that
		// it should render the Shadow Ellipsis
		has_Shadow = true;
	}

	shadow.setBackgroundColor(0x000000BA);
	shadow.setBackgroundEnabled(true);
	shadow.setOutlineEnabled(false);

	// Get all the <Action> elements
	results = parser.get_document()->get_root_node()->find("//Action");

	// For all the Actions
	for (auto action : results) {
		// Cast to Element to get the attributes
		xmlpp::Element *nd = static_cast<xmlpp::Element*>(action);

		// Get the Action Name as the Start of the Dir
		std::string path = nd->get_attribute_value("name") + "/";

		// Get all the Directions
		xmlpp::NodeSet childs = nd->find("./*");

		// for all the directions
		for (auto child : childs) {
			// Cast to Element to get the attributes
			xmlpp::Element *tmp = static_cast<xmlpp::Element*>(child);

			animations[std::string(path + tmp->get_name())] =
					&resources.getAnimationPack(
							tmp->get_attribute_value("file")).getAnimation(
							tmp->get_attribute_value("animation"));
			// Assign to the container the Animation from the referenced Animation Pack
			// The key is: ActionName/Direction
			//animations[std::string(path + tmp->get_name())] =
			//		&resources.getResource<AnimationPack>(
			//				tmp->get_attribute_value("file")).getAnimation(
			//				tmp->get_attribute_value("animation"));
		}
	}

	// Retrieve the Primitives, if exist
	retrivePrimitives();

}

const Animation& AnimationClass::getAnimation(const std::string& name,
		LifeformState::CombinedState fallbackAnimation) const {
	// Search the name provided
	auto itr = animations.find(name);
	if (itr != animations.end()) {
		// If we find it, then return the Animation it has
		return *itr->second;
	} else {
		// If it does not exist return the fallback animation
		return getAnimation(fallbackAnimation);
	}
}

const Animation& AnimationClass::getAnimation(
		LifeformState::CombinedState state) const {
	// Check if the state is valid
	if ((state & 0xF) <= LifeformState::maxDirectionValue && (state & 0xF) > 0
			&& (state >> 4) <= LifeformState::maxActionValue
			&& (state >> 4) > 0) {
		// If it is valid, then return the animation from the table it points
		return *primAnimations((state & 0xF) - 1, (state >> 4) - 1);
	}
	return *nullAnimation;
}

AnimationClass::~AnimationClass() {
	ResourceContext* resources = &System::getInstance().getResourcesManager();
	if (resources != nullptr) {
		// Release every referenced animation
		for (auto anim : animations) {
			resources->releaseResource(anim.second->getAnimationPack());
		}
	}
}

void AnimationClass::retrivePrimitives() {
// Get the Primitives for Movement

	auto itr = animations.find("__Movement__/Up");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Up - 1),
				(LifeformState::Action::Moving >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Movement__/Down");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Down - 1),
				(LifeformState::Action::Moving >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Movement__/Right");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Right - 1),
				(LifeformState::Action::Moving >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Movement__/Left");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Left - 1),
				(LifeformState::Action::Moving >> 4) - 1) = itr->second;
	}

// Get the primitives for Idle
	itr = animations.find("__Idle__/Up");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Up - 1),
				(LifeformState::Action::Idle >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Idle__/Down");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Down - 1),
				(LifeformState::Action::Idle >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Idle__/Right");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Right - 1),
				(LifeformState::Action::Idle >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Idle__/Left");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Left - 1),
				(LifeformState::Action::Idle >> 4) - 1) = itr->second;
	}

// Get the primitives for Death
	itr = animations.find("__Death__/Up");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Up - 1),
				(LifeformState::Action::Dying >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Death__/Down");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Down - 1),
				(LifeformState::Action::Dying >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Death__/Right");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Right - 1),
				(LifeformState::Action::Dying >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Death__/Left");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Left - 1),
				(LifeformState::Action::Dying >> 4) - 1) = itr->second;
	}

// Get the primitives for Dead
	itr = animations.find("__Dead__/Up");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Up - 1),
				(LifeformState::Action::Dead >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Dead__/Down");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Down - 1),
				(LifeformState::Action::Dead >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Dead__/Right");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Right - 1),
				(LifeformState::Action::Dead >> 4) - 1) = itr->second;
	}
	itr = animations.find("__Dead__/Left");
	if (itr != animations.end()) {
		primAnimations((LifeformState::Direction::Left - 1),
				(LifeformState::Action::Dead >> 4) - 1) = itr->second;
	}
}

} /* namespace Zeta */
