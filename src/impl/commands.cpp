/*
 * commands.cpp
 *
 *  Created on: 24 Sept 2021
 *      Author: marius
 */


#include "../head/commands.hpp"
#include "../head/parser.hpp"
#include "../head/utility.hpp"

cli::logger::Logger commandLogger;

bool is(std::string& reference, std::vector<std::string> check) {
    for (std::string string : check)
    {
        if (reference == string)
            return true;
    }
    return false;
}

std::string getDefaultTool(std::string& lang)
{
    if (lang == "java")
        return "none";
    else if (lang == "javascript" || lang == "js")
        return "nodejs";
    else if (lang == "typescript" || lang == "ts")
        return "nodejs";
    else if (lang == "cpp" || lang == "cmake")
        return "cmake";
    else if (lang == "c")
        return "cmake";
    return "";
}

bool isLanguageSupported(std::string& lang)
{
    return is(lang, std::vector<std::string>{
        "java", 
        "javascript", "js", 
        "typescript", "ts",
        "cpp", "c",
        "cmake"
    });
}

char splitChar = ' ';
void cli::commands::process_generate(cli::parser::Parser parser)
{
    std::string rest = parser.getRest();
    std::vector<std::string> splitted = cli::utility::split(rest, splitChar);

    // cli generate project <name> <lang> [tool] 
    if (splitted.size() == 0)
    {
        std::cout << "Known subcommands:\n\
p[roject]       Generate a project" << "\n";
    } else
    {
        std::string type = splitted.at(0);
        cli::utility::lowerCase(type);
        if (is(type, std::vector<std::string>{"project", "p"}))
        {
            if (splitted.size() == 3 || splitted.size() == 4)
            {
                std::string name = splitted.at(1);
                std::string lang = splitted.at(2);
                std::string tool;
                if (splitted.size() == 4)
                    tool = splitted.at(3);
                else
                {
                    tool = getDefaultTool(lang);
                }

                cli::utility::lowerCase(lang);
                if (!isLanguageSupported(lang))
                {
                    commandLogger.error("Language '" + lang + "' is not supported.");
                    exit(1);
                }

                if (tool == "")
                {
                    commandLogger.error("Unknown tool found for language.");
                    exit(1);
                }

                cli::generator::project::createProject(name, lang, tool);
            } else
            {
                commandLogger.error("Use: cli generate project <name> <lang> [tool]");
            }
        } else
        {
            commandLogger.error("Unknown sub command: '" + type + "'.");
        }
    }
}

bool cli::commands::process(cli::parser::Parser& parser)
{
    std::string called = parser.getCalled();
    if (is(called, std::vector<std::string>{"generate", "g"}))
    {
        cli::commands::process_generate(parser);
        return true;
    } else if (is(called, std::vector<std::string>{"build", "compile", "b", "c"}))
    {
        std::string dir = cli::utility::cwd();
        cli::entities::buildsystem::runBuildSystem(dir);
        return true;
    }
    return false;
}