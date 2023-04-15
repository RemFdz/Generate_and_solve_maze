/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#include "../includes/my.h"

int *random_cell(void)
{
    int nums[4] = {0};
    int *list = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++) {
        int r;
        do {
            r = rand() % 4 + 1;
        } while (nums[r - 1] != 0);
        nums[r - 1] = 1;
        list[i] = r;
    }
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
    return list;
}

void go_back(MAZE_T *maze, int *cy, int *cx)
{
    CHEMIN_T *list;
    list = RAC->prev;
    if (list == RAC)
        return;
    *cy = list->last_y;
    *cx = list->last_x;
    list->next->prev = list->prev;
    list->prev->next = list->next;
    free(list);
}

void backtrack_algo(MAZE_T *maze, int *cy, int *cx, int *cell)
{
    int nb = 0;
    maze->map[*cy][*cx] = '*';
    nb = cell_is_valid(maze, cell, cy, cx);
    if (nb == -1) {
        while (nb == -1 && maze->nb_visited < maze->max_len) {
            go_back(maze, cy, cx);
            nb = cell_is_valid(maze, cell, cy, cx);
        }
    }
}

void generate_maze(MAZE_T *maze, int cx, int cy)
{
    srand(time(NULL));
    while (maze->nb_visited < maze->max_len) {
        int *cell = random_cell();
        backtrack_algo(maze, &cy , &cx, cell);
        free(cell);
    }
}
