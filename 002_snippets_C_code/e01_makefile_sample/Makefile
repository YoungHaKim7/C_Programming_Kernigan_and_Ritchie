# Makefile for Pointers and Arrays examples
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Target files
MAIN_TARGET = target/pointers_and_arrays
TEST_TARGET = target/test_pointers_arrays

# Source files
MAIN_SOURCE = src/pointers_and_arrays.c
TEST_SOURCE = src/test_pointers_arrays.c

# Default target
all: $(MAIN_TARGET) $(TEST_TARGET)

# Build main example
$(MAIN_TARGET): $(MAIN_SOURCE)
	mkdir -p target
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_SOURCE)

# Build test program
$(TEST_TARGET): $(TEST_SOURCE)
	mkdir -p target
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SOURCE)

# Run main example
run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -rf target

# Show help
help:
	@echo "Available targets:"
	@echo "  all   - Build both main program and tests"
	@echo "  run   - Build and run the main example program"
	@echo "  test  - Build and run the test suite"
	@echo "  clean - Remove built files"
	@echo "  help  - Show this help message"

.PHONY: all run test clean help
