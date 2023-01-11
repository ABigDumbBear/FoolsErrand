cmake_minimum_required(VERSION 3.10)
project(FoolsErrand VERSION 0.0.1)

# Set the search path for the Kuma3D library using an environment variable.
set(CMAKE_PREFIX_PATH "$ENV{KUMA3D_INSTALL_DIR}")
find_package(Kuma3D REQUIRED)

# Exports compile commands as a .json file; some text editors use
# this file for syntax highlighting.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INSTALL_DIR "${CMAKE_SOURCE_DIR}/install")
add_subdirectory(source)
