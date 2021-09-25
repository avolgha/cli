/*
 * commands.cpp
 *
 *  Created on: 24 Sept 2021
 *      Author: marius
 */


#include "../head/commands.hpp"
#include "../head/parser.hpp"

Logger logger;

void process_generate(Parser parser)
{}

void process_unknown(Parser parser)
{
    logger.error("Unknown command: '" + parser.getCalled() + "'.");
}

bool is(std::string& reference, std::vector<std::string> check) {
    for (std::string string : check)
    {
        if (reference == string)
            return true;
    }
    return false;
}

void process(Parser& parser)
{
    std::string called = parser.getCalled();
    if (is(called, std::vector<std::string>{"generate", "g"}))
        process_generate(parser);
    else
        process_unknown(parser);
}