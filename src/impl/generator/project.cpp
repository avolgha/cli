/*
 * project.cpp
 *
 *  Created on: 25 Sept 2021
 *      Author: marius
 */


#include "../../head/commands.hpp"
#include "../../head/logger.hpp"
#include "../../head/utility.hpp"
#include "../../head/generator/project.hpp"

cli::logger::Logger projectLogger;

void cf(std::string path, std::string content)
{
    cli::utility::fs::createFile(path, content);
}

void ccf(std::string name, std::string main, std::string mainContent)
{
    std::string lname = name;
    cli::utility::lowerCase(lname);
    cf(name + "/CMakeLists.txt", "project (" + lname + ")\n\
\n\
add_executable(" + lname+ " src/" + main + ")");
    cf(name + "/src/" + main, mainContent);
}

void cli::generator::project::createProject(std::string& name, std::string& lang, std::string& tool)
{
    if (lang == "java") 
    {
        if (tool != "none")
        {
            projectLogger.warn("Currently there aren't any build systems for Java. Please don't provide any.");
        }

        cf(name + "/src/com/example/test/Main.java", "package com.example.test;\n\
\n\
public class Main {\n\
    public static void main(String[] args) { \n\
        System.out.println(\"Hey :)\");\n\
    }\n\
}");
        cf(name + "/README.md", "# " + name + " Project\n\
\n\
> Example README");
        projectLogger.info("Created project '" + name + "'.");
    } else if (lang == "javascript" || lang == "js")
    {
        if (tool == "nodejs")
        {
            cf(name + "/package.json", "{\n\
    \"name\": \"" + name + "\",\n\
    \"version\": \"0.0.1\",\n\
    \"main\": \"src/main.js\",\n\
    \"scripts\": {\n\
        \"start\": \"node .\"\n\
    }\n\
}");
            cf(name + "/src/main.js", "console.log(\"Hey :)\");");
            cf(name + "/README.md", "# " + name + " Project\n\
\n\
> Example README");
            projectLogger.info("Created project '" + name + "'.");
        } else
        {
            projectLogger.error("Unknown tool: '" + tool + "'.");
        }
    } else if (lang == "typescript" || lang == "ts") 
    {
        if (tool == "nodejs")
        {
            cf(name + "/package.json", "{\n\
    \"name\": \"" + name + "\",\n\
    \"version\": \"0.0.1\",\n\
    \"main\": \"dist/main.js\",\n\
    \"scripts\": {\n\
        \"start\": \"node .\",\n\
        \"compile\": \"tsc\",\n\
        \"dev\": \"tsc && node.\"\n\
    },\n\
    \"devDependencies\": {\n\
        \"typescript\": \"^4.4.3\"\n\
    }\n\
}");
            cf(name + "/src/main.ts", "console.log(\"Hey :)\");");
            cf(name + "/README.md", "# " + name + " Project\n\
\n\
> Example README");
            cf(name + "/tsconfig.json", "{\n\
    \"compilerOptions\": {\n\
        \"target\": \"es5\",\n\
        \"module\": \"commonjs\",\n\
        \"declaration\": true,\n\
        \"outDir\": \"./build\",\n\
        \"rootDir\": \"./src\",\n\
        \"strict\": true,\n\
        \"esModuleInterop\": true,\n\
        \"skipLibCheck\": true,\n\
        \"forceConsistentCasingInFileNames\": true\n\
    }\n\
}");
            projectLogger.info("Created project '" + name + "'.");
        } else
        {
            projectLogger.error("Unknown tool: '" + tool + "'.");
        }
    } else if (lang == "cpp" || lang == "cmake")
    {
        std::string lname = name;
        cli::utility::lowerCase(lname);
        ccf(name, lname + ".cpp", "#include <iostream>\n\
\n\
int main(int argc, char **argv)\n\
{\n\
    std::cout << \"Hey :)\" << std::endl;\n\
    return 0;\n\
}");
        projectLogger.info("Created project '" + name + "'.");
    } else if (lang == "c")
    {
        std::string lname = name;
        cli::utility::lowerCase(lname);
        ccf(name, lname + ".c", "#include <iostream>\n\
\n\
int main(int argc, char **argv)\n\
{\n\
    std::cout << \"Hey :)\" << std::endl;\n\
    return 0;\n\
}");
        projectLogger.info("Created project '" + name + "'.");
    }
}