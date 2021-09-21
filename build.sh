#!/bin/bash

##
## Author: Marius ( github.com/avolgha )
## Date: 21. Sep, 2021
## Project: CLI
##

# store the old location from where this script was executed from
# this is used to redirect the user to this location as the script
# has ended
last_seen="$PWD"
cd '/home/marius/work/cli'

# remove the builddir folder if exists and create a new one
if [ -d 'builddir' ]; then
	rm -r builddir
fi
mkdir builddir
cd builddir

# Run cmake build process
cmake -DCMAKE_C_FLAGS='-fpermissive' ..
cmake --build .

# Finish
cd "$last_seen"
