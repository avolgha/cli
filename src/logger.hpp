/*
 * logger.hpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */

#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_

#include <string>

enum OutputType
{
	NORMAL, BOLD, UNDERLINE
};

std::string formatted(OutputType type, int *foregroundData, int *backgroundData);

class Color
{
public:
	Color(int data)
	{
		Color::data = data;
	}

	int getData();
private:
	int data;
};

class Logger
{
public:
	void info(char* message[]);
	void debug(char* message[]);
	void warn(char* message[]);
	void error(char* message[]);
	void print(char *message[], OutputType type, Color *foreground, Color *background);
};


#endif /* SRC_LOGGER_HPP_ */
