/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-bsminishell1-remi.fernandez
** File description:
** TODO: add description
*/
#include "stdlib.h"

void free_double_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
    tab = NULL;
}
