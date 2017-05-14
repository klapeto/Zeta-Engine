/*
 * AsynchronousResourceContext.hpp
 *
 *  Created on: 17 Σεπ 2014
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

#ifndef ZETA_CAN_USE_ASYNCHRONOUS
#error The usage of Asynchronous Context Templates is not recommended! They do not work yet.
#else

#ifndef ASYNCHRONOUSRESOURCECONTEXT_HPP_
#define ASYNCHRONOUSRESOURCECONTEXT_HPP_

#include <Zeta/Core/AsynchronousWorker.hpp>
#include <Zeta/Core/Context.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/ResourceClasses/AbilityClass.hpp>
#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <Zeta/Core/ResourceClasses/Bitmap.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/ResourceClasses/SharedResource.hpp>
#include <Zeta/Core/ResourceClasses/Sound.hpp>
#include <Zeta/Core/ResourceClasses/SoundInstance.hpp>
#include <Zeta/Core/ResourceClasses/SpriteSheet.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/System.hpp>
#include <LibraryBinders/Loaders/FileLoader.hpp>
#include <mutex>
#include <queue>
#include <string>
#include <unordered_map>

namespace Zeta {

	template<typename BitmapT, typename SoundT>
	class AsynchronousResourceContext: public ResourceContext,
public AsynchronousWorker {
	public:

		void addOperationToQueue(ContextOperation<ResourceContext>& operation) {
			std::unique_lock<std::mutex> lock(mutex);
			operations.push(&operation);
			performCycle();
		}
		const Bitmap& getBitmap(const std::string& path) {
			BitmapLoadRequest load(path);
			addOperationToQueue(load);
			load.waitToBeCompleted();
			return load.getBitmap();
		}

		SoundInstance& getSound(const std::string& path) {
			return getResource(path, sounds).createNewInstance();
		}

		const AnimationClass& getAnimationClass(const std::string& path) {
			return getResource(path, animationClasses);
		}

		const File& getFile(const std::string& path) {
			return getResource(path, files);
		}

		const SpriteSheet& getSpriteSheet(const std::string& path) {
			return getResource(path, spriteSheets);
		}

		const AnimationPack& getAnimationPack(const std::string& path) {
			return getResource(path, animationPacks);
		}

		const AbilityClass& getAbilityClass(const std::string& path) {
			return getResource(path, abilityClasses);
		}

		const LifeformClass& getLifeformClass(const std::string& path) {
			return getResource(path, lifeformClasses);
		}

		void releaseResource(const Bitmap& bitmap) {
			addOperationToQueue(
					*new ResourceReleaseRequest<BitmapT>(bitmap.getName(),
							bitmaps));
		}

		void releaseResource(const Sound& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<SoundT>(resource.getName(),
							sounds));
		}

		void releaseResource(const AnimationClass& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<AnimationClass>(resource.getName(),
							animationClasses));
		}

		void releaseResource(const File& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<File>(resource.getName(), files));
		}

		void releaseResource(const SpriteSheet& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<SpriteSheet>(resource.getName(),
							spriteSheets));
		}

		void releaseResource(const AnimationPack& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<AnimationPack>(resource.getName(),
							animationPacks));
		}
		void releaseResource(const AbilityClass& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<AbilityClass>(resource.getName(),
							abilityClasses));
		}
		void releaseResource(const LifeformClass& resource) {
			addOperationToQueue(
					*new ResourceReleaseRequest<LifeformClass>(resource.getName(),
							lifeformClasses));
		}

		const Bitmap& getNullBitmap() {
			return NullReference<BitmapT>::getNull();
		}
		const Sound& getNullSound() {
			return NullReference<SoundT>::getNull();
		}

		AsynchronousResourceContext() :
		AsynchronousWorker() {

		}
		~AsynchronousResourceContext() {

		}
	private:
		std::unordered_map<std::string, SharedResource<BitmapT>> bitmaps;
		std::unordered_map<std::string, SharedResource<SoundT>> sounds;
		std::unordered_map<std::string, SharedResource<AnimationClass>> animationClasses;
		std::unordered_map<std::string, SharedResource<File>> files;
		std::unordered_map<std::string, SharedResource<SpriteSheet>> spriteSheets;
		std::unordered_map<std::string, SharedResource<AnimationPack>> animationPacks;
		std::unordered_map<std::string, SharedResource<AbilityClass>> abilityClasses;
		std::unordered_map<std::string, SharedResource<LifeformClass>> lifeformClasses;

		template<typename ResourceT>
		const ResourceT& getResource(const std::string& path,
				std::unordered_map<std::string, SharedResource<ResourceT>>& resMap) {
			ResourceLoadRequest<ResourceT> load(path, resMap);
			addOperationToQueue(load);
			load.waitToBeCompleted();
			return load.getResource();
		}

		class BitmapLoadRequest: public ContextOperation<ResourceContext> {
		public:
			void setPath(const std::string& path) {
				this->path = path;
			}
			const BitmapT& getBitmap() {
				return *retBmp;
			}
			void handle(ResourceContext& context) {
				auto& cntx = static_cast<AsynchronousResourceContext<BitmapT,SoundT>&>(context);
				auto itr = cntx.bitmaps.find(path);
				if (itr != cntx.bitmaps.end()) {
					if (itr->second.isValid()) {
						itr->second.increaseReference();
						retBmp = &itr->second.getInstance();
					} else {
						retBmp = &NullReference<BitmapT>::getNull();
					}
				} else {
					BitmapRequest bmpRequest(path);
					System::getInstance().getRenderingContext().addOperationToQueue(
							bmpRequest);
					bmpRequest.waitToBeCompleted();
					if (bmpRequest.getBitmap() != nullptr) {
						SharedResource<BitmapT>& sBmp = cntx.bitmaps[path];
						sBmp.setInstance(*bmpRequest.getBitmap());
						sBmp.increaseReference();
						retBmp = &sBmp.getInstance();
					} else {
						cntx.bitmaps[path].setValid(false);
						retBmp = &NullReference<BitmapT>::getNull();
					}
				}
			}
			BitmapLoadRequest(const std::string& path) :
			ContextOperation<ResourceContext>(
					false), path(path), retBmp(nullptr) {
			}
		private:
			std::string path;
			const BitmapT* retBmp;
		};

		template<typename ResourceT>
		class ResourceLoadRequest: public ContextOperation<ResourceContext> {
		public:
			void setPath(const std::string& path) {
				this->path = path;
			}
			const ResourceT& getResource() {
				return *retResource;
			}
			void handle(ResourceContext& context) {
				auto itr = mapRef.find(path);
				if (itr != mapRef.end()) {
					if (itr->second.isValid()) {
						itr->second.increaseReference();
						retResource = &itr->second.getInstance();
					} else {
						retResource = &NullReference<ResourceT>::getNull();
					}
				} else {
					if (FileLoader::fileExists(path.c_str())) {
						SharedResource<ResourceT> res(path);
						if (res.isValid()) {
							res.increaseReference();
							mapRef[path] = std::move(res);
							retResource = &res.getInstance();
						} else {
							mapRef[path].setValid(false);
							retResource = &NullReference<ResourceT>::getNull();
						}
					} else {
						mapRef[path].setValid(false);
						retResource = &NullReference<ResourceT>::getNull();
					}
				}
			}

			ResourceLoadRequest(const std::string& path,
					std::unordered_map<std::string, SharedResource<ResourceT>>& map) :
			mapRef(map), path(path), retResource(nullptr) {

			}
		private:
			std::unordered_map<std::string, SharedResource<ResourceT>>& mapRef;
			std::string path;
			const ResourceT* retResource;
		};

		class BitmapRequest: public ContextOperation<RenderingContext> {
		public:

			void setPath(const std::string& path) {
				this->path = path;
			}
			BitmapT* getBitmap() {
				return bmp;
			}
			void handle(RenderingContext& context) {
				bmp = new BitmapT(path);
			}
			BitmapRequest() :
			ContextOperation<RenderingContext>(false), bmp(nullptr) {
			}
			BitmapRequest(const std::string& path) :
			ContextOperation<RenderingContext>(false), path(path), bmp(
					nullptr) {

			}
		private:
			std::string path;
			BitmapT* bmp;
		};

		template<typename ResourceT>
		class ResourceReleaseRequest: public ContextOperation<ResourceContext> {
		public:

			void handle(ResourceContext& context) {
				auto itr = mapRef.find(path);
				if (itr != mapRef.end()) {
					if (itr->second.isValid()) {
						itr->second.decreaseReference();
						if (itr->second.getReferenceCount() <= 0) {
							mapRef.erase(itr);
						}
					}
				}
			}

			ResourceReleaseRequest(const std::string& path,
					std::unordered_map<std::string, SharedResource<ResourceT>>& mapRef) :
			ContextOperation<ResourceContext>(
					true), path(path), mapRef(mapRef) {

			}

		private:
			std::string path;
			std::unordered_map<std::string, SharedResource<ResourceT>>& mapRef;
		};

		void runCycleOperations() {
			executeOperations();
		}
	};
} /* namespace Zeta */

#endif /* ASYNCHRONOUSRESOURCECONTEXT_HPP_ */

#endif /* ZETA_CAN_USE_ASYNCHRONOUS */
