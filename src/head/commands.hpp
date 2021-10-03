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

#include "buildsystem.hpp"
#include "logger.hpp"
#include "parser.hpp"
#include "utility.hpp"
#include "generator/project.hpp"

namespace cli::commands
{
    void process_generate(cli::parser::Parser parser);

    bool process(cli::parser::Parser& parser);
}

#endif /* SRC_COMMANDS_HPP_ */
