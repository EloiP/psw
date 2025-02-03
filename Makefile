# Makefile for Push_swap Project

# Compiler
CC = cc

# Compiler flags
CFLAGS = #-Wall -Werror -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
INC = Includes

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR)  # Compile the libft library
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -I $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)  # Remove object files
	@make clean -C $(LIBFT_DIR)  # Clean libft

fclean: clean
	@rm -f $(NAME)  # Remove the executable

re: fclean all  # Rebuild the project

.PHONY: all clean fclean re
