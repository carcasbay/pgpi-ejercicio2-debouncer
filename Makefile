CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -Iinclude

TARGET = test_debouncer
BUILD_DIR = build

SRCS = src/debouncer.c tests/test_debouncer.c
OBJS = $(BUILD_DIR)/src/debouncer.o $(BUILD_DIR)/tests/test_debouncer.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/src/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)/src
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/tests/%.o: tests/%.c
	@mkdir -p $(BUILD_DIR)/tests
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) informe.txt

.PHONY: all clean valgrind
