/*
 * ShapeRenderer.hpp
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

#ifndef SHAPERENDERER_HPP_
#define SHAPERENDERER_HPP_

namespace Zeta {

class Color;

/**
 * ShapeRenderer Interface
 * Provides functions to draw different shapes
 */
class ShapeRenderer {
public:

	/**
	 * Enables or disables differed drawing where possible
	 * Differed drawing is a certain mode that have some SKDs
	 * that draws bitmaps more efficient when the bitmaps are
	 * sub-bitmaps to a larger. If the implementing SDK does not
	 * have such function, then it should not do anything
	 * @param vall true to enable differed drawing, false to disable
	 */
	virtual void holdBitmapDraw(bool vall)=0;

	/**
	 * Draws an Ellipsis with no Fill
	 * @param center_x The x coordinate of the center of the Ellipsis
	 * @param center_y The y coordinate of the center of the Ellipsis
	 * @param radius_x The radius on the x axis
	 * @param radius_y The radius on the y axis
	 * @param borderC The color of the outline
	 * @param thickness The thickness of the outline
	 */
	virtual void drawEllipsis(float center_x, float center_y, float radius_x,
			float radius_y, const Color& borderC, float thickness)=0;

	/**
	 * Draws a Filled Ellipsis
	 * @param center_x The x coordinate of the center of the Ellipsis
	 * @param center_y The y coordinate of the center of the Ellipsis
	 * @param radius_x The radius on the x axis
	 * @param radius_y The radius on the y axis
	 * @param fillC The color of the fill of the ellipsis
	 */
	virtual void drawFilledEllipsis(float center_x, float center_y,
			float radius_x, float radius_y, const Color& fillC)=0;

	/**
	 * Draws a Rectangle with no Fill
	 * The rectangle is defined by 2 points, the Top-Left, Bottom-Right
	 * @param a_x The x coordinate of the Top-Left point of the Rectangle
	 * @param a_y The y coordinate of the Top-Left point of the Rectangle
	 * @param b_x The x coordinate of the Bottom-Right point of the Rectangle
	 * @param b_y The y coordinate of the Bottom-Right point of the Rectangle
	 * @param borderC The color of the outline
	 * @param thickness The thickness of the outline
	 */
	virtual void drawRectangle(float a_x, float a_y, float b_x, float b_y,
			const Color& borderC, float thickness)=0;

	/**
	 * Draws a Filled Rectangle
	 * The rectangle is defined by 2 points, the Top-Left, Bottom-Right
	 * @param a_x The x coordinate of the Top-Left point of the Rectangle
	 * @param a_y The y coordinate of the Top-Left point of the Rectangle
	 * @param b_x The x coordinate of the Bottom-Right point of the Rectangle
	 * @param b_y The y coordinate of the Bottom-Right point of the Rectangle
	 * @param fillC The color of the Fill
	 */
	virtual void drawFilledRectangle(float a_x, float a_y, float b_x, float b_y,
			const Color& fillC)=0;

	/**
	 * Draws a Line
	 * The line is defined by 2 points
	 * @param x1 The x coordinate of the First point
	 * @param y1 The y coordinate of the First point
	 * @param x2 The x coordinate of the Second point
	 * @param y2 The y coordinate of the Second point
	 * @param fillC The color of the line
	 * @param thickness the Thickness of the line
	 */
	virtual void drawLine(float x1, float y1, float x2, float y2,
			const Color& fillC, float thickness)=0;

	ShapeRenderer() {

	}
	virtual ~ShapeRenderer() {

	}
};

} /* namespace Zeta */

#endif /* SHAPERENDERER_HPP_ */
