#Variables
NAME	= push_swap.out
CC		= cc
RM		= rm -rf
AR		= ar rc
CSRC	= src/
SRC		= check instructions psw#algorithm
CHEAD	= Includes/
HEAD	= psw.h
MAKE	= make
SSRC		= $(addsuffix .c, ($(addprefix $(CSRC), $(SRC))))
OBJ		= $(SSRC:.c=.o)
COBJ	= obj/

#Normas
all: $(NAME)
	echo "DONE"

#submake: libft
#	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SSRC) -I $(CHEAD)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(COBJ)

fclean: clean
	$(RM) $(NAME)
.PHONY:all
