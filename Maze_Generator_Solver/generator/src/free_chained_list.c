/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-remi.fernandez
** File description:
** TODO: add description
*/
#include "../includes/my.h"

void free_chained_list(MAZE_T *maze)
{
    CHEMIN_T *list;
    for (list = RAC->next; RAC->next != RAC; list = RAC->next) {
        RAC->next = list->next;
        free(list);
    }
    free(RAC);
}
