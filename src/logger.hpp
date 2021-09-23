/*
 * logger.hpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */

#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_

#include <string>
#include "utility.hpp"

enum OutputType
{
	NORMAL, BOLD, UNDERLINE
};

class Color
{
public:
	Color(int data)
	{
		Color::data = data;
	}

	int getData()
	{
		return Color::data;
	}
private:
	int data;
};

class Logger
{
public:
	void info(std::string message)
	{
		std::string s = "[Info]  %m%";
		replace(s, "%m%", message);
		print(s, OutputType::NORMAL, new Color(32), NULL);
	}
	void debug(std::string message)
	{
		std::string s = "[Debug] %m%";
		replace(s, "%m%", message);
		print(s, OutputType::NORMAL, new Color(36), NULL);
	}
	void warn(std::string message)
	{
		std::string s = "[Warn]  %m%";
		replace(s, "%m%", message);
		print(s, OutputType::BOLD, new Color(33), NULL);
	}
	void error(std::string message)
	{
		std::string s = "[Error] %m%";
		replace(s, "%m%", message);
		print(s, OutputType::UNDERLINE, new Color(31), NULL);
	}
	void print(std::string message, OutputType type, Color *foreground, Color *background);
};

std::string formatted(OutputType type, int *foregroundData, int *backgroundData);

#endif /* SRC_LOGGER_HPP_ */
