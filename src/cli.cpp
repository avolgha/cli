/*
 * cli.cpp
 *
 *  Created on: 20 Sept 2021
 *      Author: marius
 */


#include <string>

#include "head/commands.hpp"
#include "head/logger.hpp"
#include "head/parser.hpp"
#include "head/utility.hpp"

int main(int argc, char* argv[])
{
	cli::logger::Logger logger;
	cli::parser::Parser parser;

	parser.parse(argc, argv);
	std::string called = parser.getCalled();

	if (called == "help" || called == "h")
	{
		cli::utility::help::sendHelp();
	} else if (called == "version" || called == "v") 
	{
		std::cout << "Running cli v0.0.1\n";
	} else
	{
		bool error = !cli::commands::process(parser);
		if (error || (error && called == "")) {
			logger.error("Unknown command '" + called + "'.");
		}
	}

	return EXIT_SUCCESS;
}
