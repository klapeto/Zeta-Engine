/*
 * ResourceCache.hpp
 *
 *  Created on: 2 Μαρ 2015
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

#ifndef ZETA_CORE_RESOURCECACHE_HPP_
#define ZETA_CORE_RESOURCECACHE_HPP_

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/SharedResource.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/ZMap.hpp>
#include <Zeta/LibraryBinders/Loaders/FileLoader.hpp>
#include <string>

namespace Zeta {

class ResourceCache: public SingleInstanced<ResourceCache> {
public:
	const AbilityClass& getAbilityClass(const std::string& path) {
		return getResource(path, abilityClasses);
	}
	const LifeformClass& getLifeformClass(const std::string& path) {
		return getResource(path, lifeformClasses);
	}

	void releaseResource(const AbilityClass& value) {
		releaseMappedResource(value.getName(), abilityClasses);
	}

	void releaseResource(const LifeformClass& value) {
		releaseMappedResource(value.getName(), lifeformClasses);
	}
private:
	ResourceCache() {

	}
	~ResourceCache() {

	}
	ZMap<std::string, SharedResource<AbilityClass>> abilityClasses;
	ZMap<std::string, SharedResource<LifeformClass>> lifeformClasses;

	template<typename RType>
	const RType& getResource(const std::string& path,
			ZMap<std::string, SharedResource<RType>>& map) {
		auto itr = map.find(path);
		if (itr != map.end()) {
			if (itr->second.isValid()) {
				itr->second.increaseReference();
				return itr->second.getInstance();
			} else {
				return NullReference<RType>::getNull();
			}
		} else {
			if (FileLoader::fileExists(path.c_str())) {
				SharedResource<RType> &res = map[path];
				res.load(path);
				if (res.isValid()) {
					res.increaseReference();
					return res.getInstance();
				} else {
					return NullReference<RType>::getNull();
				}
			} else {
				Logger::getInstance().write(
						"During loading: " + path
								+ " via ResouceCache -> Reason: File does not exits",
						Logger::MessageType::Error);
				map[path].setValid(false);
				return NullReference<RType>::getNull();
			}
		}
		return NullReference<RType>::getNull();
	}

	template<typename RType>
	void releaseMappedResource(const std::string& path,
			ZMap<std::string, SharedResource<RType>>& map) {
		auto itr = map.find(path);
		if (itr != map.end()) {
			if (itr->second.isValid()) {
				itr->second.decreaseReference();
				if (itr->second.getReferenceCount() <= 0) {
					Logger::getInstance().write(
							"Releasing Resource via ResouceCache: " + path);
					map.erase(itr);
				}
			}
		}
	}

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RESOURCECACHE_HPP_ */
