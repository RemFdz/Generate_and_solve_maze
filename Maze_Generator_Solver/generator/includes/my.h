/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#ifndef MY_H
    #define MY_H
    #define RAC maze->rac_chemin
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <errno.h>
    #include <time.h>
    #include "my.h"
    #include "stddef.h"
    #include "my_struct.h"
char ** create_tab(int x, int y);
void backtracking_algo(MAZE_T *maze, int cx, int cy);
void generate_maze(MAZE_T *maze, int cx, int cy);
void add_chemin(MAZE_T *maze, int cy, int cx, int dir);
void genere_maze(MAZE_T *maze, int cx, int cy);
void condition_max_len(int x, int y, MAZE_T *maze);
int cell_is_valid(MAZE_T *maze, int *cell, int *cy, int *cx);
void make_imperfect(MAZE_T *maze, int ac, char **av);
void free_double_tab(char **tab);
void free_chained_list(MAZE_T *maze);
#endif
