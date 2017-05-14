/*
 * Quadtree.cpp
 *
 *  Created on: 20 Μαρ 2014
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

#include <Zeta/Core/MapClasses/Quadtree.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <iterator>

namespace Zeta {

Quadtree::Quadtree() :
		parent(nullptr), level(0), maxLevel(5), maxObjects(10), leaf(true) {
	childs[NW] = nullptr;
	childs[NE] = nullptr;
	childs[SW] = nullptr;
	childs[SE] = nullptr;
}

Quadtree::Quadtree(Float x, Float y, Float width, Float height, int level,
		int maxLevel, Quadtree* parrent) :
		parent(nullptr), bounds(x, y, width, height), level(0), maxLevel(5), maxObjects(
				10), leaf(true) {
	childs[NW] = nullptr;
	childs[NE] = nullptr;
	childs[SW] = nullptr;
	childs[SE] = nullptr;
}

int Quadtree::insert(Object* obj) {
	if (bounds.overlapsRectangle(obj->getBounding())) {
		if (bounds.overlapsWholeRectangle(obj->getBounding())) {
			objects.push_back(obj);
		} else {					// Δεν είναι ολόκληρο μέσα
			if (parent != nullptr) {
				return Insert_Out::Parent_Handles;
			} else {
				objects.push_back(obj);
			}
		}
	} else {
		return No_Contact;
	}
	if (objects.size() > maxObjects && level < maxLevel) {
		if (leaf) {
			subDivide();
		}
		for (auto itr = objects.begin(); itr != objects.end();) {
			for (int i = 0; i < 4; ++i) {
				int res = childs[i]->insert(*itr);
				if (res == Insert_Out::Parent_Handles) {
					++itr;
					break;
				} else if (res == Insert_Out::Child_Handles) {
					itr = objects.erase(itr);
					break;
				}
			}
		}
	}
	return Insert_Out::Child_Handles;			// Δεν ακουμπάει το Node

}

std::vector<Object*> Quadtree::getObjectsAt(Float x, Float y) const {
	std::vector<Object*> returnOBJS = objects, childOBJS;
	if (!leaf) {
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
		return objects;
	}

	returnOBJS.insert(returnOBJS.end(), childOBJS.begin(), childOBJS.end());
	return returnOBJS;
}

std::vector<Object*> Quadtree::getObjectsAt(const Rectangle& rect) const {
	std::vector<Object*> returnOBJS = objects, childOBJS;
	if (!leaf) {
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
		return objects;
	}

	returnOBJS.insert(returnOBJS.end(), childOBJS.begin(), childOBJS.end());
	return returnOBJS;
}

void Quadtree::draw(Float x, Float y) const {
	if (!leaf) {
		childs[NW]->draw(x, y);
		childs[NE]->draw(x, y);
		childs[SW]->draw(x, y);
		childs[SE]->draw(x, y);
	}
}

void Quadtree::clear() {
	if (!leaf) {
		childs[NW]->clear();
		childs[NE]->clear();
		childs[SW]->clear();
		childs[SE]->clear();
		delete childs[NW];
		delete childs[NE];
		delete childs[SW];
		delete childs[SE];
		childs[NW] = nullptr;
		childs[NE] = nullptr;
		childs[SW] = nullptr;
		childs[SE] = nullptr;
	}
	objects.clear();
	leaf = true;
}

Quadtree::~Quadtree() {
	if (childs[NW] != nullptr) {
		clear();
	}
}

void Quadtree::subDivide() {
	Float x = bounds.getX(), y = bounds.getY();
	Float half_w = bounds.getWidth() /2 , half_h = bounds.getHeight() /2 ;

	childs[NW] = new Quadtree(x, y, half_w, half_h, level + 1, maxLevel, this);
	childs[NE] = new Quadtree(x + half_w, y, half_w, half_h, level + 1,
			maxLevel, this);
	childs[SW] = new Quadtree(x, y + half_h, half_w, half_h, level + 1,
			maxLevel, this);
	childs[NE] = new Quadtree(x + half_w, y + half_h, half_w, half_h, level + 1,
			maxLevel, this);

	leaf = false;
}

bool Quadtree::isInside(Object* obj) {
	return bounds.overlapsWholeRectangle(obj->getBounding());
}

bool Quadtree::touches(Object* obj) {
	return bounds.overlapsRectangle(obj->getBounding());
}

} /* namespace Zeta */
