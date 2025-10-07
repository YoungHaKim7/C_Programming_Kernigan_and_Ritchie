cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES C)

# Force GCC 15(LinuxOS)
# set(CMAKE_C_COMPILER "/opt/gcc-15/bin/gcc")
# Force GCC 15(macOS)
set(CMAKE_C_COMPILER "/opt/homebrew/opt/gcc@15/bin/gcc-15")
# Force Clang 20(LinuxOS)
# set(CMAKE_C_COMPILER "/usr/bin/clang-20")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
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
    src/strlen_impl.c
    # src/mandelbrot.c
)

# Test executable
add_executable(test_strlen
    src/test_strlen.c
    src/strlen_impl.c
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)
target_link_options(test_strlen PRIVATE -pthread -lm)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

set_target_properties(test_strlen PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

# Enable tests
enable_testing()
add_test(NAME run_${ProjectId} COMMAND ${ProjectId})
add_test(NAME run_test_strlen COMMAND test_strlen)

# Validation checks for main program
set_tests_properties(run_${ProjectId} PROPERTIES
    PASS_REGULAR_EXPRESSION
    "🎉 All implementations produce identical results!"
)

# Validation checks for test program
set_tests_properties(run_test_strlen PROPERTIES
    PASS_REGULAR_EXPRESSION
    "🎉 All tests passed!"
)
