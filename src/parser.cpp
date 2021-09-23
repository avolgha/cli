#include "config.hpp"
#include "parser.hpp"
#include "utility.hpp"

#include <iostream>

void sendHelp()
{
	/*std::string helpMessage = "\
CLI-Helper for many things\
\
| Created by avolgha, 2021 |\
\
 Commands\
 	help [command]       look at the help message of an specific command or for the program in general\
";*/

	std::string helpMessage = getHelpMessage();
	std::cout << helpMessage << "\n";
}

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
