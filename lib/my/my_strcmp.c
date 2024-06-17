/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int size = 0;
    int size2 = 0;

    if (s1 == NULL || s2 == NULL || size != size2)
        return 257;
    size = my_strlen(s1);
    size2 = my_strlen(s2);
    for (int i = 0; i != size; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
