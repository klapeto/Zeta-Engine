/*
 * AllegroRenderer.hpp
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

#ifndef ALLEGRORENDERER_HPP_
#define ALLEGRORENDERER_HPP_

#include <Zeta/Core/ShapeRenderer.hpp>

namespace Zeta {

class AllegroRenderer: public ShapeRenderer {
public:

	void holdBitmapDraw(bool vall);

	void drawEllipsis(float center_x, float center_y, float radius_x,
			float radius_y, const Color& borderC, float thickness);
	void drawFilledEllipsis(float center_x, float center_y, float radius_x,
			float radius_y, const Color& fillC);

	void drawRectangle(float a_x, float a_y, float b_x, float b_y,
			const Color& borderC, float thickness);
	void drawFilledRectangle(float a_x, float a_y, float b_x, float b_y,
			const Color& fillC);
	void drawLine(float x1, float y1, float x2, float y2, const Color& fillC,
			float thickness);

	AllegroRenderer() {

	}
	~AllegroRenderer() {

	}
};

} /* namespace Zeta */

#endif /* ALLEGRORENDERER_HPP_ */
