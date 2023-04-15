/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main file
*/

#include "../includes/my.h"

char *read_file(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "bad open\n", 9);
        return NULL;
    }
    char *buffer = malloc(buf.st_size);
    if (buffer == NULL) {
        write(2, "bad file\n", 9);
        return NULL;
    }
    int value = read(fd, buffer, buf.st_size);
    if (value == 0 || value == -1) {
        write(2, "bad file\n", 9);
        return NULL;
    }
    buffer[value] = '\0';
    close(fd);
    return buffer;
}

void print_sol(GLOBAL_T *ALL, int a, int z)
{
    if (ALL->dt.dt_map_int[a][z] == -1) {
        write(1, "X", 1);
    } else if (ALL->dt.dt_map_int[a][z] == -2) {
        write(1, "o", 1);
    } else {
        write(1, "*", 1);
    }
}

int check_error(char *map)
{
    if (my_strlen(map) < 2) {
        write(2, "too small\n", 10);
        return 84;
    }

    return 0;
}

int main (int ac, char **av)
{
    GLOBAL_T ALL;char *map;
    if (ac != 2)
        return 84;
    map = read_file(av[1]);
    if (map == NULL)
        return 84;
    if (check_error(map) == 84)
        return 84;
    check_size(map, &ALL);
    make_dt(map, &ALL);
    transform_dt(&ALL);
    for (int a = 0; a < ALL.size.size_y + 1; a++) {
        for (int z = 0; z < ALL.size.size_x + 1; z++) {
            print_sol(&ALL, a, z);
        }
        if (a < ALL.size.size_y)
            write(1, "\n", 1);
    }
    return 0;
}
