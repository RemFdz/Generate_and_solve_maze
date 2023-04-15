##
## EPITECH PROJECT, 2022
## makefile cat
## File description:
## Makefile
##

SRC		=	generator/src/main.c

OBJ		=	$(SRC:.c=.o)

NAME 		= generator

all: $(NAME)
		make -C ./solver
		make -C ./generator
		make clean

clean:
		rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
