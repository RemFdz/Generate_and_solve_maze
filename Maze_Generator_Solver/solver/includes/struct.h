/*
** EPITECH PROJECT, 2023
** dante
** File description:
** struct file
*/

#ifndef STRUCT_H
    #define STRUCT_H

    typedef struct size {
        int size_x;
        int size_y;
        int dist;
        int x;
        int y;
        int temp;
    } size_T;

    typedef struct double_tab {
        char **dt_map;
        int **dt_map_int;
    } double_tab_T;

    typedef struct GLOBAL {
        size_T size;
        double_tab_T dt;
    } GLOBAL_T;

#endif
