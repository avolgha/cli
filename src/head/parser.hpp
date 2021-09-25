/*
 * parser.hpp
 *
 *  Created on: 22 Sept 2021
 *      Author: marius
 */

#ifndef SRC_PARSER_HPP_
#define SRC_PARSER_HPP_

#include <string>

#include "utility.hpp"

class Parser
{
public:
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
};

#endif /* SRC_PARSER_HPP_ */