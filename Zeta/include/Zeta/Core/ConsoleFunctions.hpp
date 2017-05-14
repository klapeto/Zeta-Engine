/*
 * ConsoleFunctions.hpp
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

#ifndef CONSOLEFUNCTIONS_HPP_
#define CONSOLEFUNCTIONS_HPP_

#include <Zeta/Core/SingleInstanced.hpp>
#include <string>

namespace Zeta {

class ConsoleFunctions: public SingleInstanced<ConsoleFunctions> {
public:

	static std::string exit(const std::string &args);
	static std::string echo(const std::string &args);
	static std::string teleport(const std::string &args);
	static std::string useAbility(const std::string &args);

	static std::string toggleBoundBoxes(const std::string &args);
	static std::string setBoundPosition(const std::string &args);
	static std::string setBoundSize(const std::string &args);
	static std::string offsetBound(const std::string& args);
	static std::string reloadScript(const std::string& args);

	bool isBoundsShown() const {
		return boundsShown;
	}

	void setBoundsShown(bool boundsShown) {
		this->boundsShown = boundsShown;
	}

private:
	bool boundsShown;

	ConsoleFunctions() :
			boundsShown(false) {

	}

	~ConsoleFunctions() {

	}
	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* CONSOLEFUNCTIONS_HPP_ */
