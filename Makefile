CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_DIR = src
OBJ_DIR = build

# select every file that ends in .c inside the src directory
SRCS = $(wildcard $(SRC_DIR)/*.c)

# transforms what was in SRCS in build/%.o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

smash: $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(OBJ_DIR) smash