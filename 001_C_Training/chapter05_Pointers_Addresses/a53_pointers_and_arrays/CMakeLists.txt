cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES C)

# Force GCC 15(LinuxOS)
# set(CMAKE_C_COMPILER "/opt/gcc-15/bin/gcc")
# Force GCC 15(macOS)
# set(CMAKE_C_COMPILER "/opt/homebrew/opt/gcc@15/bin/gcc-15")
# Force Clang 20(LinuxOS)
# set(CMAKE_C_COMPILER "/usr/bin/clang-20")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET (CMAKE_C_FLAGS_INIT                "-Wall -std=c23")
SET (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET (CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++23")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -lm
    -Wall
    -Wextra
    -ggdb
    # -std=c23
)

# Main executable with C sources
add_executable(${ProjectId}
    src/main.c
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)

# Test executable for pointers and arrays
add_executable(test_pointers_arrays
    tests/test_pointers_arrays.c
)

target_link_options(test_pointers_arrays PRIVATE -pthread -lm)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

set_target_properties(test_pointers_arrays PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

# Enable testing
enable_testing()

# Add test to CTest
add_test(NAME pointers_arrays_test COMMAND test_pointers_arrays)
