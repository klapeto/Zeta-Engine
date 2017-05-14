/*
 * ResourceContext.hpp
 *
 *  Created on: 16 Σεπ 2014
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

#ifndef RESOURCECONTEXT_HPP_
#define RESOURCECONTEXT_HPP_

#include <string>
#include <Zeta/Core/Context.hpp>

namespace Zeta {

class AnimationClass;
class Bitmap;
class SoundInstance;
class File;
class Sound;
class SpriteSheet;
class AnimationPack;
class AbilityClass;
class LifeformClass;

/**
 * Resource Context Inteface
 * An Interface for Resource Managers
 */
class ResourceContext: public Context<ResourceContext> {
public:

	virtual SoundInstance& getSound(const std::string& path)=0;
	virtual const Bitmap& getBitmap(const std::string& path)=0;
	virtual const AnimationClass& getAnimationClass(const std::string& path)=0;
	virtual const AnimationPack& getAnimationPack(const std::string& path)=0;
	virtual const File& getFile(const std::string& path)=0;
	virtual const SpriteSheet& getSpriteSheet(const std::string& path)=0;
	virtual const AbilityClass& getAbilityClass(const std::string& path)=0;
	virtual const LifeformClass& getLifeformClass(const std::string& path)=0;

	virtual void releaseResource(const Bitmap& resource)=0;
	virtual void releaseResource(const Sound& resource)=0;
	virtual void releaseResource(const AnimationClass& resource)=0;
	virtual void releaseResource(const File& resource)=0;
	virtual void releaseResource(const SpriteSheet& resource)=0;
	virtual void releaseResource(const AnimationPack& resource)=0;
	virtual void releaseResource(const AbilityClass& resource)=0;
	virtual void releaseResource(const LifeformClass& resource)=0;

	virtual const Bitmap& getNullBitmap()=0;
	virtual const Sound& getNullSound()=0;

	ResourceContext() {

	}
	virtual ~ResourceContext() {

	}
};

} /* namespace Zeta */

#endif /* RESOURCECONTEXT_HPP_ */
