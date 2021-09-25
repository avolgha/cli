/*
 * logger.cpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */


#include "../head/logger.hpp"

std::string formatted(OutputType type, int foregroundData, int backgroundData)
{
	int typeData;
	switch (type) {
		case OutputType::NORMAL:
			typeData = 0;
			break;
		case OutputType::BOLD:
			typeData = 1;
			break;
		case OutputType::UNDERLINE:
			typeData = 4;
			break;
		default:
			return "";
	}
	std::string s;
	if (backgroundData == -1) {
		s = "\033[%type%;%fore%m";
	} else {
		s = "\033[%type%;%fore%;%back%m";
	}
	replace(s, "%type%", std::to_string(typeData));
	replace(s, "%fore%", std::to_string(foregroundData));
	if (backgroundData != -1) {
		replace(s, "%back%", std::to_string(backgroundData));
	}
	return s;
}

void Logger::print(std::string message, OutputType type, Color *foreground, Color *background)
{
	std::string s = "\033[0;35m[Logger] %f%%m%\033[0m";
	if (background == NULL) {
		replace(s, "%f%", formatted(type, foreground->getData(), -1));
	} else {
		replace(s, "%f%", formatted(type, foreground->getData(), background->getData()));
	}
	replace(s, messageFormatPattern, message);

	std::cout << s << std::endl;
}
