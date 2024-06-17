/*
** EPITECH PROJECT, 2024
** delete_hashtable.c
** File description:
** delete hashtable
*/
#include "../include/hashtable.h"

void free_list(list_t *list)
{
    if (list == NULL)
        return;
    free_list(list->next);
    free(list);
    return;
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i != ht->len; i++)
        free_list(ht[i].list);
    free(ht);
    return;
}
