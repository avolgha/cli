#!/bin/bash

last_seen="$PWD"
cd '/home/marius/work/cli'

./build.sh

python ./tools/uploadBinary.py $*

cd "$last_seen"
