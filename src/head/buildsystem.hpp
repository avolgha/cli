/*
 * buildsystem.hpp
 *
 * 	Created on: 3 Octo 2021
 * 	    Author: marius
 */

#ifndef SRC_BUILDSYSTEM_HPP_
#define SRC_BUILDSYSTEM_HPP_

#include <string>

#include "json.hpp"
#include "logger.hpp"
#include "utility.hpp"

namespace cli::entities::buildsystem
{
    void runBuildSystem(std::string& path);
}

#endif /* SRC_BUILDSYSTEM_HPP_ */
