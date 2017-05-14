/*
 * XMLSchemaValidator.cpp
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/ResourceClasses/File.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <libxml++/validators/schemavalidator.h>
#include <string>

namespace Zeta {

XMLSchemaValidator::XMLSchemaValidator() {
	// Create the Validators
	validators = new xmlpp::SchemaValidator[7];
}

void XMLSchemaValidator::setSchemaFile(const std::string& path,
		ResourceValidator validator) {
	// Check if the Validator ID is valid
	if (static_cast<int>(validator) < 7) {
		// Get the Validator
		xmlpp::SchemaValidator& Svalidator =
				validators[static_cast<int>(validator)];

		try {
			// Try and load the file
			File fp(path);
			// Load the data to the validator
			Svalidator.parse_memory(fp.getData());
		} catch (Exception& ex) {
			// If file does not exist, Report it
			Logger::getInstance().write(
					"While parsing the Schema file: " + path + " Reason: "
							+ std::string(ex.reason()),
					Logger::MessageType::Error);
		} catch (std::exception& ex) {
			// If the Validator had an error, Report it too!
			Logger::getInstance().write(
					"While parsing the Schema file: " + path + " Reason: "
							+ std::string(ex.what()),
					Logger::MessageType::Error);
		}
	}

}

xmlpp::SchemaValidator& XMLSchemaValidator::getValidator(
		ResourceValidator validator) {
	// Check if the Validator ID is valid
	if (static_cast<int>(validator) < 7) {
		// Check if the target Validator exists (there is a pointer there)
		if (!validators[static_cast<int>(validator)]) {
			// If id does not exist, Report it
			Logger::getInstance().write(
					"XMLSchemaValidator was requested a Schema file that was not parsed!: ",
					Logger::MessageType::Warning);
		}
		// Return the validator
		return validators[static_cast<int>(validator)];
	}
	// If we were given invalid id, return the first validator
	return validators[0];
}

XMLSchemaValidator::~XMLSchemaValidator() {
	// Destroy all Validators
	delete [] validators;
}

} /* namespace Zeta */
