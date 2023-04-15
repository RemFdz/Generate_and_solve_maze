/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/
#include "../includes/my.h"

void condition_max_len2(int x, int y, MAZE_T *maze)
{
    int nb = 0;
    if (x % 2 == 0) {
        if (x / 2 % 2 == 1)
            nb = x / 2 / 2 + 1;
        else
            nb = x / 2 / 2;
    } if (y % 2 == 0) {
        if (y / 2 % 2 == 1)
            nb = y / 2 / 2 + 1;
        else
            nb = y / 2 / 2;
    }
    maze->max_len += nb;
}

void condition_max_len(int x, int y, MAZE_T *maze)
{
    if (x % 2 != 0 && y % 2 != 0) {
        maze->max_len = (x / 2 + 1) * (y / 2 + 1);
    } else if (x % 2 != 0 && y % 2 == 0 || x % 2 != 1 && y % 2 == 1) {
        condition_max_len2(x, y, maze);
    }
}
