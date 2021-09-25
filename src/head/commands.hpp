/*
 * commands.hpp
 *
 * 	Created on: 24 Sept 2021
 * 	    Author: marius
 */

#ifndef SRC_COMMANDS_HPP_
#define SRC_COMMANDS_HPP_

#include <string>
#include <vector>

#include "logger.hpp"
#include "parser.hpp"

void process_generate(Parser parser);
void process_unknown(Parser parser);

void process(Parser& parser);

#endif /* SRC_COMMANDS_HPP_ */
