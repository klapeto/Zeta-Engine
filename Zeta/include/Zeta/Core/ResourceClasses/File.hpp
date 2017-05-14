/*
 * File.hpp
 *
 *  Created on: 16 Δεκ 2013
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

#ifndef FILE_HPP_
#define FILE_HPP_

#include <stddef.h>
#include <string>

#include <Zeta/Core/ResourceClasses/Resource.hpp>

namespace Zeta {

/**
 * General File Class
 * This class loads a file to memory
 */
class File: public Resource {
public:

	/**
	 * Gets the pointer to the data of the File
	 * The Pointer is at the beginning of the file
	 * @return The Pointer to the file data
	 */
	char* getData() const {
		return data;
	}

	/**
	 * Gets the size of the file in bytes
	 * @return The file Size
	 */
	size_t getSize() const {
		return size;
	}

	/**
	 * Default Constructor
	 * It creates a empty XML File in the memory
	 */
	File();

	/**
	 * Loads the file in memory from the path
	 * @param path The filename path to load
	 */
	File(const std::string& path);

	/**
	 * Deallocates the memory that the file data used
	 */
	~File();
protected:
	size_t size;
	mutable char *data;
};

} /* namespace Zeta */

#endif /* FILE_HPP_ */
