/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solver
*/

#include "../includes/my.h"

void check_size(char *map, GLOBAL_T *ALL)
{
    ALL->size.size_x = -1;
    ALL->size.size_y = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            ALL->size.size_y++;
    }
    for (int j = 0; map[j] != '\n'; j++)
        ALL->size.size_x++;
}

void int_tab(GLOBAL_T *ALL, int k, int l)
{
    if (ALL->dt.dt_map[k][l] == 'X')
        ALL->dt.dt_map_int[k][l] = -1;
    else
        ALL->dt.dt_map_int[k][l] = 0;
}

void if_compt(GLOBAL_T *ALL, int m, int n)
{
    if ((m > 0 && ALL->dt.dt_map_int[m - 1][n] == ALL->size.dist - 1) ||
    (m < ALL->size.size_y && ALL->dt.dt_map_int[m + 1][n] ==
    ALL->size.dist - 1) || (n > 0 && ALL->dt.dt_map_int[m][n - 1] ==
    ALL->size.dist - 1) || (n < ALL->size.size_x &&
    ALL->dt.dt_map_int[m][n + 1] == ALL->size.dist - 1)) {
        ALL->dt.dt_map_int[m][n] = ALL->size.dist;
    }
}

void for_compt(GLOBAL_T *ALL, int m)
{
    for (int n = ALL->size.size_x; n > -1; n--){
        if (ALL->dt.dt_map_int[m][n] == 0) {
            if_compt(ALL, m, n);
        }
    }
}

void make_dt(char *map, GLOBAL_T *ALL)
{
    int k;int l;int **temp;ALL->size.dist = 1;
    ALL->dt.dt_map = str_to_word_array(map, "\n");
    ALL->dt.dt_map_int = malloc(sizeof(int *) * ALL->size.size_y + 1);
    for (k = 0; k < ALL->size.size_y + 1; k++) {
        ALL->dt.dt_map_int[k] =
                malloc(sizeof(ALL->dt.dt_map_int) * ALL->size.size_x + 1);
        for (l = 0; l < ALL->size.size_x + 1; l++)
            int_tab(ALL, k, l);
    }
    ALL->dt.dt_map_int[ALL->size.size_y][ALL->size.size_x] = 1;
    while (ALL->dt.dt_map_int[0][0] == 0) {
        ALL->size.dist++;
        for (int m = ALL->size.size_y; m > -1; m--)
            for_compt(ALL, m);
    }
}
