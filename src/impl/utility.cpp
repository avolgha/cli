/*
 * utility.cpp
 *
 *  Created on: 22 Sept 2021
 *      Author: marius
 */


#include "../head/utility.hpp"

std::string cli::utility::help::getDefaultHelpMessage()
{
	return "\n\
CLI-Helper for many things&n&\n\
&n&\n\
| Created by avolga, 2021 |&n&\n\
&n&\n\
 Commands&n&\n\
    help [command]      help message of command or program in general&n&\n\
	version             prints the version of the current running application&n&\n\
";
}

std::string cli::utility::getHomeDir()
{
	struct passwd *pw = getpwuid(getuid());
	return std::string(pw->pw_dir);
}

std::string messageFilePath = cli::utility::getHomeDir() + "/.config/mgc-cli/header.txt";
void cli::utility::help::createHelpMessageFile()
{
	if (cli::utility::fs::doesFileExists(messageFilePath))
		return;

	std::string msg = getDefaultHelpMessage();
	cli::utility::fs::createFile(messageFilePath, msg);
}

std::string cli::utility::help::getHelpMessage()
{
	cli::utility::help::createHelpMessageFile();

	std::string msg = cli::utility::fs::readFile(messageFilePath);
	replace(msg, "&n&", "\n");
	return msg;
}

void cli::utility::lowerCase(std::string &data)
{
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
}

void cli::utility::help::sendHelp()
{
	std::string helpMessage = cli::utility::help::getHelpMessage();
	std::cout << helpMessage << "\n";
}

void cli::utility::replace(std::string& str, const std::string& find, const std::string& replace)
{
	std::size_t position{};

	while((position = str.find(find)) != std::string::npos)
	{
		str.erase(position, find.size());
		str.insert(position, replace);
	}
}

bool cli::utility::fs::doesFileExists(std::string path)
{
	return std::filesystem::exists(std::filesystem::path{path.c_str()});
}

void cli::utility::fs::createParents(std::string& path)
{
	int lastIndex = path.find_last_of('/');
	std::string parents = path.substr(0, lastIndex);
	std::filesystem::create_directories(std::filesystem::path{parents.c_str()});
}

void cli::utility::fs::createFile(std::string& path, std::string& content)
{
	if (doesFileExists(path)) return;

	createParents(path);

	FILE* outFile = fopen(path.c_str(), "w+");
	if (outFile && content.c_str() != NULL)
	{
		fwrite(content.c_str(), 1, content.size(), outFile);
	}
}

std::string cli::utility::fs::readFile(std::string& path)
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

std::vector<std::string> cli::utility::split(std::string& string, char& splitChar)
{
	std::vector<std::string> strings;
	std::istringstream stream(string);

	std::string current;
	while (std::getline(stream, current, splitChar))
	{
		strings.push_back(current);
	}

	return strings;
}