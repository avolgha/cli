cmake_minimum_required (VERSION 2.6)

project (cli)

add_executable(cli 
		src/cli.cpp
		src/logger.cpp src/logger.hpp
		src/parser.cpp src/parser.hpp
				       src/utility.hpp	
	)
