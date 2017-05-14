/*
 * AllegroRenderer.cpp
 *
 *  Created on: 25 Σεπ 2014
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

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <Zeta/Core/Color.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroRenderer.hpp>

namespace Zeta {

void AllegroRenderer::holdBitmapDraw(bool vall) {
	al_hold_bitmap_drawing(vall);
}

void AllegroRenderer::drawEllipsis(float center_x, float center_y,
		float radius_x, float radius_y, const Color& borderC, float thickness) {
	al_draw_ellipse(center_x, center_y, radius_x, radius_y,
			al_map_rgba(borderC.r, borderC.g, borderC.b, borderC.a), thickness);
}

void AllegroRenderer::drawFilledEllipsis(float center_x, float center_y,
		float radius_x, float radius_y, const Color& fillC) {
	al_draw_filled_ellipse(center_x, center_y, radius_x, radius_y,
			al_map_rgba(fillC.r, fillC.g, fillC.b, fillC.a));
}

void AllegroRenderer::drawRectangle(float a_x, float a_y, float b_x, float b_y,
		const Color& borderC, float thickness) {
	al_draw_rectangle(a_x, a_y, b_x, b_y,
			al_map_rgba(borderC.r, borderC.g, borderC.b, borderC.a), thickness);
}

void AllegroRenderer::drawFilledRectangle(float a_x, float a_y, float b_x,
		float b_y, const Color& fillC) {
	al_draw_filled_rectangle(a_x, a_y, b_x, b_y,
			al_map_rgba(fillC.r, fillC.g, fillC.b, fillC.a));
}

void AllegroRenderer::drawLine(float x1, float y1, float x2, float y2,
		const Color& fillC, float thickness) {
	al_draw_line(x1, y1, x2, y2,
			al_map_rgba(fillC.r, fillC.g, fillC.b, fillC.a), thickness);
}

} /* namespace Zeta */
