/*
 * SharedResource.hpp
 *
 *  Created on: 3 Σεπ 2014
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

#ifndef SHAREDRESOURCE_HPP_
#define SHAREDRESOURCE_HPP_

#include <string>
#include <type_traits>

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>

namespace Zeta {

/**
 * Shared Resouce Template
 * It defines a Resource Type that will be shared among other Engine parts
 */
template<typename RType>
class SharedResource: public NonCopyable {
public:

	/**
	 * We must make sure that the Template argument has Resource as Base class
	 */
	static_assert(std::is_base_of<Resource,RType>::value,"ERROR! Invalid Argument for Shared Resource template! Argument is not derived of Resource Class");

	/**
	 * Check whether the resource is Valid
	 * Valid means that the resource is loaded and can be used
	 * @return true if the resource is valid for use
	 */
	bool isValid() const {
		return valid;
	}

	/**
	 * Set whether the resource is Valid
	 * Valid means that the resource is loaded and can be used
	 * @param valid The value to assign to the valid falg
	 */
	void setValid(bool valid) {
		this->valid = valid;
	}

	/**
	 * Gets the Reference Count for this resource
	 * The Reference Count is a number of how many objects have a reference to this
	 * Resource.
	 * @return The reference Count number
	 */
	int getReferenceCount() const {
		return referenceCount;
	}

	/**
	 * Gets the actual Resource Object
	 * @return The usable Resource Object
	 */
	const RType& getInstance() const {
		return *instance;
	}

	/**
	 * Sets the Resource Object
	 * It automatically validates the Resource
	 * @param instance The resource Object to be set
	 */
	void setInstance(RType& instance) {
		this->instance = &instance;
		valid = true;
	}

	/**
	 * Loads the Resource from the Filename
	 * The resource is loaded by calling the constructor
	 * Resource(const std::string&) of the derived class.
	 * if there was already a Resource Object, then the old gets Deleted.
	 * If there is any error, then it sets the valid flag to False, and can't be used
	 * @param path The filename to Load
	 */
	void load(const std::string& path) {
		// If there is already an Instance, destroy it
		if (instance != nullptr) {
			delete instance;
		}
		try {
			// try to costruct and Load the Resource
			instance = new RType(path);
		} catch (Exception& ex) {
			// If any Engine related Exception was thrown
			// Destroy the Instance if it actually was created
			delete instance;
			// Log the Error
			Logger::getInstance().write(
					"During loading: " + path + " Reason: " + ex.reason(),
					Logger::MessageType::Error);
			// Invalidate the resource
			valid = false;
			// Clear the Instance Pointer
			instance = nullptr;
			return;
		} catch (std::exception& ex) {
			// If any General related Exception was thrown
			// Destroy the Instance if it actually was created
			delete instance;
			// Log the Error
			Logger::getInstance().write(
					"During loading: " + path + " Reason: "
							+ std::string(ex.what()),
					Logger::MessageType::Error);
			// Invalidate the resource
			valid = false;
			// Clear the Instance Pointer
			instance = nullptr;
			return;
		}
		// If the resource was loaded successfully
		// Set the Name of the Resource to the Name
		instance->setName(path);
		// Validate the resource
		valid = true;
	}

	/**
	 * Increases the Reference Counter
	 */
	void increaseReference() {
		++referenceCount;
	}

	/**
	 * Decreases the Reference Counter
	 */
	void decreaseReference() {
		--referenceCount;
	}

	SharedResource(SharedResource&&) = default;
	SharedResource& operator=(SharedResource&&) = default;

	/**
	 * Default Constructor
	 * Nothing is loaded and is invalid
	 */
	SharedResource() :
			instance(nullptr), referenceCount(0), valid(false) {

	}

	/**
	 * Constructs and Loads the Filename
	 * @param path The file to load
	 */
	SharedResource(const std::string& path) :
			instance(nullptr), referenceCount(0), valid(false) {
		load(path);
	}

	/**
	 * Constructs and sets the Resource Object
	 * @param resource The resource Object to set
	 */
	SharedResource(RType& resource) :
			instance(&resource), referenceCount(0), valid(true) {

	}

	/**
	 * Destroys the Resource Object if any
	 */
	~SharedResource() {
		if (valid) {
			delete instance;
		}
	}

private:
	RType* instance;
	int referenceCount;
	bool valid;
};

} /* namespace Zeta */

#endif /* SHAREDRESOURCE_HPP_ */
