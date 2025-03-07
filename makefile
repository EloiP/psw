# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIB_DIR = libs
INC_DIR = Includes

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIB = .a

# Executable name
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIB_DIR)/$(LIBFT_DIR)$(CLIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -I $(INC_DIR) -l:$(LIBFT_DIR)$(CLIB)

$(LIB_DIR)/$(LIBFT_DIR)$(CLIB):
	@make -C $(LIBFT_DIR) # Compile libft library
	@mkdir -p $(LIB_DIR) # Create libs directory if it doesn't exist
	@cp -a $(LIBFT_DIR)/$(LIBFT_DIR)$(CLIB) $(LIB_DIR)/ # Copy the library to libs

$(INC_DIR):
	@mkdir -p $(INC_DIR) # Create Includes directory if it doesn't exist
	@cp -a $(LIBFT_DIR)/$(INC_DIR)/*.h $(INC_DIR) # Copy the header files to Includes

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)  # Remove object files
	@rm -rf $(LIB_DIR) # Remove libs
	@rm -rf $(INC_DIR) # Remove Includes
	@make fclean -C $(LIBFT_DIR)  # Clean libft

fclean: clean
	@rm -f $(NAME)  # Remove the executable

re: fclean all  # Rebuild the project

.PHONY: all clean fclean re
