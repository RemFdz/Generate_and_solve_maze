/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** from char* to char **
*/

#include "../includes/my.h"

void alloc_dt(const char *s, int *space, char *str)
{
    int index = 0;
    int v = 0;
    do {
        while (str[index] != '\0') {
            if (str[index] == s[v])
                (*space)++;
            index++;
        }
        v++;
        index = 0;
    } while (s[v] != '\0');
}

char **str_to_word_array(char *str, const char *s)
{
    char *token;char **tab_stock;
    int space = 0;int dt = 1;
    alloc_dt(s, &space, str);
    tab_stock = malloc(sizeof(char *) * (space + 1));
    for (int i = 0; i != space + 1; i++)
        tab_stock[i] = NULL;
    token = strtok(str, s);
    tab_stock[0] = malloc(sizeof(char) * (my_strlen(token) + 1));
    tab_stock[0] = token;
    while (token != NULL) {
        token = strtok(NULL, s);
        if (token != NULL) {
            tab_stock[dt] = malloc(sizeof(char) * (my_strlen(token) + 1));
            tab_stock[dt] = token;
        }
        dt++;
    }
    return tab_stock;
}
