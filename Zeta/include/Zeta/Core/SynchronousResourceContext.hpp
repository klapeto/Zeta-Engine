/*
 * SynchronousResourceContext.hpp
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

#ifndef SYNCHRONOUSRESOURCECONTEXT_HPP_
#define SYNCHRONOUSRESOURCECONTEXT_HPP_

#include <Zeta/Core/Context.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/Display.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
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
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/System.hpp>
#include <LibraryBinders/Loaders/FileLoader.hpp>
#include <mutex>
#include <string>
#include <type_traits>
#include <unordered_map>

namespace Zeta {

/**
 * Synchronous Resource Context Template
 * A template for managing Resources in a Single Thread (Main thread)
 */
template<typename BitmapT, typename SoundT>
class SynchronousResourceContext: public ResourceContext {
public:

	static_assert(std::is_base_of<Bitmap,BitmapT>::value,"ERROR: Template Argument for Bitmap in the ResourcesManager is not derived form Bitmap Base Class!");
	static_assert(std::is_base_of<Sound,SoundT>::value,"ERROR: Template Argument for Sound in the ResourcesManager is not derived form Sound Base Class!");

	/**
	 * Gets the Sound Instance from the Sound in path
	 * @param path The file path to the Sound
	 * @return A SoundInstance
	 */
	SoundInstance& getSound(const std::string& path) {
		return getResource(path, sounds, soundMutex).createNewInstance();
	}

	/**
	 * Gets The bitmap from the File
	 * @param path The file path to the Bitmap
	 * @return The Bitmap
	 */
	const Bitmap& getBitmap(const std::string& path) {
		return getBitmapImpl(path);
	}

	/**
	 * Gets The AnimationClass from the File
	 * @param path The file path to the AnimationClass
	 * @return The AnimationClass
	 */
	const AnimationClass& getAnimationClass(const std::string& path) {
		return getResource(path, animationClasses, animationClassMutex);
	}

	/**
	 * Gets The File
	 * @param path The file path
	 * @return The File
	 */
	const File& getFile(const std::string& path) {
		return getResource(path, files, fileMutex);
	}

	/**
	 * Gets The SpriteSheet from the File
	 * @param path The file path to the SpriteSheet
	 * @return The SpriteSheet
	 */
	const SpriteSheet& getSpriteSheet(const std::string& path) {
		return getResource(path, spriteSheets, spriteSheetMutex);
	}

	/**
	 * Gets The AnimationPack from the File
	 * @param path The file path to the AnimationPack
	 * @return The AnimationPack
	 */
	const AnimationPack& getAnimationPack(const std::string& path) {
		return getResource(path, animationPacks, animationPackMutex);
	}

	/**
	 * Gets The AbilityClass from the File
	 * @param path The file path to the AbilityClass
	 * @return The AbilityClass
	 */
	const AbilityClass& getAbilityClass(const std::string& path) {
		return getResource(path, abilityClasses, abilityClassMutex);
	}

	/**
	 * Gets The LifeformClass from the File
	 * @param path The file path to the LifeformClass
	 * @return The LifeformClass
	 */
	const LifeformClass& getLifeformClass(const std::string& path) {
		return getResource(path, lifeformClasses, lifeformClassMutex);
	}

	/**
	 * Releases the Bitmap
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The Bitmap
	 */
	void releaseResource(const Bitmap& value) {
		releaseMappedResource(value.getName(), bitmaps, bitmapMutex);
	}

	/**
	 * Releases the Sound
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The Sound
	 */
	void releaseResource(const Sound& value) {
		releaseMappedResource(value.getName(), sounds, soundMutex);
	}

	/**
	 * Releases the AnimationClass
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The AnimationClass
	 */
	void releaseResource(const AnimationClass& value) {
		releaseMappedResource(value.getName(), animationClasses,
				animationClassMutex);
	}

	/**
	 * Releases the File
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The File
	 */
	void releaseResource(const File& value) {
		releaseMappedResource(value.getName(), files, fileMutex);
	}

	/**
	 * Releases the SpriteSheet
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The SpriteSheet
	 */
	void releaseResource(const SpriteSheet& value) {
		releaseMappedResource(value.getName(), spriteSheets, spriteSheetMutex);
	}

	/**
	 * Releases the AnimationPack
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The AnimationPack
	 */
	void releaseResource(const AnimationPack& value) {
		releaseMappedResource(value.getName(), animationPacks,
				animationPackMutex);
	}

	/**
	 * Releases the AbilityClass
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The AbilityClass
	 */
	void releaseResource(const AbilityClass& value) {
		releaseMappedResource(value.getName(), abilityClasses,
				abilityClassMutex);
	}

	/**
	 * Releases the LifeformClass
	 * It doesn't necessarily mean that the Resource will be destroyed
	 * @param value The LifeformClass
	 */
	void releaseResource(const LifeformClass& value) {
		releaseMappedResource(value.getName(), lifeformClasses,
				lifeformClassMutex);
	}

	/**
	 * Gets The NullBitmap
	 * @return The NullBitmap
	 */
	const Bitmap& getNullBitmap() {
		return NullReference<BitmapT>::getNull();
	}

	/**
	 * Gets The NullSound
	 * @return The NullSound
	 */
	const Sound& getNullSound() {
		return NullReference<SoundT>::getNull();
	}

	/**
	 * Does nothing. Exists for clarity Reasons
	 */
	SynchronousResourceContext() {

	}

	/**
	 * Destroys all Resources
	 */
	~SynchronousResourceContext() {
		lifeformClasses.clear();
		abilityClasses.clear();
		animationClasses.clear();
		animationPacks.clear();
		spriteSheets.clear();
		files.clear();
		sounds.clear();
		bitmaps.clear();
	}

private:

	std::mutex bitmapMutex;
	std::mutex soundMutex;
	std::mutex animationClassMutex;
	std::mutex fileMutex;
	std::mutex spriteSheetMutex;
	std::mutex animationPackMutex;
	std::mutex abilityClassMutex;
	std::mutex lifeformClassMutex;

	std::unordered_map<std::string, SharedResource<BitmapT>> bitmaps;
	std::unordered_map<std::string, SharedResource<SoundT>> sounds;
	std::unordered_map<std::string, SharedResource<AnimationClass>> animationClasses;
	std::unordered_map<std::string, SharedResource<File>> files;
	std::unordered_map<std::string, SharedResource<SpriteSheet>> spriteSheets;
	std::unordered_map<std::string, SharedResource<AnimationPack>> animationPacks;
	std::unordered_map<std::string, SharedResource<AbilityClass>> abilityClasses;
	std::unordered_map<std::string, SharedResource<LifeformClass>> lifeformClasses;

	/**
	 * Helper class for asking for the main Thread load A bitmap
	 * If the ResourcesManager is running on a separate thread, then
	 * the it can't load Bitmaps to VRAM, since it can only happen on the Main thread.
	 * This is how OpenGL works, don't blame me.
	 */
	class BitmapLoadRequest: public ContextOperation<RenderingContext> {
	public:

		/**
		 * Gets the Path of the Bitmap that will load
		 * @return The filepath
		 */
		const std::string& getPath() const {
			return path;
		}

		/**
		 * Gets the Bitmap that was loaded
		 * @return The loaded Bitmap
		 */
		const Bitmap& getBitmap() const {
			return *bitmap;
		}

		/**
		 * Handles the request
		 * Loads the Bitmap, as it was a regular request
		 * @param the Context that will handle the Request
		 */
		void handle(RenderingContext& context) {
			bitmap = &System::getInstance().getResourcesManager().getBitmap(
					path);
		}

		/**
		 * Constructs the Request from the File path
		 * @param The Path to bitmap to load
		 */
		BitmapLoadRequest(const std::string& path) :
				ContextOperation(), path(path), bitmap(nullptr) {

		}
		~BitmapLoadRequest() {

		}
	private:
		std::string path;
		const Bitmap *bitmap;
	};

	/**
	 * Loads a resource and registers to the Referenced Hashtable
	 * The load is thread Locked
	 * @param path The file path to load
	 * @param map The hashtable to add the Resource to
	 * @param mutex The mutex to use for locking the Execution.
	 * @return The loaded Resource
	 */
	template<typename RType>
	const RType& getResource(const std::string& path,
			std::unordered_map<std::string, SharedResource<RType>>& map,
			std::mutex& mutex) {
		// Lock the mutex so no other Thread will try to load with
		// the same signature function
		std::unique_lock<std::mutex> lock(mutex);
		// Find the filename in the referenced Hashtable
		auto itr = map.find(path);
		if (itr != map.end()) {
			// If we found it, then check if the resource is valid
			if (itr->second.isValid()) {
				// If the resource is valid for use, increase it's reference count
				itr->second.increaseReference();
				// Return a reference of the Resource
				return itr->second.getInstance();
			} else {
				// If the resource is not valid, return a Null resource reference
				return NullReference<RType>::getNull();
			}
		} else {
			// If the Filename does not exist in the Hashtable
			// Check it the file exists on the disk
			if (FileLoader::fileExists(path.c_str())) {
				// If the file exist, construct an Empty SharedResource on the
				// Hashtable with the path as key and get a reference to it
				SharedResource<RType> &res = map[path];
				// Load to this SharedResource the Filename
				res.load(path);
				// Check the Valid flag to check if it loaded fine
				if (res.isValid()) {
					// If it loaded OK, the increase its reference
					res.increaseReference();
					// Return a reference to the Resource
					return res.getInstance();
				} else {
					// If the file did not load for any reason
					// Return a Null Resource reference
					return NullReference<RType>::getNull();
				}
			} else {
				// If the file does not exist, then Log an error
				Logger::getInstance().write(
						"During loading: " + path
								+ " Reason: File does not exist",
						Logger::MessageType::Error);
				// Construct an Empty SharedResource on the Hashtable
				// With key the path, and invalidate it to prevent further
				// future futile tries to load it
				map[path].setValid(false);
				// Return a Null Resource reference
				return NullReference<RType>::getNull();
			}
		}
		return NullReference<RType>::getNull();
	}

	/**
	 * Releases a resource
	 * @param path The file path of the Resource to Release
	 * @param map The hashtable Resource residents
	 * @param mutex The mutex to use for locking the Execution.
	 */
	template<typename RType>
	void releaseMappedResource(const std::string& path,
			std::unordered_map<std::string, SharedResource<RType>>& map,
			std::mutex& mutex) {
		// Lock the mutex so no other Thread will try to load with
		// the same signiature function
		std::unique_lock<std::mutex> lock(mutex);
		// Find the filename in the referenced Hashtable
		auto itr = map.find(path);
		if (itr != map.end()) {
			// If it exists in the HashTable, check if it is valid
			if (itr->second.isValid()) {
				// If it is valid, decrease its reference Count
				itr->second.decreaseReference();
				// If the reference count reached 0 or below
				if (itr->second.getReferenceCount() <= 0) {
					// Log a Message of the Resource deallocation
					Logger::getInstance().write("Releasing Resource: " + path);
					// Destroy the resource and erase its record on the hashtable
					map.erase(itr);
				}
			}
		}
	}

	/**
	 * It Loads a Bitmap from a File
	 * The load is thread locked
	 * @param path The file path of the Bitmap to load
	 * @return The Loaded bitmap
	 */
	const Bitmap& getBitmapImpl(const std::string& path) {
		// Lock the Execution, so no other thread might try it
		std::unique_lock<std::mutex> lock(bitmapMutex);
		// Find the filename in the Bitmap Hashtable
		auto itr = bitmaps.find(path);
		if (itr != bitmaps.end()) {
			// If it exists in the HashTable, check if it is valid
			if (itr->second.isValid()) {
				// If it is valid, Increase The reference count
				itr->second.increaseReference();
				// Return a reference to the Bitmap
				return itr->second.getInstance();
			} else {
				// If it is not valid, Return a Null Bitmap
				return NullReference<BitmapT>::getNull();
			}
		} else {
			// If it does not exist in the Hashtable, this means that we need to load it

			// Check if this running thread is the Rendering Thread (main thread)
			if (Display::isRenderingThread()) {
				// If it is, then Check if the file exists
				if (FileLoader::fileExists(path.c_str())) {
					// If the File exist, then get construct an Empty SharedResource on the
					// Hashtable with the path as key and get a reference to it
					SharedResource<BitmapT> &res = bitmaps[path];
					// Load the Bitmap
					res.load(path);
					// Check if it loaded fine
					if (res.isValid()) {
						// If it is ok, the increase its Reference Count
						res.increaseReference();
						// Return a Reference to the Bitmap
						return res.getInstance();
					} else {
						// If the file did not load OK, then Return a NullBitmap reference
						return NullReference<BitmapT>::getNull();
					}
				} else {
					// If the file does not exist, the Log an Error
					Logger::getInstance().write(
							"During loading: " + path
									+ " Reason: File does not exist",
							Logger::MessageType::Error);
					// Construct an Empty SharedResource on the Hashtable
					// With key the path, and invalidate it to prevent further
					// future futile tries to load it
					bitmaps[path].setValid(false);
					// Return a NullBitmap Reference
					return NullReference<BitmapT>::getNull();
				}
			} else {
				// If this thread is not the Rendering Thread, then
				// we need to request from the rendering thread to load it for us.
				// So we unlock the mutex, so the Other thread can load it (it will call the same function)
				// and will deadlock on the beginning where it needs to lock the mutex)
				lock.unlock();
				// We construct a BitmapRequest with The filename
				BitmapLoadRequest request(path);
				// Add the request to the Rendering Context's Queue to execute
				System::getInstance().getRenderingContext().addOperationToQueue(
						request);
				// Wait for the Operation to be completed by the Rendering Thread.
				request.waitToBeCompleted();
				// Since the Other Thread loaded it, it means that it called this function too,
				// but there the Display::isRenderingThread() returned true, and did all the
				// associated stuff to the hashtable, like increasing the reference count, so
				// we don't need to do it. So we just return the Bitmap we got.
				return request.getBitmap();
			}
		}
	}
};

} /* namespace Zeta */

#endif /* SYNCHRONOUSRESOURCECONTEXT_HPP_ */
