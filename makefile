# Makefile for Push_swap Project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIB_DIR = libs
INC = Includes

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIB = .a

# Executable name
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIB_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -I $(INC) -l:$(LIBFT_DIR)$(CLIB)

$(LIB_DIR):
	@make -C $(LIBFT_DIR) # Compila libft library
	@mkdir -p $(LIB_DIR) # Create libs directory if it doesn't exist
	@cp -a $(LIBFT_DIR)/$(LIBFT_DIR)$(CLIB) $(LIB_DIR) # Copy the library to libs

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)  # Remove object files
	@rm -rf $(LIB_DIR) # Remove libs
	@make fclean -C $(LIBFT_DIR)  # Clean libft

fclean: clean
	@rm -f $(NAME)  # Remove the executable

re: fclean all  # Rebuild the project

.PHONY: all clean fclean re
