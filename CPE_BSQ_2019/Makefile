##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## oui
##

NAME	=	bsq

SRC	=		src/bsq.c \
			src/main.c \
			src/set_x.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS  +=	-L./ -lmy -I./include

all	:	$(NAME)

$(NAME) :	$(OBJ) $(SRC)
			gcc -o $(NAME) $(OBJ) -g3

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re	:	fclean all
