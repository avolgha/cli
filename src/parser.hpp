/*
 * parser.hpp
 *
 *  Created on: 22 Sept 2021
 *      Author: marius
 */

#ifndef SRC_PARSER_HPP_
#define SRC_PARSER_HPP_

#include <string>
#include <vector>

struct Argument
{
	std::string name;
	std::string description;
	void* callback;	
};

class Parser
{
public:
	void addArgument(std::string name, std::string description, void* callback)
	{
		Argument argument = {
			name,
			description,
			callback
		};

		arguments.push_back(argument);
	}

	std::string getCalled()
	{
		return Parser::called;
	}

	std::string getRest()
	{
		return Parser::other;
	}

	void parse(int argc, char* argv[]);
private:
	std::string called;
	std::string other;
	std::vector<Argument> arguments;
};

#endif /* SRC_PARSER_HPP_ */
