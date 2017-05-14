/*
 * SpriteSheet.hpp
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

#ifndef SPRITESHEET_HPP_
#define SPRITESHEET_HPP_

#include <Zeta/Core/ZSmallMap.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>

namespace xmlpp {
class Element;
} /* namespace xmlpp */


namespace Zeta {

class Bitmap;

/**
 * SpriteSheet Class
 * It handles the loading of *.sprites XML Files
 */
class SpriteSheet: public Resource {
public:

	/**
	 * Gets the Named Sprite
	 * The names are Path-like
	 * If the name does not exist in the spritesheet, it returns NullBitmap
	 * @param path The name of the Sprite
	 * @return The Sprite
	 */
	const Bitmap& getSprite(const std::string& path) const;

	/**
	 * Gets the Spritesheet's Mother Bitmap
	 * @return The Spritesheet Bitmap
	 */
	const Bitmap& getImage() const {
		return *image;
	}

	/**
	 * Default Constructor
	 * Creates an Empty Spritesheet
	 */
	SpriteSheet();

	/**
	 * Loads the XML Spritesheet
	 * @param path The Filename to the XML File
	 */
	SpriteSheet(const std::string& path);

	/**
	 * Destructor
	 * Destroys all Sprites and Unloads the Mother Bitmap
	 */
	~SpriteSheet();
protected:
	ZSmallMap<std::string, Bitmap*> sprites;
	const Bitmap *image;
private:
	void handleNode(const std::string& curName, xmlpp::Element* curNode);
};

} /* namespace Zeta */

#endif /* SPRITESHEET_HPP_ */
