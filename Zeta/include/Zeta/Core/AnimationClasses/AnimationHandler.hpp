/*
 * AnimationHandler.hpp
 *
 *  Created on: 28 Φεβ 2014
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

#ifndef ANIMATIONHANDLER_HPP_
#define ANIMATIONHANDLER_HPP_

#include <Zeta/Core/AnimationClasses/OffAnimation.hpp>
#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/ZSmallMap.hpp>
#include <string>

namespace Zeta {

class Animation;

/**
 * Class for handling Lifeform Animations
 */
class AnimationHandler: public Drawable, public Updateable, public LuaPushable {
public:

	enum class QueuePlace {
		Front, Back
	};

	/**
	 * Gets the AnimationClass that the Handler has
	 * @return the AnimationClass
	 */
	const AnimationClass& getAnimationClass() const {
		return *animClass;
	}

	/**
	 * Gets whether it should release its AnimationClass
	 * upon destruction
	 * @return true if the AnimationClass will be released
	 */
	bool isReleaseResources() const {
		return releaseResources;
	}

	/**
	 * Sets whether it should release its AnimationClass
	 * upon destruction
	 * @param true if the AnimationClass will be released
	 */
	void setReleaseResources(bool releaseResources) {
		this->releaseResources = releaseResources;
	}

	/**
	 * Gets the AnimationPlayer of the main animation
	 * @return The main AnimationPlayer
	 */
	AnimationPlayer& getMainAnimationPlayer() const {
		return mainAnimation;
	}

	/**
	 * Sets the main Animation from the name provided
	 * If the named animation does not exist in the AnimationClass
	 * then the fallback will be used
	 * @param name The name of the Animation on the AnimationClass to be used
	 * @param nonExist The Animation to be used if the Animation with name does not exist. This is LifeformState::CombinedState
	 */
	void setAnimation(const std::string& name,
			LifeformState::CombinedState nonExist = LifeformState::Action::Idle
					| LifeformState::Direction::Down);

	/**
	 * Sets the main Animation from the LifeformState::CombinedState
	 * @param The LifeformState that has the animation
	 */
	void setAnimation(LifeformState::CombinedState name);

	void update(Float elapsedTime);

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	/**
	 * Sets the AnimationClass to be used
	 * The main Animation that will be used is the LifeformState::Idle + Down
	 * @param animClass The AnimationClass
	 */
	void setAnimationClass(const AnimationClass& animClass);

	/**
	 * Sets the AnimationClass to be used from the path provided
	 * If necessary, it will be loaded. The previous AnimationClass
	 * will be released depending on the releaseResources Flag.
	 * @param path The file path of the AnimationClass to be used
	 */
	void setAnimationClass(const std::string& path);

	/**
	 * Adds the Animation as an OffAnimation to the provided queue with the provided offsets
	 * @param animation The Animation to be added
	 * @param dx The offset on the x axis relative to the main Animation
	 * @param dy The offset on the y axis relative to the main Animation
	 * @param queue The queue to be placed (Either front of the Main Animation of back)
	 */
	void addOffAnimation(const Animation& animation, Float dx = 0.0f, Float dy =
			0.0f, QueuePlace queue = QueuePlace::Front);

	/**
	 * Gets the OffAnimation that was previously added with addOffAnimation()
	 * \note If the named OffAnimation does not exist, then a NullAnimation will be returned
	 * @param name The name of the Animation
	 * @param queue The Queue that was added
	 * @return The OffAnimation or NullAnimation if it does not exist
	 */
	OffAnimation& getOffAnimation(const std::string& name, QueuePlace queue =
			QueuePlace::Front);

	void pushToLua(lua_State* lstate);

	/**
	 * Constructs a AnimationHandler and sets a NullAnimation as the Main Animation
	 */
	AnimationHandler();

	/**
	 * Constructs a AnimationHandler and sets the AnimationClass
	 * @param animClass The AnimationClass to set
	 */
	AnimationHandler(const AnimationClass& animClass);

	/**
	 * Constructs a AnimationHandler and sets the AnimationClass
	 * from the file path provided. It will load it if necessary.
	 * The main Animation is set from the animation parameter
	 * @param classPath The file path of the AnimationClass to use
	 * @param animation The name of the Animation to be used as Main
	 */
	AnimationHandler(const std::string& classPath,
			const std::string& animation = "");

	~AnimationHandler();
private:
	ZSmallMap<std::string, OffAnimation> frontalAnimations;
	ZSmallMap<std::string, OffAnimation> backAnimations;
	mutable AnimationPlayer mainAnimation;
	const AnimationClass *animClass;
	bool releaseResources;
};

} /* namespace Zeta */

#endif /* ANIMATIONHANDLER_HPP_ */
