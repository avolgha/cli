/*
 * utility.cpp
 *
 *  Created on: 22 Sept 2021
 *      Author: marius
 */


#include "../head/utility.hpp"

std::string getDefaultHelpMessage()
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

std::string getHomeDir()
{
	struct passwd *pw = getpwuid(getuid());
	return std::string(pw->pw_dir);
}

std::string messageFilePath = getHomeDir() + "/.config/mgc-cli/header.txt";
void createHelpMessageFile()
{
	if (doesFileExists(messageFilePath))
		return;

	std::string msg = getDefaultHelpMessage();
	createFile(messageFilePath, msg);
}

std::string getHelpMessage()
{
	createHelpMessageFile();

	std::string msg = readFile(messageFilePath);
	replace(msg, "&n&", "\n");
	return msg;
}

void lowerCase(std::string &data)
{
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
}

void sendHelp()
{
	std::string helpMessage = getHelpMessage();
	std::cout << helpMessage << "\n";
}

void replace(std::string& str, const std::string& find, const std::string& replace)
{
	std::size_t position{};

	while((position = str.find(find)) != std::string::npos)
	{
		str.erase(position, find.size());
		str.insert(position, replace);
	}
}

bool doesFileExists(std::string path)
{
	return std::filesystem::exists(std::filesystem::path{path.c_str()});
}

void createParents(std::string& path)
{
	// TODO
}

void createFile(std::string& path, std::string& content)
{
	if (doesFileExists(path)) return;

	createParents(path);

	FILE* outFile = fopen(path.c_str(), "w+");
	if (outFile && content.c_str() != NULL)
	{
		fwrite(content.c_str(), 1, content.size(), outFile);
	}
}

std::string readFile(std::string& path)
{
	std::ifstream inFile;
	inFile.open(path);

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

	return full;
}