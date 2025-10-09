cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

# Force GCC 15(LinuxOS)
# set(CMAKE_CXX_COMPILER "/opt/gcc-15/bin/g++")
# Force Clang 20(LinuxOS)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++-21")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenMP
find_package(OpenMP REQUIRED)

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -lm
    -Wall
    -Wextra
    -ggdb
    # -Wdangling  # clang option
)

# Main executable with main.cpp sources
add_executable(${ProjectId}
    src/main.cpp
    # src/mandelbrot.cpp
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)
target_link_libraries(${ProjectId} PRIVATE OpenMP::OpenMP_CXX)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)


