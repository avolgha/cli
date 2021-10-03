cmake_minimum_required(VERSION 3.21.3)
project (cli)

set(CMAKE_C_FLAGS "-Wdeprecated-declarations -fpermissive")

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(cli 
		# JSONCPP library files
		src/lib/json/allocator.h
		src/lib/json/assertions.h
		src/lib/json/config.h
		src/lib/json/forwards.h
		src/lib/json/json_features.h
		src/lib/json/json_tool.h
		src/lib/json/json_valueiterator.inl
		src/lib/json/json.h
		src/lib/json/reader.h
		src/lib/json/value.h
		src/lib/json/version.h
		src/lib/json/writer.h

		src/lib/json/json_reader.cpp
		src/lib/json/json_value.cpp
		src/lib/json/json_writer.cpp

		# cli project files
		src/head/utility.hpp	src/impl/utility.cpp

		src/head/json.hpp       src/impl/json.cpp
		src/head/web.hpp        src/impl/web.cpp

		src/head/logger.hpp  	src/impl/logger.cpp
		src/head/commands.hpp	src/impl/commands.cpp
		src/head/parser.hpp  	src/impl/parser.cpp

		src/head/buildsystem.hpp          src/impl/buildsystem.cpp
		
		src/head/generator/project.hpp    src/impl/generator/project.cpp

				    		
		# main files
								src/cli.cpp
	)