/*
 * Sprite.cpp
 *
 *  Created on: 1 Μαρ 2016
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

#include <Zeta/Core/AnimationClasses/Sprite.hpp>
#include <Zeta/Core/ResourceClasses/SpriteSheet.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <glibmm/ustring.h>
#include <libxml++/nodes/element.h>

namespace Zeta {

Sprite::Sprite() :
		image(&System::getInstance().getResourcesManager().getNullBitmap()), x(
				0), y(0), z(0), angle(0.0f), flip(Bitmap::FlipFlag::Normal) {

}

Sprite::Sprite(xmlpp::Node* node, const SpriteSheet& spriteSheet) :
		Sprite() {
	if (node != nullptr) {
		// Cast to Element to get the Attributes
		xmlpp::Element *spr = static_cast<xmlpp::Element*>(node);
		// Get the fields
		x = strtol(spr->get_attribute_value("x").c_str(), nullptr, 0);
		y = strtol(spr->get_attribute_value("y").c_str(), nullptr, 0);
		z = strtol(spr->get_attribute_value("z").c_str(), nullptr, 0);
		angle = strtof(spr->get_attribute_value("angle").c_str(), nullptr);

		// OR the return number of strtol so we can get the final flip Flag
		flip =
				static_cast<Bitmap::FlipFlag>((strtol(
						spr->get_attribute_value("flipH").c_str(), nullptr, 0)
						<< 1)
						| strtol(spr->get_attribute_value("flipV").c_str(),
								nullptr, 0));
		image = &spriteSheet.getSprite(
				spr->get_attribute_value("name").c_str());
	}
}

void Sprite::draw(Float x, Float y, Float rotation, Float scale) const {
	image->drawAtCentre(x + (this->x * scale), y + (this->y * scale),
			(angle * 0.0174532925f) + rotation, scale, flip);
}

} /* namespace Zeta */
