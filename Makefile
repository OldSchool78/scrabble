# Makefile to compile the project with source code in ./src, build files in ./build, and executable in the root directory

# Name of your program
TARGET = scrabble

# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
BUILD_DIR = ./build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Command to remove files
RM = rm -rf

# Main target
all: $(TARGET)

# Compilation of objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation of the main target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Command to clean files
clean:
	$(RM) $(BUILD_DIR) $(TARGET)

# Command to clean files and rebuild
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild
