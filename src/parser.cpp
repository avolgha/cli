#include "config.hpp"
#include "parser.hpp"
#include "utility.hpp"

#include <iostream>

void Parser::parse(int argc, char *argv[])
{
	if (argc == 1)
	{
		sendHelp();
	} else 
	{
		std::string call(argv[1]);
		lowerCase(call);
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
