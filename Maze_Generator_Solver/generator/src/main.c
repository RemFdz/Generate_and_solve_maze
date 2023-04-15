/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#include "../includes/my.h"

void initialise_list(MAZE_T *maze, int x, int y)
{
    maze->len_x = x;
    maze->len_y = y;
    maze->nb_visited = 1;
    maze->add = 1;
    maze->max_len = x * y / 2 / 2;
    maze->map = create_tab(x, y);
    RAC = malloc(sizeof(*RAC));
    RAC->y = 0;
    RAC->x = 0;
    RAC->last_x = 0;
    RAC->last_y = 0;
    RAC->next = RAC;
    RAC->prev = RAC;
}

void add_chemin(MAZE_T *maze, int cy, int cx, int dir)
{
    CHEMIN_T *new = malloc(sizeof(*new));
    new->last_x = cx;
    new->last_y = cy;
    if (dir == 1) {
        new->x = cx;
        new->y = cy - 1;
    } if (dir == 2) {
        new->x = cx;
        new->y = cy + 1;
    } if (dir == 3) {
        new->x = cx + 1;
        new->y = cy;
    } if (dir == 4) {
        new->x = cx - 1;
        new->y = cy;
    }
    new->prev = RAC->prev;
    new->next = RAC;
    RAC->prev->next = new;
    RAC->prev = new;
}

void print_chained_list(MAZE_T *maze)
{
    CHEMIN_T *list;
    for (list = RAC->next; list != RAC; list = list->next) {
        printf("\n%d:%d\n", list->y, list->x);
    }
}

int check_args(int ac, char **av)
{
    int j = 0;
    if (ac < 3 || ac > 4) {
        write(2, "wrong nb of arguments\n", 22);
        return 84;
    } if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        write(2, "wrongs args\n", 12);
        return 84;
    } for (j = 0; av[1][j] != '\0'; j++) {
        if (av[1][j] < 48 || av[1][j] > 57) {
            write(2, "wrongs args\n", 12);
            return 84;
        }
    } for (j = 0; av[2][j] != '\0'; j++) {
        if (av[2][j] < 48 || av[2][j] > 57) {
            write(2, "wrong args\n", 12);
            return 84;
        }
    }
    return 0;
}

int main (int ac, char **av)
{
    MAZE_T maze;
    int j = 0;
    if (check_args(ac, av) == 84)
        return 84;
    initialise_list(&maze, atoi(av[1]), atoi(av[2]));
    condition_max_len(atoi(av[1]), atoi(av[2]), &maze);
    generate_maze(&maze, 0 , 0);
    if (maze.len_x > 0 && maze.len_y > 0) {
        maze.map[0][0] = '*';
        maze.map[maze.len_y - 1][maze.len_x - 1] = '*';
        if (maze.len_x % 2 == 0 && maze.len_y % 2 == 0)
            maze.map[maze.len_y - 2][maze.len_x - 1] = '*';
    }
    make_imperfect(&maze, ac, av);
    for (j = 0; maze.map[j + 1] != NULL; j++)
        printf("%s\n", maze.map[j]);
    printf("%s", maze.map[j]);
    free_double_tab(maze.map);
    free_chained_list(&maze);
}
