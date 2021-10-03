/*
 * web.cpp
 *
 *  Created on: 1 Octo 2021
 *      Author: marius
 */


#include "../head/web.hpp"

std::tuple<std::string, std::string> splitUrl(std::string& url)
{
    // invalid connection. only http is allowed
    if (url.rfind("http://") == 0 || url.rfind("https://") == 0)
    {
        std::string first;
        std::string second;

        int index;
        if (url.rfind("http://") == 0)
            index = std::string("http://").length();
        else
            index = std::string("https://").length();
        std::string sub = url.substr(index);

        int firstSlash = sub.find_first_of('/');
        first = url.substr(0, index + firstSlash);
        second = url.substr(index + firstSlash);

        return std::make_tuple(first, second);
    } else
    {
        return std::make_tuple<std::string, std::string>(NULL, NULL);
    }
}

std::string cli::web::makeGetRequest(std::string& url)
{
    std::tuple<std::string, std::string> split = splitUrl(url);
    httplib::Client client(std::get<0>(split));
    httplib::Result result = client.Get(std::get<1>(split).c_str());
    return result->body;
}

std::string cli::web::makePostRequest(std::string& url)
{
    std::tuple<std::string, std::string> split = splitUrl(url);
    httplib::Client client(std::get<0>(split));
    httplib::Result result = client.Post(std::get<1>(split).c_str());
    return result->body;
}

Json::Value cli::web::makeJsonGetRequest(std::string& url)
{
    std::string result = cli::web::makeGetRequest(url);
    return cli::json::parseJson(result);
}