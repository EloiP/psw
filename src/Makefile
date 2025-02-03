# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epascual <epascual@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 19:24:22 by epascual          #+#    #+#              #
#    Updated: 2024/12/18 12:37:05 by epascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
RM = rm -rf
D = .c
INCLUDES = ./includes
HEAD = libft.h
FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c \
ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c \
ft_substr.c ft_striteri.c ft_strmapi.c ft_strjoin.c\
ft_strrchr.c ft_memchr.c ft_itoa.c ft_strtrim.c ft_split.c

BISRC = ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstsize_bonus.c \
ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c \
ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

SRC = $(SRCS)
BSRC = $(BISRC)
OBJ = $(SRC:.c=.o) 
BOBJ = $(BSRC:.c=.o)
MAKE = make

all: $(NAME)

bonus: $(OBJ) $(BOBJ) $(HEAD)
	ar rc $(NAME) $(BOBJ) $(OBJ)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c $(HEAD) Makefile
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

submake: printf
	$(MAKE) -C printf

.PHONY: all clean fclean re bonus rebonus
