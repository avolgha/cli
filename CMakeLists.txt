project (cli)

add_executable(cli 
		               		src/cli.cpp
		src/utility.hpp	
		src/config.hpp
		src/logger.hpp  	src/logger.cpp
		src/parser.hpp  	src/parser.cpp
	)
