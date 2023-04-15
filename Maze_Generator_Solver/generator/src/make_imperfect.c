/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#include "../includes/my.h"

void modify_map(MAZE_T *maze, int *nb_modified, int x, int y)
{
    if (maze->map[y][x] == 'X') {
        *nb_modified += 1;
        maze->map[y][x] = '*';
    }
}

void make_imperfect(MAZE_T *maze, int ac, char **av)
{
    int imperfect = 1;
    if (ac >= 4) {
        if (strcmp(av[3], "perfect") == 0)
            imperfect = 0;
    } if (imperfect == 1) {
        int nb_modified = 0;
        while (nb_modified != maze->len_x * maze->len_y / 7) {
            int x_rand = rand() % maze->len_x;
            int y_rand = rand() % maze->len_y;
            modify_map(maze, &nb_modified, x_rand, y_rand);
        }
    }
}
