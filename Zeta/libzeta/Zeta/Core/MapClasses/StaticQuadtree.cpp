/*
 * StaticQuadtree.cpp
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

#include <Zeta/Core/MapClasses/StaticQuadtree.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <iterator>

namespace Zeta {

StaticQuadtree::StaticQuadtree() :
		parent(nullptr), level(0), leaf(true) {
	// Construct the children
	childs[NW] = new StaticQuadtree(this, 1);
	childs[NE] = new StaticQuadtree(this, 1);
	childs[SW] = new StaticQuadtree(this, 1);
	childs[SE] = new StaticQuadtree(this, 1);

}

StaticQuadtree::StaticQuadtree(StaticQuadtree* parent, int level) :
		parent(parent), level(level), leaf(true) {
	// Check if the level is below the max allowed
	if (level < maxLevel) {
		// Create the children on the next level
		childs[NW] = new StaticQuadtree(this, level + 1);
		childs[NE] = new StaticQuadtree(this, level + 1);
		childs[SW] = new StaticQuadtree(this, level + 1);
		childs[SE] = new StaticQuadtree(this, level + 1);
	} else {
		// if we reached the max level, create nothing
		childs[NW] = nullptr;
		childs[NE] = nullptr;
		childs[SW] = nullptr;
		childs[SE] = nullptr;
	}
}

int StaticQuadtree::insert(Object* obj) {
	// Check if the object is overlapping with this node
	if (bounds.overlapsRectangle(obj->getBounding())) {
		// If it overlaps, then check if it is wholly inside
		if (bounds.overlapsWholeRectangle(obj->getBounding())) {
			// if it it's wholly inside, then add it
			objects.push_back(obj);
		} else {
			// if it is not wholly inside, check if we have a parent
			if (parent != nullptr) {
				// if we have a parent, then he should add it
				return Insert_Out::Parent_Handles;
			} else {
				// if we haven't a parent, then we will add it
				objects.push_back(obj);
			}
		}
	} else {
		// if it does not overlap at all, then let the caller know
		return No_Contact;
	}
	// Here we will get if we added the object
	// We have to check if we reached the max object count
	//  for this node
	if (objects.size() > maxObjects) {
		// If we have reached the limits, then we need to subdivide
		// the node to 4
		if (leaf) {
			// if we are leaf, then check if we can subdivide
			if (level < maxLevel) {
				// if we can then do it
				subDivide();
			} else {
				// if we can't subdivide, then pass it to the parent
				// (although we have the item?? it makes no sense)
				return Insert_Out::Parent_Handles;
			}
		}
		// since we subdivided, we have to insert the objects to the new sub-nodes
		for (auto itr = objects.begin(); itr != objects.end();) {
			// for all sub-nodes
			for (int i = 0; i < 4; ++i) {
				// try to insert and get the outcome
				int res = childs[i]->insert(*itr);
				// check the result
				if (res == Insert_Out::Parent_Handles) {
					// if we should handle it, then go to the next object
					// since we already handle it
					++itr;
					break;
				} else if (res == Insert_Out::Child_Handles) {
					// if the child handle it, then erase the object from
					// this node
					itr = objects.erase(itr);
					break;
				}
			}
		}
	}
	// Let the parrent that we handled the object
	return Insert_Out::Child_Handles;
}

std::vector<Object*> StaticQuadtree::getObjectsAt(Float x, Float y) const {
	// we should collect all the objects from here and the children
	std::vector<Object*> returnOBJS = objects, childOBJS;
	// check if this node is leaf
	if (!leaf) {
		// if it is not, then get the objects from the child that overlaps
		if (childs[NW]->bounds.overlapsPoint(x, y)) {
			childOBJS = childs[NW]->getObjectsAt(x, y);
		} else if (childs[NE]->bounds.overlapsPoint(x, y)) {
			childOBJS = childs[NE]->getObjectsAt(x, y);
		} else if (childs[SW]->bounds.overlapsPoint(x, y)) {
			childOBJS = childs[SW]->getObjectsAt(x, y);
		} else if (childs[SE]->bounds.overlapsPoint(x, y)) {
			childOBJS = childs[SE]->getObjectsAt(x, y);
		}
	} else {
		// if it is leaf, then return the objects we have
		return objects;
	}

	// merge the table to get all the objects
	returnOBJS.insert(returnOBJS.end(), childOBJS.begin(), childOBJS.end());
	// return the objects
	return returnOBJS;
}

std::vector<Object*> StaticQuadtree::getObjectsAt(const Rectangle& rect) const {
	// we should collect all the objects from here and the children
	std::vector<Object*> returnOBJS = objects, childOBJS;
	// check if this node is leaf
	if (!leaf) {
		// if it is not, then get the objects from the child that overlaps
		if (childs[NW]->bounds.overlapsRectangle(rect)) {
			childOBJS = childs[NW]->getObjectsAt(rect);
		} else if (childs[NE]->bounds.overlapsRectangle(rect)) {
			childOBJS = childs[NE]->getObjectsAt(rect);
		} else if (childs[SW]->bounds.overlapsRectangle(rect)) {
			childOBJS = childs[SW]->getObjectsAt(rect);
		} else if (childs[SE]->bounds.overlapsRectangle(rect)) {
			childOBJS = childs[SE]->getObjectsAt(rect);
		}
	} else {
		// if it is leaf, then return the objects we have
		return objects;
	}
	// merge the table to get all the objects
	returnOBJS.insert(returnOBJS.end(), childOBJS.begin(), childOBJS.end());
	// return the objects
	return returnOBJS;
}

void StaticQuadtree::draw(Float x, Float y, Float rotation, Float scale) const {
	// we have to draw the bounds of every child and this node
	if (!leaf) {
		// if this is not leaf, draw the children
		childs[NW]->draw(x, y, rotation, scale);
		childs[NE]->draw(x, y, rotation, scale);
		childs[SW]->draw(x, y, rotation, scale);
		childs[SE]->draw(x, y, rotation, scale);
	}
	// draw this bounds
	bounds.draw(x, y, rotation);
}

void StaticQuadtree::clear() {
	// if we are not leaf, we need to clear the children too
	if (!leaf) {
		childs[NW]->clear();
		childs[NE]->clear();
		childs[SW]->clear();
		childs[SE]->clear();
	}
	// clear the objects
	objects.clear();
	// since the children have no objects
	// this means we are leaf
	leaf = true;
}

void StaticQuadtree::setBounds(Float x, Float y, Float width, Float height) {
	// set the bounds
	bounds.setPosition(x, y);
	bounds.setSize(width, height);
}

StaticQuadtree::~StaticQuadtree() {
	// clear the objects
	clear();
	// delete the children (if exists)
	for (auto ch : childs) {
		delete ch;
	}
}

void StaticQuadtree::subDivide() {
	// We have to place the children
	Float x = bounds.getX(), y = bounds.getY();
	Float half_w = bounds.getWidth() / 2, half_h = bounds.getHeight() / 2;

	// Top Left
	childs[NW]->setLeaf(true);
	childs[NW]->setBounds(x, y, half_w, half_h);

	// Top Right
	childs[NE]->setLeaf(true);
	childs[NE]->setBounds(x + half_w, y, half_w, half_h);

	// Bottom Left
	childs[SW]->setLeaf(true);
	childs[SW]->setBounds(x, y + half_h, half_w, half_h);

	// Bottom Right
	childs[SE]->setLeaf(true);
	childs[SE]->setBounds(x + half_w, y + half_h, half_w, half_h);

	// Since we have children, we are no longer leaf
	leaf = false;
}

bool StaticQuadtree::isInside(Object* obj) {
	// if it is inside, then it must be the whole in
	return bounds.overlapsWholeRectangle(obj->getBounding());
}

void StaticQuadtree::resetPosition() {
	// set this position  to 0
	bounds.setPosition(0.0f, 0.0f);
	if (!leaf) {
		// if we have children, we must place them to the right
		// position
		Float half_w = childs[NW]->getWidth() / 2, half_h =
				childs[NW]->getHeight() / 2;
		childs[NW]->setPosition(0.0f, 0.0f);
		childs[NE]->setPosition(half_w, 0.0f);
		childs[SW]->setPosition(0.0f, half_h);
		childs[SE]->setPosition(half_w, half_h);
	}
}

void StaticQuadtree::setSize(Float width, Float height) {
	// set the size
	bounds.setSize(width, height);
	if (!leaf) {
		// If we have children, set it's size too
		Float half_w = width / 2, half_h = height / 2;
		childs[NW]->setSize(half_w, half_h);
		childs[NE]->setSize(half_w, half_h);
		childs[SW]->setSize(half_w, half_h);
		childs[SE]->setSize(half_w, half_h);
	}
}

void StaticQuadtree::setPosition(Float x, Float y) {
	// set the Position
	bounds.setPosition(x, y);
	if (!leaf) {
		// If we have children, set it's position too
		Float half_w = childs[NW]->getWidth() / 2, half_h =
				childs[NW]->getHeight() / 2;
		childs[NW]->setPosition(x, y);
		childs[NE]->setPosition(x + half_w, y);
		childs[SW]->setPosition(x, y + half_h);
		childs[SE]->setPosition(x + half_w, y + half_h);
	}
}

bool StaticQuadtree::touches(Object* obj) {
	return bounds.overlapsRectangle(obj->getBounding());
}

void StaticQuadtree::offset(Float dx, Float dy) {
	// offset the position
	bounds.offsetPosition(dx, dy);
	if (!leaf) {
		// If we have children, offset then too
		childs[NW]->offset(dx, dy);
		childs[NE]->offset(dx, dy);
		childs[SW]->offset(dx, dy);
		childs[SE]->offset(dx, dy);
	}
}

} /* namespace Zeta */
