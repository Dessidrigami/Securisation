/*
** EPITECH PROJECT, 2024
** hash.c
** File description:
** hash
*/

#include "../include/hashtable.h"

int hash(char *key, int len)
{
    int result = 0;
    int size = my_strlen(key);

    if (key == NULL || len <= 0 || size == 0)
        return -1;
    for (int i = 0; i != size; i++) {
        if (i % 2 == 0)
            result += key[i] + len;
        if (i % 2 == 1)
            result -= key[i] + len;
    }
    result *= result;
    return result;
}
