/*
 * Object.hpp
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

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <Zeta/Core/PropertyList.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/ZSmallMap.hpp>
#include <string>
#include <vector>

namespace Zeta {

class ChildObject;
class Visitor;

/**
 * Base class for all the Objects in the Game
 */
class Object: public Drawable, public Updateable, public LuaPushable {
public:

	/**
	 * Gets the Bounding Rectangle
	 * @return The bounding Rectangle
	 */
	const Rectangle& getBounding() const {
		return bounding;
	}

	/**
	 * Gets the Bounding Rectangle
	 * @return The bounding Rectangle
	 */
	Rectangle& getBounding() {
		return bounding;
	}

	/**
	 * Sets the Bounding Rectangle
	 * @param bounding The bounding Rectangle to set
	 */
	void setBounding(const Rectangle& bounding) {
		this->bounding = bounding;
	}

	/**
	 * Gets the Target Area Rectangle
	 * @return The Target Area Rectangle
	 */
	const Rectangle& getTargetArea() const {
		return targetArea;
	}

	/**
	 * Gets the Target Area Rectangle
	 * @return The Target Area Rectangle
	 */
	Rectangle& getTargetArea() {
		return targetArea;
	}

	/**
	 * Gets the Position of the Object
	 * @return The position
	 */
	const Vector2& getPosition() const {
		return position;
	}

	/**
	 * Sets the Position of the Object
	 * @param position The new position to set
	 */
	void setPosition(const Vector2& position);

	/**
	 * Sets the Position of the Object
	 * @param x The x coordinate of the position to set
	 * @param y The y coordinate of the position to set
	 */
	virtual void setPosition(Float x, Float y);

	/**
	 * Gets the name of the Object
	 * @return The name
	 */
	const std::string& getName() const {
		return name;
	}

	/**
	 * Sets the name of the Object
	 * @param name The new name
	 */
	void setName(const std::string& name) {
		this->name = name;
	}

	/**
	 * Gets the Custom Properties of the object
	 * @return The properties object
	 */
	const PropertyList& getCustomProperties() const {
		return customProperties;
	}

	/**
	 * Gets the Custom Properties of the object
	 * @return The properties object
	 */
	PropertyList& getCustomProperties() {
		return customProperties;
	}

	/**
	 * Gets the distance from the Other Object
	 * @param other The other Object to calculate the Distance
	 * @return The distance
	 */
	Float getDistance(const Object& other) const {
		return position.getDistance(other.position);
	}

	/**
	 * Gets the distance from the provided Position
	 * @param other The other Position to calculate the Distance
	 * @return The distance
	 */
	Float getDistance(const Vector2& position) const {
		return this->position.getDistance(position);
	}

	/**
	 * Gets whether the Object can be collided
	 * @return true if the object can be collided
	 */
	inline bool isCollideAble() const {
		return collideAble;
	}

	/**
	 * Sets whether the Object can be collided
	 * @param value true if the object should be able to be collided
	 */
	void setCoolideAble(bool value) {
		collideAble = value;
	}

	/**
	 * Gets whether the Object can trigger Collision Events
	 * \note The events can be triggered even if the object is cannot be collided if this is true
	 * @return true if the Object can trigger the events
	 */
	bool isTriggeringCollisionEvents() const {
		return triggersCollisionEvents;
	}

	/**
	 * Sets whether the Object can trigger Collision Events
	 * \note The events can be triggered even if the object is cannot be collided if this is set true
	 * @return true if the Object should trigger the events
	 */
	void setTriggeringCollisionEvents(bool value) {
		triggersCollisionEvents = value;
	}

	/**
	 * Gets if the object is visible
	 * \note this is not if the object is in screen. It it if the object will be drawn or not
	 * @return true if the object is visible
	 */
	inline bool isVisible() const {
		return visible;
	}

	/**
	 * Sets if the object is visible
	 * \note this is not if the object is in screen. It it if the object will be drawn or not
	 * \note This cause the call of onShow() or onHide() depending of the value passed on visible
	 * @param visible true if the object should be visible
	 */
	void setVisible(bool visible) {
		this->visible = visible;
		visible == true ? onShow() : onHide();
	}

	/**
	 * Shows the object and calls the onShow()
	 */
	inline void show() {
		visible = true;
		onShow();
	}

	/**
	 * Hides the object and calls the onHide()
	 */
	inline void hide() {
		visible = false;
		onHide();
	}

	/**
	 * Function to be called when this object is collided with another Object
	 * @param other The other object that has collided with this
	 */
	virtual void onCollidedWith(Object *other)=0;

	/**
	 * Function to be called when this object is interacted with another (usually the Player)
	 * @param other The other object that has interacted with this
	 */
	virtual void onClick(Object *other)=0;

	/**
	 * Callback that is called when the Object is shown
	 */
	virtual void onShow() {

	}

	/**
	 * Callback that is called when the Object is hidden
	 */
	virtual void onHide() {

	}

	/**
	 * Adds the constructed ChildObject to this with name
	 * \note If a child with the same name already exist, then it will not be added and the passed will be destroyed if it is needed
	 * \note The child will be added to the Offset List
	 * @param name The name that the ChildObject will have inside this
	 * @param child The constructed Child To add
	 */
	void addChildObject(const std::string& name, ChildObject *child);

	/**
	 * Constructs and Adds a ChildObject
	 * @param x The offset x to set to the Child relative to this object's x
	 * @param y The offset y to set to the Child relative to this object's y
	 * @param name The name to set to the child
	 * @param classPath The AnimationClass filename to assign to the child
	 * @param animName The animation Name to assign to the child
	 */
	void addChildObject(Float x, Float y, const std::string& name,
			const std::string& classPath, const std::string& animName);

	/**
	 * Removes a ChildObject
	 * \note The ChildObject will be destroyed depending on the configuration of the Child
	 * @param name The name of the Child to remove
	 */
	void removeChildObject(const std::string& name);

	/**
	 * Gets a ChildObject
	 * @param name The name of the ChildObject to get
	 * @return The ChildObject or nullptr if the Child does not exist
	 */
	ChildObject* getChildObject(const std::string& name);

	/**
	 * Offsets the position of the Object
	 * \note The position of the Children that resident on the childsToBeOffseted, is offset too
	 * @param dx The offset to apply on the x axis
	 * @param dy The offset to apply on the y axis
	 */
	virtual void offsetPosition(Float dx, Float dy);

	/**
	 * Offsets all the Shapes of the Object
	 * The shapes are the Bounding and Target Area. On derived classes additional
	 * shapes can be added
	 * @param dx The offset to apply on the x axis
	 * @param dy The offset to apply on the y axis
	 */
	void offsetShapes(Float dx, Float dy) {
		for (auto shape : shapesToBeOffseted) {
			shape->offsetPosition(dx, dy);
		}
	}

	/**
	 * Adds a ChildObject to the list of the Child to be offset when the Object is offset
	 * @param name The name of the child to add on the offset list
	 */
	void addChildToBeOffseted(const std::string& name);

	/**
	 * Removes a ChildObject from the list of children to be offset when the Object is offset
	 * @param name The name of the child to remove from the offset list
	 */
	void removeChildToBeOffseted(const std::string& name);

	/**
	 * Gets the Render position according to the main View of the World
	 * The Render Position is the position relative to the Screen
	 * @return The render Position
	 */
	Vector2 getRenderPosition() const;

	/**
	 * Accepts a Visitor
	 * @param visitor The Visitor to accept
	 */
	virtual void accept(Visitor& visitor)=0;

	Object();
	Object(Float x, Float y);
	Object(Float x, Float y, int width, int height);
	virtual ~Object();
protected:
	PropertyList customProperties;
	ZSmallMap<std::string, ChildObject*> childs;
	ZSmallMap<std::string, ChildObject*> childsToBeOffseted;
	std::vector<Shape*> shapesToBeOffseted;
	std::string name;
	Vector2 position;
	Rectangle bounding;
	Rectangle targetArea;
	bool collideAble;
	bool triggersCollisionEvents;
	bool visible;

	virtual void addShapesToBeOffseted();
};

} /* namespace Zeta */

#endif /* OBJECT_HPP_ */
