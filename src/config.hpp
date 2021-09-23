/*
 * config.hpp
 *
 * 	Created on: 23 Sept 2021
 * 	    Author: marius
 */

#ifndef SRC_CONFIG_HPP_
#define SRC_CONFIG_HPP_

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

#include "logger.hpp"
#include "utility.hpp"

namespace fs = std::filesystem;

std::string messageFilePath = getHomeDir() + "/.config/mgc-cli/header.txt";

std::string getDefaultMessage()
{
	return "\n\
CLI-Helper for many things&n&\n\
&n&\n\
| Created by avolga, 2021 |&n&\n\
&n&\n\
 Commands&n&\n\
    help [command]      help message of command or program in general&n&\n\
";
}

bool doesHelpMessageFileExists()
{
	return fs::exists(fs::path{messageFilePath.c_str()});
}

void createHelpMessageFile()
{
	if (doesHelpMessageFileExists())
		return;

	fs::path dirPath{
		getHomeDir() + "/.config/mgc-cli"
	};
	if (!fs::exists(dirPath))
	{
		fs::create_directory(dirPath);
	}

	FILE* outFile = fopen(messageFilePath.c_str(), "w+");
	if (outFile)
	{
		std::string msg = getDefaultMessage();
		fwrite(msg.c_str(), 1, msg.size(), outFile);
	} else
	{
		std::cout << "Couldn't write default help file" << "\n";
	}
}

std::string getHelpMessage()
{
	createHelpMessageFile();

	std::ifstream inFile;
	inFile.open(messageFilePath);

	std::string full;
	std::string current;

	if (inFile.is_open())
	{
		while (inFile >> current) 
		{
			if (full == "")
			{
				full = current;
			} else 
			{
				full = full + " " + current;
			}
		}
	} else
	{
		full = "Couldn't open file";
	}

	replace(full, "&n&", "\n");
	return full;
}

#endif /* SRC_CONFIG_HPP_ */
