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

Logger projectLogger;

void cf(std::string path, std::string content)
{
    createFile(path, content);
}

void ccf(std::string name, std::string main, std::string mainContent)
{
    std::string lname = name;
    lowerCase(lname);
    cf(name + "/CMakeLists.txt", "project (" + lname + ")\
\
add_executable(" + lname+ " src/" + main + ")");
    cf(name + "/src/" + main, mainContent);
}

void createProject(std::string& name, std::string& lang, std::string& tool)
{
    if (lang == "java") 
    {
        if (tool != "none")
        {
            projectLogger.warn("Currently there aren't any build systems for Java. Please don't provide any.");
        }

        cf(name + "/src/com/example/test/Main.java", "package com.example.test;\
\
public class Main {\
    public static void main(String[] args) { \
        System.out.println(\"Hey :)\");\
    }\
");
        cf(name + "/README.md", "# " + name + " Project\
\
> Example README");
        projectLogger.info("Created project '" + name + "'.");
    } else if (lang == "javascript" || lang == "js")
    {
        if (tool == "nodejs")
        {
            cf(name + "/package.json", "{\
    \"name\": \"" + name + "\",\
    \"version\": \"0.0.1\",\
    \"main\": \"src/main.js\",\
    \"scripts\": {\
        \"start\": \"node .\"\
    }\
}");
            cf(name + "/src/main.js", "console.log(\"Hey :)\");");
            cf(name + "/README.md", "# " + name + " Project\
\
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
            cf(name + "/package.json", "{\
    \"name\": \"" + name + "\",\
    \"version\": \"0.0.1\",\
    \"main\": \"dist/main.js\",\
    \"scripts\": {\
        \"start\": \"node .\",\
        \"compile\": \"tsc\",\
        \"dev\": \"tsc && node.\"\
    },\
    \"devDependencies\": {\
        \"typescript\": \"^4.4.3\"\
    }\
}");
            cf(name + "/src/main.ts", "console.log(\"Hey :)\");");
            cf(name + "/README.md", "# " + name + " Project\
\
> Example README");
            cf(name + "/tsconfig.json", "{\
    \"compilerOptions\": {\
        \"target\": \"es5\",\
        \"module\": \"commonjs\",\
        \"declaration\": true,\
        \"outDir\": \"./build\",\
        \"rootDir\": \"./src\",\
        \"strict\": true,\
        \"esModuleInterop\": true,\
        \"skipLibCheck\": true,\
        \"forceConsistentCasingInFileNames\": true\
    }\
}");
            projectLogger.info("Created project '" + name + "'.");
        } else
        {
            projectLogger.error("Unknown tool: '" + tool + "'.");
        }
    } else if (lang == "cpp" || lang == "cmake")
    {
        std::string lname = name;
        lowerCase(lname);
        ccf(name, lname + ".cpp", "#include <iostream>\
\
int main(int argc, char **argv)\
{\
    std::cout << \"Hey :)\" << std::endl;\
    return 0;\
}");
        projectLogger.info("Created project '" + name + "'.");
    } else if (lang == "c")
    {
        std::string lname = name;
        lowerCase(lname);
        ccf(name, lname + ".c", "#include <iostream>\
\
int main(int argc, char **argv)\
{\
    std::cout << \"Hey :)\" << std::endl;\
    return 0;\
}");
        projectLogger.info("Created project '" + name + "'.");
    }
}