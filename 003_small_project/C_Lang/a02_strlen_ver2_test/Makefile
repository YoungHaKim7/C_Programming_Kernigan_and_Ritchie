# Makefile for strlen implementation project

CC = gcc
CFLAGS = -Wall -Wextra -std=c23 -g -O2
LDFLAGS = -lm

# Directories
SRC_DIR = src
BUILD_DIR = build
TARGET_DIR = $(BUILD_DIR)/target

# Source files
MAIN_SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/strlen_impl.c
TEST_SOURCES = $(SRC_DIR)/test_strlen.c $(SRC_DIR)/strlen_impl.c

# Targets
MAIN_TARGET = $(TARGET_DIR)/a01_strlen_impl
TEST_TARGET = $(TARGET_DIR)/test_strlen

.PHONY: all clean test run-main run-test build

all: build

build: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_SOURCES) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $(MAIN_SOURCES) $(LDFLAGS)

$(TEST_TARGET): $(TEST_SOURCES) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $(TEST_SOURCES) $(LDFLAGS)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

run-main: $(MAIN_TARGET)
	@echo "Running main strlen comparison..."
	@$(MAIN_TARGET)

run-test: $(TEST_TARGET)
	@echo "Running comprehensive tests..."
	@$(TEST_TARGET)

test: run-test

clean:
	rm -rf $(BUILD_DIR)

# Development helpers
debug: CFLAGS += -DDEBUG -O0
debug: build

release: CFLAGS += -DNDEBUG -O3
release: build

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build all executables (default)"
	@echo "  build     - Build all executables"
	@echo "  run-main  - Run the main strlen comparison program"
	@echo "  run-test  - Run the comprehensive test suite"
	@echo "  test      - Alias for run-test"
	@echo "  clean     - Remove build directory"
	@echo "  debug     - Build with debug flags"
	@echo "  release   - Build with release optimization"
	@echo "  help      - Show this help message"