/*
 * File.cpp
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

#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <LibraryBinders/Loaders/FileLoader.hpp>
#include <cstring>

using namespace std;

namespace Zeta {

File::File() :
		Resource("nullFile"), size(
				sizeof("<?xml version=\"1.0\" encoding=\"UTF-8\"?>")) {
	data = new char[size + 1];
	strcat(data, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
}

File::File(const std::string& path) :
		Resource(path) {
	if (FileLoader::fileExists(path.c_str())) {
		FileLoader::FileStat fl = FileLoader::Load(path.data());
		data = fl.data;
		size = fl.size;
	} else {
		throw Exception(path, "File does not exist");
	}
}

File::~File() {
	if (data != nullptr) {
		delete[] data;
	}
}

} /* namespace Zeta */
