##
## EPITECH PROJECT, 2022
## anagram
## File description:
## Makefile
##

NAME = solver

SRC = 	src/main.c src/solver.c \
		src/str_to_word_array.c \
		src/my_strlen.c src/transform.c

OBJ = $(SRC:.c=.o)

all : $(OBJ)
	  			gcc $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
