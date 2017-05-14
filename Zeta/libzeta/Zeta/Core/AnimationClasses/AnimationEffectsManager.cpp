/*
 * AnimationEffectsManager.cpp
 *
 *  Created on: 8 Νοε 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/AnimationClasses/AnimationEffectsManager.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/System.hpp>
#include <utility>

namespace Zeta {

AnimationEffectsManager::AnimationEffectsManager() {

}

const Animation& AnimationEffectsManager::getAnimationFX(
		const std::string& name, const std::string& animationPack) const {
	auto pack = animationPacks.find(animationPack);
	if (pack != animationPacks.end()) {
		return pack->second->getAnimation(name);
	} else {
		return NullReference<Animation>::getNull();
	}
}

void AnimationEffectsManager::addAnimationPack(const std::string& path,
		const std::string& name) {
	const std::string* actName;
	if (name.size() > 0) {
		actName = &name;
	} else {
		actName = &path;
	}
	auto itr = animationPacks.find(*actName);
	if (itr == animationPacks.end()) {
		animationPacks[*actName] =
				&System::getInstance().getResourcesManager().getAnimationPack(
						path);
	} else {
		Logger::getInstance().write(
				"Tried to add Animation Pack:" + path + " with name:" + *actName
						+ ". An Animation pack with than name already exists. Ignoring...",
				Logger::MessageType::Warning);
	}
}

AnimationEffectsManager::~AnimationEffectsManager() {
// Since System will handle the cleanup, there is no reason for this.
#if false
	auto& resMan = System::getInstance().getResourcesManager();
	for (auto anim : animationPacks) {
		resMan.releaseResource(*anim.second);
	}
#endif
}

} /* namespace Zeta */
