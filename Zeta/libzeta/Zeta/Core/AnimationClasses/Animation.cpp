/*
 * Animation.cpp
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
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <glibmm/ustring.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <algorithm>
#include <cstdlib>

namespace Zeta {

Animation::Animation() :
		parentPack(&NullReference<AnimationPack>::getNull()), loops(false) {
	// Add an Null Cell so the animation is playable
	cells.push_back(Cell());
}

Animation::Animation(xmlpp::Node *node, const AnimationPack &parent) :
		loops(false) {
	// Load the value
	set(node, parent);
}

Animation::~Animation() {

}

void Animation::set(xmlpp::Node* node, const AnimationPack& parent) {
	this->cells.clear();
	// node here points(if called properly) to an <anim... > tag of the animations File
	xmlpp::Element* anim = static_cast<xmlpp::Element*>(node);
	// Get the name of the Animation
	name = anim->get_attribute_value("name").c_str();

	// Get whether the animation loops
	if (strtol(anim->get_attribute_value("loops").c_str(), nullptr, 0) == 0) {
		loops = false;
	} else {
		loops = true;
	}

	// Get all the <cell> children
	xmlpp::NodeSet cells = anim->find("./cell");

	// For all the cells
	for (auto nd : cells) {
		// cast it to Element to gain access to its Attributes
		xmlpp::Element *cellNode = static_cast<xmlpp::Element*>(nd);

		// Create a new Cell with the stated delay the XML describes
		Cell tmpCell(
				strtol(cellNode->get_attribute_value("delay").c_str(), nullptr,
						0) / 100.0f);

		tmpCell.clearSprites();
		// Get all the <spr> children
		xmlpp::NodeSet sprites = cellNode->find("./spr");

		// For all the sprites
		for (auto spr : sprites) {
			tmpCell.addSprite(spr, parent.getSpriteSheet());
		}
		this->cells.push_back(std::move(tmpCell));
	}

	parentPack = &parent;
}

} /* namespace Zeta */
