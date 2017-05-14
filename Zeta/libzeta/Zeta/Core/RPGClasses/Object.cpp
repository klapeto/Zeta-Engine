/*
 * Object.cpp
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

#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/View.hpp>
#include <utility>

namespace Zeta {

Object::Object(Float x, Float y) :
		position(x, y), bounding(x, y, 10, 10), targetArea(x, y, 10, 10), collideAble(
				true), triggersCollisionEvents(true), visible(true) {

}

Object::Object(Float x, Float y, int width, int height) :
		position(x, y), bounding(x, y, width, height), targetArea(x, y, width,
				height), collideAble(true), triggersCollisionEvents(true), visible(
				true) {

}

Object::Object() :
		collideAble(true), triggersCollisionEvents(true), visible(true) {

}

void Object::offsetPosition(Float dx, Float dy) {
	// Offset the position
	position.offset(dx, dy);
	// Offset all the shapes
	offsetShapes(dx, dy);
	// Offset the children
	for (auto& child : childsToBeOffseted) {
		child.second->offsetPosition(dx, dy);
	}
}

Object::~Object() {
	// Delete any children that need to be deleted
	for (auto anim : childs) {
		if (anim.second->isToBeDeleted()) {
			delete anim.second;
		}
	}
}

void Object::addChildObject(const std::string& name, ChildObject *child) {
	// Check if the child is valid
	if (child != nullptr) {
		// Check if a child with the same name already exist
		if (childs.find(child->getName()) == childs.end()) {
			// If it does not exist, then we can add it
			child->setName(name);
			// add it to the hashtable
			childs[name] = child;
			// Set its parrent
			child->setParent(this);
			// Add to the Offset List
			childsToBeOffseted[name] = child;
		} else {
			// If we already have that name, we will not add it
			// check if we need to destroy it
			if (child->isToBeDeleted()) {
				// if we should, then do it
				delete child;
			}
		}
	}
}

void Object::removeChildObject(const std::string& name) {
	// Search for the child
	auto itr = childs.find(name);
	if (itr != childs.end()) {
		// if we find it, then remove from the offset list
		removeChildToBeOffseted(name);
		// remove its parrent (this)
		itr->second->setParent(nullptr);
		// check if we need to destroy it
		if (itr->second->isToBeDeleted()) {
			delete itr->second;
		}
		// finaly remove it from the children list
		childs.erase(itr);

	}
}

ChildObject* Object::getChildObject(const std::string& name) {
	// search for the child
	auto itr = childs.find(name);
	if (itr != childs.end()) {
		return itr->second;
	} else {
		return nullptr;
	}
}

void Object::addShapesToBeOffseted() {
	// add the basic shapes
	shapesToBeOffseted.push_back(&bounding);
	shapesToBeOffseted.push_back(&targetArea);
}

void Object::addChildObject(Float x, Float y, const std::string& name,
		const std::string& classPath, const std::string& animName) {

	// check if the name already exists
	if (childs.find(name) == childs.end()) {
		// if it does not exist, then we can add it
		ChildObject *ch = new ChildObject(x, y, this, name, classPath,
				animName);
		childs[name] = ch;
	}
}

void Object::addChildToBeOffseted(const std::string& name) {
	// search the child
	auto itr = childs.find(name);
	if (itr != childs.end()) {
		// if we find it then add it
		childsToBeOffseted[name] = itr->second;
	}
}

void Object::removeChildToBeOffseted(const std::string& name) {
	// search the child
	auto itr = childsToBeOffseted.find(name);
	if (itr != childsToBeOffseted.end()) {
		// if we find it then remove it from the list
		childsToBeOffseted.erase(itr);
	}
}

void Object::setPosition(Float x, Float y) {
	// offset the shapes
	offsetShapes(x - position.getX(), y - position.getY());
	// set the position
	position.set(x, y);
}

void Object::setPosition(const Vector2& position) {
	// offset the shapes
	offsetShapes(position.getX()- this->position.getX(),
			position.getY() - this->position.getY());
	// set the position
	this->position = position;
}

Vector2 Object::getRenderPosition() const {
	return position - WorldManager::getInstance().getView().getPosition();
}

} /* namespace Zeta */
