# Makefile for Section 6.2 Structures and Functions examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
MAIN_SRC = src/main.c
TEST_SRC = tests/test_structures.c

# Executables
MAIN_EXE = main
TEST_EXE = test_structures

# Default target
all: $(MAIN_EXE) $(TEST_EXE)

# Main program
$(MAIN_EXE): $(MAIN_SRC)
	$(CC) $(CFLAGS) $(MAIN_SRC) -o $(MAIN_EXE)

# Test program
$(TEST_EXE): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_EXE)

# Run main program
run: $(MAIN_EXE)
	./$(MAIN_EXE)

# Run tests
test: $(TEST_EXE)
	./$(TEST_EXE)

# Clean up
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)

# Install (placeholder)
install:
	@echo "No installation required"

.PHONY: all run test clean install
