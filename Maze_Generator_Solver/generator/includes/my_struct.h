/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H

typedef struct CHEMIN{
    int x;
    int y;
    int last_x;
    int last_y;
    struct CHEMIN *next;
    struct CHEMIN *prev;
} CHEMIN_T;

typedef struct GENE_MAZE {
    char **map;
    int len_x;
    int len_y;
    int nb_visited;
    int add;
    int max_len;
    CHEMIN_T *rac_chemin;
} MAZE_T;
#endif
