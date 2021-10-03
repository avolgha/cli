/*
 * web.hpp
 *
 * 	Created on: 1 Octo 2021
 * 	    Author: marius
 */

#ifndef SRC_WEB_HPP_
#define SRC_WEB_HPP_

#include <string>

#include <json/json.h>
#include <httplib.h>

#include "json.hpp"

namespace cli::web
{
    std::string makeGetRequest(std::string& url);
    std::string makePostRequest(std::string& url);

    Json::Value makeJsonGetRequest(std::string& url);
}

#endif /* SRC_WEB_HPP_ */
