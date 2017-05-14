/*
 * Quadtree.hpp
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

#ifndef QUADTREE_HPP_
#define QUADTREE_HPP_

#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <vector>

namespace Zeta {

class Object;

class Quadtree {
public:

	int insert(Object* obj);

	std::vector<Object*> getObjectsAt(Float x, Float y) const;
	std::vector<Object*> getObjectsAt(const Rectangle& rect) const;

	void draw(Float x, Float y) const;

	void clear();

	Quadtree();
	Quadtree(Float x, Float y, Float width, Float height, int level, int maxLevel,
			Quadtree *parrent);
	~Quadtree();
private:

	enum NODES {
		NW, NE, SW, SE
	};
	enum Insert_Out {
		No_Contact = -2, Child_Handles = -1, Parent_Handles = 0
	};

	std::vector<Object*> objects;

	Quadtree *childs[4];
	Quadtree *parent;

	Rectangle bounds;

	int level;
	int maxLevel;
	unsigned int maxObjects;

	bool leaf;

	void subDivide();
	bool isInside(Object *obj);
	bool touches(Object *obj);

};

} /* namespace Zeta */

#endif /* QUADTREE_HPP_ */
