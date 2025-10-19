CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = sort_program
TEST_TARGET = test_sort

all: $(TARGET)

$(TARGET): sort_program.c
	$(CC) $(CFLAGS) -o $(TARGET) sort_program.c

test: $(TARGET) test_sort.c
	$(CC) $(CFLAGS) -o test_sort test_sort.c
	./test_sort

clean:
	rm -f $(TARGET) test_sort test*.txt

.PHONY: all test clean