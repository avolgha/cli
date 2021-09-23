/*
 * utility.hpp
 *
 * 	Created on: 22 Sept 2021
 * 	    Author: marius
 */

#ifndef SRC_UTILITY_HPP_
#define SRC_UTILITY_HPP_

#include <algorithm>
#include <cctype>
#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void lowerCase(std::string &data)
{
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
}

struct passwd *pw = getpwuid(getuid());
std::string getHomeDir()
{
	return std::string(pw->pw_dir);
}

#endif /* SRC_UTILITY_HPP_ */
