/*
** EPITECH PROJECT, 2024
** new_hashtable.c
** File description:
** new_hashtable
*/
#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = NULL;

    if (len <= 0)
        return NULL;
    ht = malloc(sizeof(hashtable_t) * len);
    for (int i = 0; i != len; i++) {
        ht[i].len = len;
        ht[i].function = hash;
        ht[i].list = NULL;
    }
    return ht;
}
