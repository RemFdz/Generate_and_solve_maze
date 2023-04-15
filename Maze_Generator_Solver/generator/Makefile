##
## EPITECH PROJECT, 2022
## anagram
## File description:
## Makefile
##

NAME = generator

SRC = 	src/main.c \
		src/create_tab.c \
		src/backtracking_algo.c \
		src/condition_max_len.c \
		src/cell_is_valid.c \
		src/make_imperfect.c \
		src/free_double_tab.c \
		src/free_chained_list.c

OBJ = $(SRC:.c=.o)

all : $(OBJ)
	  			gcc $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
