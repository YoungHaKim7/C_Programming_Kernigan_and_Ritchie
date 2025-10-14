cmake_minimum_required(VERSION 4.0)

# Enable C++23 modules support BEFORE project() call
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

# Force GCC 15(LinuxOS)
# set(CMAKE_CXX_COMPILER "/opt/gcc-15/bin/g++")
# Force Clang 20(LinuxOS)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-21")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -Wall
    -Wextra
    -ggdb
    # Enable C++23 modules (automatically enabled with -std=c++23)
    -fmodules
    # -Wdangling  # clang option
)

# Main executable with sources
add_executable(${ProjectId}
    src/std_import.cppm
    src/main.cpp
)

# Set up module support
target_sources(${ProjectId} PRIVATE
    FILE_SET CXX_MODULES FILES
    src/std_import.cppm
)

# Set properties for the executable to support modules
set_target_properties(${ProjectId} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)

target_link_options(${ProjectId} PRIVATE -pthread)
target_link_libraries(${ProjectId} PRIVATE m)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)


