/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** len
*/

int my_strlen(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return (n);
}
