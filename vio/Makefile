# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avelandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 20:20:08 by avelandr          #+#    #+#              #
#    Updated: 2025/05/30 12:33:48 by epascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -MD -MP -g -fsanitize=address

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIB_DIR = libs
INC_DIR = Includes
DEPS_DIR = deps

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(DEPS_DIR)/%.d)
CLIB = .a

# Executable name
NAME = push_swap
TESTVALUES = 1 3 2

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	@mkdir -p $(DEPS_DIR)  # Create dependencies directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@ -MD -MF $(DEPS_DIR)/$*.d

# Include dependency files
-include $(DEP_FILES)

clean:
	@rm -rf $(OBJ_DIR)  # Remove object files
	@rm -rf $(LIB_DIR) # Remove libs
	@rm -rf $(DEPS_DIR) # Remove dependencies
	@make fclean -C $(LIBFT_DIR)  # Clean libft

fclean: clean
	@rm -f $(NAME)  # Remove the executable

re: fclean all  # Rebuild the project

mem: $(NAME)
	valgrind --verbose --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TESTVALUES)

test: $(NAME)
	./$(NAME) $(TESTVALUES)

.PHONY: all clean fclean re
