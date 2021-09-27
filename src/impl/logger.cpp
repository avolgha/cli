/*
 * logger.cpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */


#include "../head/logger.hpp"

std::string cli::logger::formatted(cli::logger::OutputType type, int foregroundData, int backgroundData)
{
	int typeData;
	switch (type) {
		case cli::logger::OutputType::NORMAL:
			typeData = 0;
			break;
		case cli::logger::OutputType::BOLD:
			typeData = 1;
			break;
		case cli::logger::OutputType::UNDERLINE:
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
	cli::utility::replace(s, "%type%", std::to_string(typeData));
	cli::utility::replace(s, "%fore%", std::to_string(foregroundData));
	if (backgroundData != -1) {
		cli::utility::replace(s, "%back%", std::to_string(backgroundData));
	}
	return s;
}

void cli::logger::Logger::print(std::string message, cli::logger::OutputType type, cli::logger::Color *foreground, cli::logger::Color *background)
{
	std::string s = "\033[0;35m[Logger] %f%%m%\033[0m";
	if (background == NULL) {
		cli::utility::replace(s, "%f%", cli::logger::formatted(type, foreground->getData(), -1));
	} else {
		cli::utility::replace(s, "%f%", cli::logger::formatted(type, foreground->getData(), background->getData()));
	}
	cli::utility::replace(s, messageFormatPattern, message);

	std::cout << s << std::endl;
}
