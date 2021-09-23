cmake_minimum_required (VERSION 2.6)

project (cli)

add_executable(cli 
		               		src/cli.cpp
		src/logger.hpp  	src/logger.cpp
		src/parser.hpp  	src/parser.cpp
		src/utility.hpp	
		src/config.hpp
	)
