/*
 * json.hpp
 *
 * 	Created on: 1 Octo 2021
 * 	    Author: marius
 */

#ifndef SRC_JSON_HPP_
#define SRC_JSON_HPP_

#include <string>

#include "../lib/json/json.h"

namespace cli::json
{
    Json::Value parseJson(std::string& content);
}

#endif /* SRC_JSON_HPP_ */
