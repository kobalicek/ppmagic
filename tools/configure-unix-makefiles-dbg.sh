#!/bin/sh

CURRENT_DIR=`pwd`
BUILD_DIR="build_makefiles_dbg"

mkdir ../${BUILD_DIR}
cd ../${BUILD_DIR}
cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
cd ${CURRENT_DIR}
