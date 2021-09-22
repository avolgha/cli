#include <iostream>

#include "logger.hpp"
#include "parser.hpp"

int main(int argc, char* argv[])
{
	Logger logger;
	Parser parser;

	parser.parse(argc, argv);
	return 0;
}
