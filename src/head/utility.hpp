/*
 * utility.hpp
 *
 * 	Created on: 22 Sept 2021
 * 	    Author: marius
 */

#ifndef SRC_UTILITY_HPP_
#define SRC_UTILITY_HPP_

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <pwd.h>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

namespace cli::utility
{
    std::string getHomeDir();
    std::string cwd();
    void lowerCase(std::string &data);
    void replace(std::string& str, const std::string& find, const std::string& replace);
    std::vector<std::string> split(std::string& string, char& splitChar);
}

namespace cli::utility::help
{
    std::string getDefaultHelpMessage();
    void createHelpMessageFile();
    std::string getHelpMessage();
    void sendHelp();
}

namespace cli::utility::fs
{
    bool doesFileExists(std::string path);
    void createParents(std::string& path);
    void createFile(std::string& path, std::string& content);
    std::string readFile(std::string& path);
}

#endif /* SRC_UTILITY_HPP_ */
