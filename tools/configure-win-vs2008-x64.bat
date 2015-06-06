@echo off

set CURRENT_DIR=%CD%
set BUILD_DIR="build_vs2008_x64"

mkdir ..\%BUILD_DIR%
cd ..\%BUILD_DIR%
cmake .. -G"Visual Studio 9 2008 Win64"
cd %CURRENT_DIR%
