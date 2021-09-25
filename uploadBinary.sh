#!/bin/bash

##
## Author: Marius ( github.com/avolgha )
## Date: 25. Sep, 2021
## Project: CLI
##

# store the old location from where this script was executed from
# this is used to redirect the user to this location as the script
# has ended
last_seen="$PWD"
cd '/home/marius/work/cli'

# Run the build script to build the binary file
./build.sh

# Run the upload script to upload the binary file to github
python ./tools/uploadBinary.py $*

# Finish
cd "$last_seen"
