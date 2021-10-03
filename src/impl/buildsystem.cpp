/*
 * buildsystem.cpp
 *
 *  Created on: 3 Octo 2021
 *      Author: marius
 */

#include "../head/buildsystem.hpp"

using namespace cli::utility::fs;

cli::logger::Logger bLogger;

/**
package.json                        --> javascript
    "typescript" && "tsconfig.json" --> typescript
CMakeLists.txt                      --> c/c++

*/
void cli::entities::buildsystem::runBuildSystem(std::string& path)
{
    path = path + "/";
    if (doesFileExists(path + "package.json"))
    {
        bLogger.debug("Detected 'package.json'...");

        auto fPath = path + "package.json";
        auto content = readFile(fPath);
        auto packageJson = cli::json::parseJson(content);

        bLogger.debug("Parsed 'package.json'...");

        bool typescript = false;
        if (packageJson.isMember("dependencies"))
        {
            auto dependencies = packageJson["dependencies"];

            if (doesFileExists(path + "tsconfig.json") && dependencies.isMember("typescript"))
            {
                typescript = true;
                bLogger.debug("Found TypeScript...");
            }
        }

        if (typescript)
        {
            auto command = "cd " + path + " && node_modules/.bin/tsc " + path;
            auto result = system(command.c_str());
            if (result != 0) 
            {
                bLogger.error("Could not run typescript compiler!");
                exit(result);
            } else 
            {
                bLogger.info("Compiled typescript!");
            }
        }

        if (packageJson.isMember("scripts"))
        {
            auto scripts = packageJson["scripts"];

            if (scripts.isMember("build"))
            {
                auto command = "cd " + path + " && npm run build";
                auto result = system(command.c_str());
                if (result != 0) 
                {
                    bLogger.error("Could not run build script!");
                    exit(result);
                } else 
                {
                    bLogger.info("Successfully runned build script!");
                }
            } else if (scripts.isMember("compile"))
            {
                auto command = "cd " + path + " && npm run compile";
                auto result = system(command.c_str());
                if (result != 0) 
                {
                    bLogger.error("Could not run compile script!");
                    exit(result);
                } else 
                {
                    bLogger.info("Successfully runned compile script!");
                }
            } else
            {
                bLogger.warn("Cannot run build script because there is no 'build' or 'compile' member in 'scripts'!");
            }
        } else
        {
            bLogger.warn("Cannot run build script because there is no 'scripts' member in 'package.json'!");
        }
    } else if (doesFileExists(path + "CMakeLists.txt"))
    {
        bLogger.debug("Detected 'CMakeLists.txt'...");

        auto cmakebuilddirpath = path + "/__build";
        auto tempFile = cmakebuilddirpath + "/a";
        createParents(tempFile);

        auto command = "cd " + cmakebuilddirpath + " && cmake ..";
        auto result = system(command.c_str());
        if (result != 0) 
        {
            bLogger.error("Could not initialize cmake build dir!");
            exit(result);
        } else 
        {
            bLogger.debug("Successfully initialized cmake build dir...");
        }

        command = "cd " + cmakebuilddirpath + " && cmake --build .";
        result = system(command.c_str());
        if (result != 0) 
        {
            bLogger.error("Could not build project!");
            exit(result);
        } else
        {
            bLogger.debug("Successfully compiled dir!");
        }
    } else
    {
        bLogger.error("Could not resolve build system.");
    }
}