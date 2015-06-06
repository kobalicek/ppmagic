@echo off

set CURRENT_DIR=%CD%
set BUILD_DIR="build_mingw_dbg"

mkdir ..\%BUILD_DIR%
cd ..\%BUILD_DIR%
cmake .. -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
cd %CURRENT_DIR%
