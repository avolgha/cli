/*
 * parser.cpp
 *
 *  Created on: 22 Sept 2021
 *      Author: marius
 */


#include "../head/parser.hpp"

void cli::parser::Parser::parse(int argc, char *argv[])
{
	if (argc == 1)
	{
		cli::utility::help::sendHelp();
	} else 
	{
		std::string call(argv[1]);
		cli::utility::lowerCase(call);
		Parser::called = call;

		if (argc >= 3)
		{
			for (int i=2;i<argc;++i)
			{
				std::string add(argv[i]);
				if (Parser::other == "")
				{
					Parser::other = add;
				} else
				{
					Parser::other = Parser::other + " " + add;
				}
			}
		} else
		{
			Parser::other = "";
		}
	}
}
