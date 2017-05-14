/*
 * SaveManager.hpp
 *
 *  Created on: 28 Απρ 2014
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

#ifndef SAVEMANAGER_HPP_
#define SAVEMANAGER_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <libxml++/parsers/domparser.h>
#include <string>

namespace Zeta {

class SaveManager: public SingleInstanced<SaveManager>, public LuaPushable {
public:

	void setFile(const std::string& path);
	void save();
	void load();

	xmlpp::Element* getSaveFileRoot();

	void write(const std::string& name, const std::string& value);
	std::string read(const std::string& name) const;

	void pushToLua(lua_State* lstate);

private:
	xmlpp::DomParser parser;
	std::string filename;

	void retrievePlayer(xmlpp::Element *node);
	void retrieveMap(xmlpp::Element *node);

	void savePlayer(xmlpp::Element *node);
	void saveMap(xmlpp::Element *node);

	SaveManager();
	~SaveManager();
	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* SAVEMANAGER_HPP_ */
