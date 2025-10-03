#!/bin/bash

# Test runner script for strlen implementation project

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    local status=$1
    local message=$2
    case $status in
        "INFO")
            echo -e "${BLUE}[INFO]${NC} $message"
            ;;
        "SUCCESS")
            echo -e "${GREEN}[SUCCESS]${NC} $message"
            ;;
        "WARNING")
            echo -e "${YELLOW}[WARNING]${NC} $message"
            ;;
        "ERROR")
            echo -e "${RED}[ERROR]${NC} $message"
            ;;
    esac
}

# Function to check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Function to build the project
build_project() {
    print_status "INFO" "Building project..."
    
    if command_exists make; then
        make clean
        make build
        print_status "SUCCESS" "Project built successfully using Makefile"
    elif command_exists cmake; then
        mkdir -p build
        cd build
        cmake ..
        make
        cd ..
        print_status "SUCCESS" "Project built successfully using CMake"
    else
        print_status "ERROR" "Neither make nor cmake found. Please install one of them."
        exit 1
    fi
}

# Function to run basic tests
run_basic_tests() {
    print_status "INFO" "Running basic strlen comparison tests..."
    
    if [ -f "build/target/a01_strlen_impl" ]; then
        if ./build/target/a01_strlen_impl; then
            print_status "SUCCESS" "Basic tests passed!"
        else
            print_status "ERROR" "Basic tests failed!"
            return 1
        fi
    else
        print_status "ERROR" "Main executable not found. Please build first."
        return 1
    fi
}

# Function to run comprehensive tests
run_comprehensive_tests() {
    print_status "INFO" "Running comprehensive test suite..."
    
    if [ -f "build/target/test_strlen" ]; then
        if ./build/target/test_strlen; then
            print_status "SUCCESS" "Comprehensive tests passed!"
        else
            print_status "ERROR" "Comprehensive tests failed!"
            return 1
        fi
    else
        print_status "ERROR" "Test executable not found. Please build first."
        return 1
    fi
}

# Function to run memory tests (if valgrind is available)
run_memory_tests() {
    if command_exists valgrind; then
        print_status "INFO" "Running memory tests with valgrind..."
        
        if [ -f "build/target/test_strlen" ]; then
            valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
                     --verbose --log-file=valgrind_output.txt \
                     ./build/target/test_strlen
            
            if grep -q "ERROR SUMMARY: 0 errors" valgrind_output.txt; then
                print_status "SUCCESS" "Memory tests passed!"
                rm -f valgrind_output.txt
            else
                print_status "ERROR" "Memory leaks detected! Check valgrind_output.txt"
                return 1
            fi
        else
            print_status "ERROR" "Test executable not found. Please build first."
            return 1
        fi
    else
        print_status "WARNING" "Valgrind not found. Skipping memory tests."
    fi
}

# Function to run performance tests
run_performance_tests() {
    print_status "INFO" "Running performance tests..."
    
    if [ -f "build/target/a01_strlen_impl" ]; then
        echo "Performance comparison (this may take a moment)..."
        ./build/target/a01_strlen_impl | grep -A 10 "PERFORMANCE COMPARISON"
        print_status "SUCCESS" "Performance tests completed!"
    else
        print_status "ERROR" "Main executable not found. Please build first."
        return 1
    fi
}

# Function to run all tests
run_all_tests() {
    print_status "INFO" "Running all tests..."
    
    local failed=0
    
    if ! run_basic_tests; then
        failed=1
    fi
    
    echo ""
    if ! run_comprehensive_tests; then
        failed=1
    fi
    
    echo ""
    if ! run_memory_tests; then
        failed=1
    fi
    
    echo ""
    if ! run_performance_tests; then
        failed=1
    fi
    
    if [ $failed -eq 0 ]; then
        print_status "SUCCESS" "All tests completed successfully!"
    else
        print_status "ERROR" "Some tests failed!"
        exit 1
    fi
}

# Function to show help
show_help() {
    echo "Usage: $0 [OPTION]"
    echo ""
    echo "Options:"
    echo "  build      Build the project"
    echo "  basic      Run basic strlen comparison tests"
    echo "  test       Run comprehensive test suite"
    echo "  memory     Run memory tests with valgrind"
    echo "  perf       Run performance tests"
    echo "  all        Run all tests (default)"
    echo "  clean      Clean build directory"
    echo "  help       Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0              # Run all tests"
    echo "  $0 build        # Build the project"
    echo "  $0 basic        # Run basic tests only"
    echo "  $0 test         # Run comprehensive tests"
}

# Main script logic
case "${1:-all}" in
    "build")
        build_project
        ;;
    "basic")
        run_basic_tests
        ;;
    "test")
        run_comprehensive_tests
        ;;
    "memory")
        run_memory_tests
        ;;
    "perf")
        run_performance_tests
        ;;
    "all")
        build_project
        echo ""
        run_all_tests
        ;;
    "clean")
        print_status "INFO" "Cleaning build directory..."
        rm -rf build/
        print_status "SUCCESS" "Build directory cleaned!"
        ;;
    "help")
        show_help
        ;;
    *)
        print_status "ERROR" "Unknown option: $1"
        show_help
        exit 1
        ;;
esac