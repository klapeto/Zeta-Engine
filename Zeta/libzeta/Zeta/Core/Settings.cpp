/*
 * Settings.cpp
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

#include <Zeta/Core/GUIManager.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/AudioContext.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/Settings.hpp>
#include <Zeta/Core/System.hpp>
#include <glibmm/ustring.h>
#include <libxml++/document.h>
#include <libxml++/nodes/element.h>
#include <libxml++/nodes/node.h>
#include <libxml++/parsers/domparser.h>
#include <tolua++.h>
#include <cstdlib>
#include <exception>

namespace Zeta {

Settings::Settings() :
		soundGain(1.0f), fullScreen(true) {
}

Settings::~Settings() {

}

void Settings::loadFile(const std::string& path) {
	using namespace xmlpp;

	DomParser parser;

	try {
		File fp(path);
		parser.parse_memory_raw((const unsigned char*) (fp.getData()),
				fp.getSize());
	} catch (std::exception &ex) {
		retrieveAvailableResolutions();
		defaultSettings();
		return;
	}
	NodeSet setting = parser.get_document()->get_root_node()->find(
			"//Setting[@name=\'Width\']");
	if (setting.size() > 0) {
		currentResolution.width = strtol(
				static_cast<xmlpp::Element*>(setting[0])->get_attribute_value(
						"value").c_str(), nullptr, 0);
	}
	setting = parser.get_document()->get_root_node()->find(
			"//Setting[@name=\'Height\']");
	if (setting.size() > 0) {
		currentResolution.height = strtol(
				static_cast<xmlpp::Element*>(setting[0])->get_attribute_value(
						"value").c_str(), nullptr, 0);
	}
	setting = parser.get_document()->get_root_node()->find(
			"//Setting[@name=\'FullScreen\']");
	if (setting.size() > 0) {
		fullScreen = strtol(
				static_cast<xmlpp::Element*>(setting[0])->get_attribute_value(
						"value").c_str(), nullptr, 0);
	}
	setting = parser.get_document()->get_root_node()->find(
			"//Setting[@name=\'MainGain\']");
	if (setting.size() > 0) {
		soundGain = strtof(
				static_cast<xmlpp::Element*>(setting[0])->get_attribute_value(
						"value").c_str(), nullptr);
	}

	retrieveAvailableResolutions();
	bool valid = false;
	for (auto &res : resolutions) {
		if (res.height == currentResolution.height
				&& res.width == currentResolution.width) {
			valid = true;
			break;
		}
	}
	if (!valid) {
		currentResolution.height = resolutions[0].height;
		currentResolution.width = resolutions[0].width;
	}

	auto& disp = System::getInstance().getRenderingContext().getDisplay();

	disp.setFullScreen(fullScreen);
	disp.resize(currentResolution.width, currentResolution.height);
	currentResolution.height = disp.getHeight();
	currentResolution.width = disp.getWidth();
	GUIManager::getInstance().displayResized(currentResolution.width,
			currentResolution.height);
	System::getInstance().getAudioContext().setMainGain(soundGain);
}

void Settings::saveSettings(const std::string& path) {

}

void Settings::setFullscreen(bool val) {
	fullScreen = val;

	System::getInstance().getRenderingContext().getDisplay().setFullScreen(val);
}

lua_Object Settings::getResolutionsTable() {
	lua_State* lstate = LuaEngine::getInstance().getState();
	lua_createtable(lstate, 0, resolutions.size());

	for (auto& res : resolutions) {
		lua_pushstring(lstate,
				std::string(
						std::to_string(res.width) + "x"
								+ std::to_string(res.height)).c_str());
		res.pushToLua(lstate);
		lua_settable(lstate, -3);
	}
	return -1;
}

void Settings::defaultSettings() {
	auto& disp = System::getInstance().getRenderingContext().getDisplay();

	disp.setFullScreen(true);
	disp.resize(resolutions[0].width, resolutions[0].height);
	currentResolution.height = disp.getHeight();
	currentResolution.width = disp.getWidth();
	GUIManager::getInstance().displayResized(currentResolution.width,
			currentResolution.height);
}

void Settings::setResolution(const Display::Resolution& res) {

	if (res.height == currentResolution.height
			&& res.width == currentResolution.width) {
		return;
	}
	currentResolution = res;
	System::getInstance().getRenderingContext().getDisplay().resize(res.width,
			res.height);
	GUIManager::getInstance().displayResized(res.width, res.height);

}

void Settings::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Settings");
}

void Settings::retrieveAvailableResolutions() {
	resolutions =
			System::getInstance().getRenderingContext().getDisplay().getAvailableResolutions();
}

} /* namespace Zeta */
