#Variables
NAME	= push_swap.out
CC		= cc
RM		= rm -rf
AR		= ar rc
CSRC	= src/
SRC		= algorithm check instructions psw
CHEAD	= Includes/
HEAD	= psw.h
MAKE	= make
SRC		= $(addsuffix .c, ($(addprefix $(CSRC), $(SRC))))
OBJ		= $(SRC:.c=.o)
COBJ	= obj/

#Normas
all: $(NAME)
	echo "DONE"

submake: libft
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC) -I $(CHEAD)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(COBJ)

fclean: clean
	$(RM) $(NAME)
.PHONY:all
