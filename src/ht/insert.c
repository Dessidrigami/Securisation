/*
** EPITECH PROJECT, 2024
** insert.c
** File description:
** insert
*/

#include "../../include/hashtable.h"

bool key_already_exist(hashtable_t *ht, int placement, list_t *new)
{
    list_t *list = ht[placement].list;

    if (list == NULL)
        return false;
    while (list != NULL) {
        if (new->crypt == list->crypt) {
            new->next = list->next;
            *list = *new;
            return true;
        }
        list = list->next;
    }
    return false;
}

void choose_new_next(list_t *new, hashtable_t *ht, int placement)
{
    if (!key_already_exist(ht, placement, new)) {
        new->next = ht[placement].list;
        ht[placement].list = new;
    }
    return;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int crypt = 0;
    int placement = 0;
    list_t *new = NULL;

    if (key == NULL || value == NULL || ht == NULL)
        return 84;
    crypt = (ht->function)(key, ht->len);
    if (crypt == -1)
        return 84;
    placement = crypt % ht->len;
    new = malloc(sizeof(list_t));
    new->key = key;
    new->crypt = crypt;
    new->value = value;
    choose_new_next(new, ht, placement);
    return 0;
}
