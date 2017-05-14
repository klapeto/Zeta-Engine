/*
 * StaticQuadtree.hpp
 *
 *  Created on: 9 Σεπ 2014
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

#ifndef STATICQUADTREE_HPP_
#define STATICQUADTREE_HPP_

#include <vector>

#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>

namespace Zeta {

class Object;

/**
 * Class for creating and Handling QuadTree Nodes
 * The Quadtree is Static, meaning that the Nodes are predefined
 */
class StaticQuadtree: public Drawable {
public:

	/**
	 * Gets whether this QuadTree Node is leaf
	 * @return true if this node is leaf
	 */
	bool isLeaf() const {
		return leaf;
	}

	/**
	 * Sets this QuadTree Node as leaf
	 * @param leaf true to set as Leaf
	 */
	void setLeaf(bool leaf) {
		this->leaf = leaf;
	}

	/**
	 * Tries to insert the object to this node
	 * \note it might not insert it if the object does not fit
	 * @param obj The Object to insert
	 * @return The result according to the Insert_Out Enumeration
	 */
	int insert(Object* obj);

	/**
	 * Gets the objects near the Coordinates
	 * @param x The x coodrinate
	 * @param y The y coordinate
	 * @return A std::vector<Object*> with the Objects near
	 */
	std::vector<Object*> getObjectsAt(Float x, Float y) const;

	/**
	 * Gets the Objects that collide with the provided Rectangle
	 * @param rect The rectangle to check
	 * @return A std::vector<Object*> with the Objects that overlap the Rectangle
	 */
	std::vector<Object*> getObjectsAt(const Rectangle& rect) const;

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	/**
	 * Clears the QuadTree and the objects inside
	 * \note It does not destroy the objects
	 */
	void clear();

	/**
	 * Sets the QuadTree's Bounds
	 * @param x The x Coordinate of the Quadtree
	 * @param y The y Coordinate of the Quadtree
	 * @param width The width of the Quadtree
	 * @param height The height of the Quadtree
	 */
	void setBounds(Float x, Float y, Float width, Float height);

	/**
	 * Offsets the Quadtree location
	 * The offset is applied to childs too
	 * @param dx The offset to apply on the x axis
	 * @param dy The offset to apply on the y axis
	 */
	void offset(Float dx, Float dy);

	/**
	 * Resets the Quadtree's position to (0,0)
	 */
	void resetPosition();

	/**
	 * Sets the Size of the QuadTree
	 * @param width The width to assign
	 * @param height The height to assign
	 */
	void setSize(Float width, Float height);

	/**
	 * Sets the position of the Quadtree
	 * @param x The x coordinate
	 * @param y The y coordinate
	 */
	void setPosition(Float x, Float y);

	/**
	 * Gets the Width of the Quadtree
	 * @return The Width
	 */
	Float getWidth() const {
		return bounds.getWidth();
	}

	/**
	 * Gets the Height of the Quadtree
	 * @return The height
	 */
	Float getHeight() const {
		return bounds.getHeight();
	}

	/**
	 * Constructs a StaticQuadtree with level 1
	 */
	StaticQuadtree();

	/**
	 * Constructs a Child StaticQuadtree to the parent
	 * @param parent The parent StaticQuadtree
	 * @param level the Depth level
	 */
	StaticQuadtree(StaticQuadtree* parent, int level);
	~StaticQuadtree();
private:
	enum Node {
		NW, NE, SW, SE
	};
	enum Insert_Out {
		No_Contact = -2, Child_Handles = -1, Parent_Handles = 0
	};

	std::vector<Object*> objects;

	StaticQuadtree *childs[4];
	StaticQuadtree *parent;

	Rectangle bounds;

	int level;
	const int maxLevel = 5;
	const unsigned int maxObjects = 10;

	bool leaf;

	void subDivide();
	bool isInside(Object *obj);
	bool touches(Object *obj);
};

} /* namespace Zeta */

#endif /* STATICQUADTREE_HPP_ */
