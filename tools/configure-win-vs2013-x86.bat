@echo off

set CURRENT_DIR=%CD%
set BUILD_DIR="build_vs2013_x86"

mkdir ..\%BUILD_DIR%
cd ..\%BUILD_DIR%
cmake .. -G"Visual Studio 12"
cd %CURRENT_DIR%
