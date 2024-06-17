/*
** EPITECH PROJECT, 2024
** search.c
** File description:
** search
*/

#include "../../include/hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int crypt = 0;
    int placement = 0;
    list_t *list = NULL;

    if (key == NULL || ht == NULL)
        return NULL;
    crypt = ht->function(key, ht->len);
    if (crypt == -1)
        return NULL;
    placement = crypt % ht->len;
    list = ht[placement].list;
    if (list == NULL)
        return NULL;
    while (list != NULL) {
        if (my_strcmp(list->key, key) == 0)
            return list->value;
        list = list->next;
    }
    return NULL;
}
