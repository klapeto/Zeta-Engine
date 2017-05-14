/*
 * AllegroDisplay.cpp
 *
 *  Created on: 1 Σεπ 2014
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

#include <allegro5/allegro.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#if ALLEGRO_WIP_VERSION > 6
#include <allegro5/drawing.h>
#include <allegro5/fullscreen_mode.h>
#endif
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroDisplay.hpp>
#include <string>
#include <vector>

namespace Zeta {

AllegroDisplay::AllegroDisplay() :
		Display() {
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	disp = al_create_display(1024, 768);
}

void AllegroDisplay::resize(int width, int height) {
	if (!al_resize_display(disp, width, height)) {
		Logger::getInstance().write(
				"Failed to resize display: " + std::to_string(width) + "x"
						+ std::to_string(height));
	}
}

void AllegroDisplay::setFullScreen(bool value) {
#if ALLEGRO_WIP_VERSION > 6
	if (!al_set_display_flag(disp, ALLEGRO_FULLSCREEN_WINDOW, value)) {
#else
	if (!al_toggle_display_flag(disp, ALLEGRO_FULLSCREEN_WINDOW, value)) {
#endif
		Logger::getInstance().write(
				"Failed to set display fullScreen to: "
						+ std::to_string(value));
	}
}

std::vector<Display::Resolution> AllegroDisplay::getAvailableResolutions() const {
	int numRes = al_get_num_display_modes();
	std::vector<Display::Resolution> resolutions;
	resolutions.resize(numRes);
	for (int i = 0; i < numRes; ++i) {
		ALLEGRO_DISPLAY_MODE mode;
		al_get_display_mode(i, &mode);
		resolutions[i].height = mode.height;
		resolutions[i].width = mode.width;
	}
	return resolutions;
}

AllegroDisplay::AllegroDisplay(int width, int height) :
		Display() {
	disp = al_create_display(width, height);
}

void AllegroDisplay::switchFramebuffer() {
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

AllegroDisplay::~AllegroDisplay() {
	al_destroy_display(disp);
}

int Zeta::AllegroDisplay::getWidth() const {
	return al_get_display_width(disp);
}

int Zeta::AllegroDisplay::getHeight() const {
	return al_get_display_height(disp);
}

} /* namespace Zeta */
