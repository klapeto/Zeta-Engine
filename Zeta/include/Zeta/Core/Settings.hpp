/*
 * Settings.hpp
 *
 *  Created on: 22 Δεκ 2013
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

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <Zeta/Core/Display.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>
#include <vector>

namespace Zeta {

class Settings: public SingleInstanced<Settings>, public LuaPushable {
public:

	std::vector<Display::Resolution>& getResolutions() {
		return resolutions;
	}

	const Display::Resolution& getResolutionAt(unsigned int index) {
		if (index < resolutions.size()) {
			return resolutions[index];
		} else {
			return currentResolution;
		}
	}

	unsigned int getResolutionNum() const {
		return resolutions.size();
	}

	const Display::Resolution& getCurrentResolution() const {
		return currentResolution;
	}

	bool getFullscreen() const {
		return fullScreen;
	}

	void setFullscreen(bool val);

	void setResolution(const Display::Resolution& res);

	void loadFile(const std::string& path = "XMLFiles/Settings.xml");
	void saveSettings(const std::string& path = "XMLFiles/Settings.xml");

	lua_Object getResolutionsTable();

	void pushToLua(lua_State* lstate);

	~Settings();
private:
	Settings();

	std::vector<Display::Resolution> resolutions;
	Display::Resolution currentResolution;
	float soundGain;
	bool fullScreen;
	void defaultSettings();
	void retrieveAvailableResolutions();

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* SETTINGS_HPP_ */
