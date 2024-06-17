/*
** EPITECH PROJECT, 2024
** delete.c
** File description:
** delete
*/
#include "../../include/hashtable.h"

int search_delete(list_t *list, int crypt, int placement)
{
    if (list == NULL || list->next == NULL)
        return 84;
    if (list->next->crypt == crypt) {
        if (list->next->next != NULL)
            *list->next = *list->next->next;
        else
            list->next = NULL;
        return 0;
    } else
        search_delete(list->next, crypt, placement);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int crypt = 0;
    int placement = 0;

    if (key == NULL || ht == NULL)
        return 84;
    crypt = ht->function(key, ht->len);
    if (crypt == -1)
        return 84;
    placement = crypt % ht->len;
    if (ht[placement].list == NULL)
        return 84;
    if (ht[placement].list->crypt == crypt)
            ht[placement].list = ht[placement].list->next;
    else
        return search_delete(ht[placement].list, crypt, placement);
    return 0;
}
