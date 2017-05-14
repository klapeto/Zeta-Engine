/*
 * XMLSchemaValidator.hpp
 *
 *  Created on: 5 Σεπ 2014
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

#ifndef XMLSCHEMAVALIDATOR_HPP_
#define XMLSCHEMAVALIDATOR_HPP_

#include <Zeta/Core/SingleInstanced.hpp>

namespace xmlpp {
class SchemaValidator;
}  // namespace xmlpp

namespace Zeta {

/**
 * A container Singleton for providing XML Validators
 */
class XMLSchemaValidator: public SingleInstanced<XMLSchemaValidator> {
public:

	enum class ResourceValidator {
		Sprites,
		Animations,
		Map,
		Tileset,
		AnimationClass,
		LifeformClass,
		Faction
	};

	/**
	 * Retrieves a XML Validator
	 * @param validator The Validator to return
	 * @return The XML Validator
	 */
	xmlpp::SchemaValidator& getValidator(ResourceValidator validator);

	/**
	 * Loads a XSD Schema to the target Validator
	 * @param path The filename of the XSD Schema to load
	 * @param validator The validator to load the Schema to
	 */
	void setSchemaFile(const std::string& path, ResourceValidator validator);

	~XMLSchemaValidator();
private:
	XMLSchemaValidator();
	xmlpp::SchemaValidator* validators;

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* XMLSCHEMAVALIDATOR_HPP_ */
