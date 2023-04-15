/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/
#include "../includes/my.h"

void condition_fill(int i, int j, char **tab, int bin)
{
    if (bin == 0) {
        if (j != 0 && tab[i][j - 1] == '.' || i != 0 && tab[i - 1][j] == '.') {
            tab[i][j] = 'X';
        } else
            tab[i][j] = '.';
    }
    if (bin == 1) {
        tab[i][j] = 'X';
    }
}

char ** create_tab(int x, int y)
{
    int bin = 0;
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (y + 1));
    for (i = 0; i != y; i++) {
        tab[i] = malloc(sizeof(char) * (x + 1));
        for (j = 0; j != x; j++) {
            condition_fill(i, j, tab, bin);
        }
        tab[i][j] = '\0';
        if (bin == 0)
            bin = 1;
        else
            bin = 0;
    }
    tab[i] = NULL;
    return tab;
}
