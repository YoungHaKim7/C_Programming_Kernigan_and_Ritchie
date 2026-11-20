cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

# Force GCC 15(LinuxOS)
# set(CMAKE_CXX_COMPILER "/opt/gcc-15/bin/g++")
# Force Clang 20(LinuxOS)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++-21")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

# Common compile flags
# NOTE: -lm is a linker input, not a compiler flag -> removed (was the
#       "'linker' input unused" warning). -pedantic is redundant next to
#       -pedantic-errors. Safe to use -pedantic-errors because Apple's
#       headers are included as SYSTEM below (verified: suppression works
#       even under -pedantic-errors / -Werror).
add_compile_options(
    -pedantic-errors
    -pthread
    -Wall
    -Wextra
    -ggdb
)

# Main executable with C++ sources
add_executable(${ProjectId}
    src/main.cpp
    src/implementation.cpp
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)

if(APPLE)
    find_library(METAL_FW      Metal      REQUIRED)
    find_library(FOUNDATION_FW Foundation REQUIRED)
    find_library(QUARTZCORE_FW QuartzCore REQUIRED)
    target_link_libraries(${ProjectId} PRIVATE
        ${METAL_FW} ${FOUNDATION_FW} ${QUARTZCORE_FW}
    )
endif()

# ---- Fetch metal-cpp into include/metal-cpp ----
include(FetchContent)

FetchContent_Declare(
    metal_cpp
    GIT_REPOSITORY https://github.com/apple/metal-cpp.git
    GIT_TAG        main
    SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/include/metal-cpp"
)
FetchContent_MakeAvailable(metal_cpp)

# SYSTEM => all diagnostics originating inside Apple's headers (anonymous
# structs in MTLAccelerationStructureTypes.hpp etc.) are suppressed.
target_include_directories(${ProjectId} SYSTEM PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/metal-cpp"
)

# ---- Link the frameworks metal-cpp wraps (header-only wrapper, not a lib) ----
# Metal       -> MTLCreateSystemDefaultDevice, MTLCopyAllDevices, MTL*Domain...
# Foundation  -> NS*ErrorDomain, NS*Notification, objc_getProtocol/lookUpClass,
#                sel_registerName (libobjc is re-exported via Foundation)
# QuartzCore  -> CA::MetalLayer, needed as soon as you render into a view
# ---- Link the frameworks metal-cpp wraps ----
# SHELL: prefix prevents CMake from de-duplicating the repeated "-framework"
# token (which broke the link line: "-framework Metal Foundation QuartzCore").
if(APPLE)
    target_link_options(${ProjectId} PRIVATE
        "SHELL:-framework Metal"
        "SHELL:-framework Foundation"
        "SHELL:-framework QuartzCore"
    )
endif()

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/$<LOWER_CASE:$<CONFIG>>"
)
