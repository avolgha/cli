project (cli)

add_executable(cli 
		src/head/utility.hpp	src/impl/utility.cpp
		src/head/logger.hpp  	src/impl/logger.cpp
		src/head/commands.hpp	src/impl/commands.cpp
		src/head/parser.hpp  	src/impl/parser.cpp

		src/head/generator/project.hpp    src/impl/generator/project.cpp

				    		    
								src/cli.cpp
	)
