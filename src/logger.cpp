/*
 * logger.cpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */


#include <iostream>
#include <stdio.h>

#include "logger.hpp"

void replace(std::string& str, const std::string& find, const std::string& replace)
{
	std::size_t position{};

	while((position = str.find(find)) != std::string::npos)
	{
		str.erase(position, find.size());
		str.insert(position, replace);
	}
}

int Color::getData()
{
	return Color::data;
}

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
			typeData = 2;
			break;
		default:
			return "";
	}
	std::string s = "\033[%type%;%fore%;%back%m";
	replace(s, "%type%", std::to_string(typeData));
	replace(s, "%fore%", std::to_string(foregroundData));
	replace(s, "%back%", std::to_string(backgroundData));
	return s;
}

void Logger::print(char *message[], OutputType type, Color *foreground, Color *background)
{
	printf("%s%s %s%s%s", "\033[0;36m", "[Logger]", formatted(type, foreground->getData(), background->getData()), message, "\033[0m");
}
