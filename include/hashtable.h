/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct list_s {
    int crypt;
    char *key;
    char *value;
    struct list_s *next;
} list_t;

typedef struct hashtable_s {
    int len;
    int (*function)(char *, int);
    list_t *list;
} hashtable_t;

// hash.c

int hash(char *key, int len);

// Create & destroy table

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table

int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// lib/my/

int mini_printf(const char *, ...);
int my_strlen(char *);
char *my_strdup(char *src);
int my_strcmp(char *, char *);

// insert.c

bool key_already_exist(hashtable_t *ht, int placement, list_t *new);

#endif /* HASHTABLE_H */
