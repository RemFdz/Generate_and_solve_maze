/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#include "../includes/my.h"

int condition_top(int *cy, int *cx, MAZE_T *maze)
{
    int ny = *cy - 2;
    int my = *cy - 1;
    if (ny >= 0 && *cx >= 0 && ny < maze->len_y && *cx < maze->len_x &&
    maze->map[ny][*cx] == '.' && maze->map[my][*cx] == 'X') {
        *cy = ny;
        add_chemin(maze, *cy, *cx , 1);
        maze->map[*cy][*cx] = '*';
        maze->map[my][*cx] = '*';
        maze->nb_visited += maze->add;
        return 1;
    }
    return 0;
}

int condition_bot(int *cy, int *cx, MAZE_T *maze)
{
    int ny = *cy + 2;
    int my = *cy + 1;
    if (ny >= 0 && *cx >= 0 && ny < maze->len_y && *cx <
    maze->len_x && maze->map[ny][*cx] == '.' && maze->map[my][*cx] == 'X') {
        *cy = ny;
        add_chemin(maze, *cy, *cx , 2);
        maze->map[*cy][*cx] = '*';
        maze->map[my][*cx] = '*';
        maze->nb_visited += maze->add;
        return 1;
    }
    return 0;
}

int condition_right(int *cy, int *cx, MAZE_T *maze)
{
    int nx = *cx + 2;
    int mx = *cx + 1;
    if (*cy >= 0 && nx >= 0 && *cy < maze->len_y && nx <
    maze->len_x && maze->map[*cy][nx] == '.' && maze->map[*cy][mx] == 'X') {
        *cx = nx;
        add_chemin(maze, *cy, *cx , 3);
        maze->map[*cy][*cx] = '*';
        maze->map[*cy][mx] = '*';
        maze->nb_visited += maze->add;
        return 1;
    }
    return 0;
}

int condition_left(int *cy, int *cx, MAZE_T *maze)
{
    int nx = *cx - 2;
    int mx = *cx - 1;
    if (*cy >= 0 && nx >= 0 && *cy < maze->len_y && nx <
    maze->len_x && maze->map[*cy][nx] == '.' && maze->map[*cy][mx] == 'X') {
        *cx = nx;
        add_chemin(maze, *cy, *cx , 4);
        maze->map[*cy][*cx] = '*';
        maze->map[*cy][mx] = '*';
        maze->nb_visited += maze->add;
        return 1;
    }
    return 0;
}

int cell_is_valid(MAZE_T *maze, int *cell, int *cy, int *cx)
{
    for (int j = 0; j != 4; j++) {
        if (cell[j] == 1 && condition_top(cy, cx, maze) == 1)
            return 1;
        if (cell[j] == 2 && condition_bot(cy, cx, maze) == 1) {
            return 1;
        } if (cell[j] == 3 && condition_right(cy, cx, maze) == 1) {
            return 1;
        } if (cell[j] == 4 && condition_left(cy, cx, maze) == 1) {
            return 1;
        }
    }
    return -1;
}
