/*
 * json.cpp
 *
 *  Created on: 1 Octo 2021
 *      Author: marius
 */


#include "../head/json.hpp"

Json::Value cli::json::parseJson(std::string& content)
{
    Json::Value root;
    Json::Reader reader;

    bool parsingState = reader.parse(content, root);
    if (parsingState)
        return root;
    else
        return NULL;
}