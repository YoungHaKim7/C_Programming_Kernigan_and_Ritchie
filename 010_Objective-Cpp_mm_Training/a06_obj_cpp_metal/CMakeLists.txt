cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Objective-C++ standard
set(CMAKE_OBJCXX_STANDARD 20)
set(CMAKE_OBJCXX_STANDARD_REQUIRED ON)
set(CMAKE_OBJCXX_EXTENSIONS OFF)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX OBJC)
# Enable Objective-C
enable_language(OBJCXX)

# Force GCC 15(LinuxOS)
# set(CMAKE_C_COMPILER "/opt/gcc-15/bin/gcc")
# Force GCC 15(macOS)
# set(CMAKE_C_COMPILER "/opt/homebrew/opt/gcc@15/bin/gcc-15")
# Force Clang 20(LinuxOS)
# set(CMAKE_C_COMPILER "/usr/bin/clang-20")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

# Common compile flags
add_compile_options(
    -pedantic
    -pedantic-errors
    -Wall
    -Wextra
    # -std=c23
)

# Main executable with Objective-C sources
add_executable(${ProjectId}
    src/main.mm
    # src/add_source.m
)

# Threads
find_package(Threads REQUIRED)

# macOS frameworks
if(APPLE)
    target_link_libraries(${ProjectId} PRIVATE
        "-framework Foundation"
    )
    find_library(METAL_FW      Metal      REQUIRED)
    find_library(FOUNDATION_FW Foundation REQUIRED)
    target_link_libraries(${ProjectId} PRIVATE
        ${METAL_FW} ${FOUNDATION_FW}
    )
endif()

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/$<LOWER_CASE:$<CONFIG>>"
)
