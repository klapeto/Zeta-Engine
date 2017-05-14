/*
 * Layer.hpp
 *
 *  Created on: 7 Μαρ 2014
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

#ifndef LAYER_HPP_
#define LAYER_HPP_

#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/UtilityClasses/Vector2D.hpp>

namespace xmlpp {
class Element;
} /* namespace xmlpp */

namespace Zeta {

class Tile;

/**
 * Class for loading and drawing Map Layers
 */
class Layer {
public:

	/**
	 * Draws the Layer
	 * The drawing is based on a rectangle that is defined.
	 * This rectangle is actually the view that the Layer must
	 * draw to.
	 * @param dx The x coordinate of the Top Left point of the Rectangle
	 * @param dy The y coordinate of the Top Left point of the Rectangle
	 * @param numTilesX The number of tiles on the x axis should to draw (width)
	 * @param numTilesy The number of tiles on the y axis should to draw (height)
	 */
	void draw(float dx, float dy, int numTilesX, int numTilesY) const;

	/**
	 * Gets the Tile at the target Layer Coordinate
	 * \note The coordinate is discreet, meaning the coordinate in on the Table, not on the map
	 * @param x The x coordinate at the Layer Table
	 * @param y The y coordinate at the Layer Table
	 * @return The tile that exists there, or Null if no Tile exist at this point
	 */
	const Tile* getTileAt(unsigned int x, unsigned int y) const;

	/**
	 * Constructs an Empty Layer
	 */
	Layer();

	/**
	 * Constructs and Loads a Layer from the XML node provided
	 * \note The xml Node must have a valid <layer> node
	 * @param layerNode The XML Node that has the data to load
	 * @param tilesets The Available Tilesets
	 * @param parrent the Parrent Map that will have the Layer
	 */
	Layer(xmlpp::Element *layerNode, const std::vector<MapTileset> &tilesets,
			Map &parrent);

	~Layer();
protected:

	Vector2D<const Tile*> tiles;
	Map* parent;
	unsigned int width;
	unsigned int height;

	int tileWidth;
	int tileHeight;

	void nullise();
};

} /* namespace Zeta */

#endif /* LAYER_HPP_ */
