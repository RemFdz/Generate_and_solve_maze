/*
** EPITECH PROJECT, 2023
** B-CPE-200-LIL-2-1-dante-aurelien.pochart
** File description:
** TODO: add description
*/

#include "struct.h"

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <errno.h>
    #include <time.h>
    #include "my.h"
    #include "stddef.h"

void check_size(char *map, GLOBAL_T *ALL);
char **str_to_word_array(char *str, const char *s);
int my_strlen(char const *str);
void make_dt(char *map, GLOBAL_T *ALL);
void transform_dt(GLOBAL_T *ALL);

#endif
