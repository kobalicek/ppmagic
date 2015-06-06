#!/bin/sh

CURRENT_DIR=`pwd`
BUILD_DIR="build_makefiles_rel"

mkdir ../${BUILD_DIR}
cd ../${BUILD_DIR}
cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cd ${CURRENT_DIR}
