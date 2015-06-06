@echo off

set CURRENT_DIR=%CD%
set BUILD_DIR="build_vs2005_x64"

mkdir ..\%BUILD_DIR%
cd ..\%BUILD_DIR%
cmake .. -G"Visual Studio 8 2005 Win64"
cd %CURRENT_DIR%
