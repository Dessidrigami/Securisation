/*
** EPITECH PROJECT, 2024
** dump.c
** File description:
** dump
*/
#include "../../include/hashtable.h"

void print_value(list_t *list, hashtable_t *ht)
{
    list_t *tmp = list;

    while (tmp != NULL) {
        mini_printf("> %d - %s\n", ht->function(tmp->key, my_strlen(tmp->key)),
        tmp->value);
        tmp = tmp->next;
    }
    return;
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i != ht->len; i++) {
        mini_printf("[%d]:\n", i);
        print_value(ht[i].list, ht);
    }
    return;
}
