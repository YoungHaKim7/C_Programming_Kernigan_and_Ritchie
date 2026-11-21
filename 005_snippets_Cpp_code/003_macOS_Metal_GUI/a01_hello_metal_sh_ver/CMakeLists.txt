cmake_minimum_required(VERSION 3.21)

project(metal_cpp_hello LANGUAGES CXX)

if(NOT APPLE)
    message(FATAL_ERROR "Apple Metal is available only on Apple platforms.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# The repository root contains Foundation/, Metal/, and QuartzCore/.
set(METAL_CPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH
    "Path to the Apple metal-cpp headers")

foreach(header_dir Foundation Metal QuartzCore)
    if(NOT EXISTS "${METAL_CPP_ROOT}/${header_dir}")
        message(FATAL_ERROR
            "Missing ${header_dir}/ under METAL_CPP_ROOT=${METAL_CPP_ROOT}")
    endif()
endforeach()

find_library(FOUNDATION_FRAMEWORK Foundation REQUIRED)
find_library(METAL_FRAMEWORK Metal REQUIRED)
find_library(QUARTZCORE_FRAMEWORK QuartzCore REQUIRED)

add_executable(metal_cpp_hello
    src/main.cpp
    src/mtl_implementation.cpp
)

target_include_directories(metal_cpp_hello PRIVATE
    "${METAL_CPP_ROOT}"
)

target_compile_options(metal_cpp_hello PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(metal_cpp_hello PRIVATE
    "${FOUNDATION_FRAMEWORK}"
    "${METAL_FRAMEWORK}"
    "${QUARTZCORE_FRAMEWORK}"
)

set_target_properties(metal_cpp_hello PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

