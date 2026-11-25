cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES C OBJC)
# Enable Objective-C
enable_language(OBJC)

# Force GCC 15(LinuxOS)
# set(CMAKE_C_COMPILER "/opt/gcc-15/bin/gcc")
# Force GCC 15(macOS)
# set(CMAKE_C_COMPILER "/opt/homebrew/opt/gcc@15/bin/gcc-15")
# Force Clang 20(LinuxOS)
# set(CMAKE_C_COMPILER "/usr/bin/clang-20")
# Force Clang 20(macOS)
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -Wall
    -Wextra
    -ggdb
    # -std=c23
)

# Main executable with Objective-C sources
add_executable(${ProjectId}
    src/main.m
    src/util.c
    # src/add_source.m
)

target_link_options(${ProjectId} PRIVATE -framework Foundation)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)
