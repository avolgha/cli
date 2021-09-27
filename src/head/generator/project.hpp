/*
 * project.hpp
 *
 * 	Created on: 25 Sept 2021
 * 	    Author: marius
 */

#ifndef SRC_PROJECT_HPP_
#define SRC_PROJECT_HPP_

#include <string>

namespace cli::generator::project
{
    void createProject(std::string& name, std::string& lang, std::string& tool);
}

#endif /* SRC_PROJECT_HPP_ */
