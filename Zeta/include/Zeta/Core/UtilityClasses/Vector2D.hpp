/*
 * Vector2D.hpp
 *
 *  Created on: 19 Σεπ 2014
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

#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include <cstddef>
#include <vector>

namespace Zeta {

template<typename type>
class Vector2D {
public:

	inline type& at(size_t x, size_t y) {
		return vec.at((y * rows) + x);
	}

	inline const type& at(size_t x, size_t y) const {
		return vec.at((y * rows) + x);
	}

	inline type& operator()(size_t x, size_t y) {
		return vec[(y * rows) + x];
	}

	inline const type& operator()(size_t x, size_t y) const {
		return vec[(y * rows) + x];
	}

	void resize(size_t rows, size_t columns) {
		vec.resize((rows * columns) + 2);
		this->rows = rows;
		this->columns = columns;
	}

	size_t getRowsN() const {
		return rows;
	}

	size_t getColumnsN() const {
		return columns;
	}

	void clear() {
		vec.clear();
		rows = 0;
		columns = 0;
	}

	std::vector<type>& getInternal() {
		return vec;
	}

	Vector2D() :
			columns(0), rows(0) {

	}

	Vector2D(size_t rows, size_t columns) :
			columns(columns), rows(rows) {
		vec.resize((rows * columns) + 2);
	}
	~Vector2D() {

	}
private:

	std::vector<type> vec;
	size_t columns;
	size_t rows;
};

} /* namespace Zeta */

#endif /* VECTOR2D_HPP_ */
