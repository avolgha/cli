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

void lowerCase(std::string &data)
{
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
}

#endif /* SRC_UTILITY_HPP_ */
