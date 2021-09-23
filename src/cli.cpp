#include <iostream>
#include <string>

#include "logger.hpp"
#include "parser.hpp"
#include "utility.hpp"

int main(int argc, char* argv[])
{
	Logger logger;
	Parser parser;

	parser.parse(argc, argv);
	std::string called = parser.getCalled();

	if (called == "help" || called == "h")
	{
		sendHelp();
	} else if (called == "version" || called == "v") 
	{
		
	} else
	{
		logger.error("Unknown command '" + called + "'.");
	}

	return EXIT_SUCCESS;
}
