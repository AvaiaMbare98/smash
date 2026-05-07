.PHONY: clean e2e_tests test_all

CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_DIR = src
OBJ_DIR = build
TEST_DIR = tests

# select every file that ends in .c inside the src directory
SRCS = $(wildcard $(SRC_DIR)/*.c)

# transforms what was in SRCS in build/%.o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))

CORE_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

smash: $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
unit_tests: $(TEST_OBJS) $(CORE_OBJS)
				$(CC) $(CFLAGS) $^ -o $@ -lcriterion

clean: 
		rm -rf $(OBJ_DIR) smash test_runner

e2e_tests: smash
			./tests/e2e_executor.sh 

test_all: e2e_tests unit_tests
			./unit_tests --verbose
			@echo "Unit tests completed. E2E tests completed."