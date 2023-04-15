/*
** EPITECH PROJECT, 2023
** dante
** File description:
** transform dt
*/

#include "../includes/my.h"

void move_nbr(GLOBAL_T *ALL)
{
    if (ALL->size.x < ALL->size.size_x &&
    ALL->dt.dt_map_int[ALL->size.y][ALL->size.x + 1] == ALL->size.temp - 1) {
        ALL->size.x++;
        return;
    }
    if (ALL->size.y < ALL->size.size_y &&
    ALL->dt.dt_map_int[ALL->size.y + 1][ALL->size.x] == ALL->size.temp - 1) {
        ALL->size.y++;
        return;
    }
    if (ALL->size.x > 0 && ALL->dt.dt_map_int[ALL->size.y][ALL->size.x - 1]
    == ALL->size.temp - 1) {
        ALL->size.x--;
        return;
    }
    if (ALL->size.y > 0 && ALL->dt.dt_map_int[ALL->size.y - 1][ALL->size.x]
    == ALL->size.temp - 1) {
        ALL->size.y--;
        return;
    }
}

void transform_dt(GLOBAL_T *ALL)
{
    ALL->size.x = 0;
    ALL->size.y = 0;
    ALL->size.temp = ALL->dt.dt_map_int[ALL->size.y][ALL->size.x];
    ALL->dt.dt_map_int[ALL->size.y][ALL->size.x] = -2;
    while (ALL->size.x != ALL->size.size_x || ALL->size.y != ALL->size.size_y) {
        move_nbr(ALL);
        ALL->size.temp = ALL->dt.dt_map_int[ALL->size.y][ALL->size.x];
        ALL->dt.dt_map_int[ALL->size.y][ALL->size.x] = -2;
    }
}
