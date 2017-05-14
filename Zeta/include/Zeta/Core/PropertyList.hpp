/*
 * PropertyList.hpp
 *
 *  Created on: 6 Μαρ 2014
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

#ifndef PROPERTYLIST_HPP_
#define PROPERTYLIST_HPP_

#include <Zeta/Core/ZetaConfig.hpp>
#include <string>
#include <Zeta/Core/ZSmallMap.hpp>

namespace xmlpp {
class Element;
}  // namespace xmlpp

namespace Zeta {

class PropertyList{
public:

	lua_Object getLuaTable() const;

	const std::string& getProperty(const std::string& name) const;
	void setProperty(const std::string& name, const std::string& value);

	PropertyList();
	~PropertyList();
private:
	ZSmallMap<std::string, std::string> properties;
	static std::string nullProperty;
};

} /* namespace Zeta */

#endif /* PROPERTYLIST_HPP_ */
