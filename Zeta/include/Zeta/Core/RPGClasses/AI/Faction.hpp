/*
 * Faction.hpp
 *
 *  Created on: 2 Οκτ 2014
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

#ifndef FACTION_HPP_
#define FACTION_HPP_

#include <string>
#include <Zeta/Core/ZSet.hpp>

namespace Zeta {

class Faction {
public:

	bool isHostile(const std::string& faction) const {
		return hostile.find(faction) != hostile.end();
	}

	void setHostile(const std::string& faction) {
		hostile.insert(faction);
	}

	bool isHostile(const Faction& other) const {
		return isHostile(other.getName());
	}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	Faction() :
			name("Neutral") {

	}
	~Faction() {

	}

private:
	std::string name;
	ZSet<std::string> hostile;
};

} /* namespace Zeta */

#endif /* FACTION_HPP_ */
