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
#include <string>
#include <sys/types.h>
#include <unistd.h>

std::string getDefaultMessage();
std::string getHomeDir();
void createHelpMessageFile();
std::string getHelpMessage();
void lowerCase(std::string &data);
void sendHelp();
void replace(std::string& str, const std::string& find, const std::string& replace);
bool doesFileExists(std::string path);
void createParents(std::string& path);
void createFile(std::string& path, std::string& content);
std::string readFile(std::string& path);

#endif /* SRC_UTILITY_HPP_ */
