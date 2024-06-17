/*
** EPITECH PROJECT, 2024
** functionnal_test.c
** File description:
** functionnal_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(new_hashtable, case_01)
{
    hashtable_t *ht = new_hashtable(hash, 0);

    cr_assert_eq(ht, NULL, "creating hashtable size 0.");
}

Test(new_hashtable, case_02)
{
    hashtable_t *ht = new_hashtable(hash, -5);

    cr_assert_eq(ht, NULL, "creating hashtable with negative size.");
}

Test(ht_insert, case_01)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = ht_insert(ht, "coucou", "coucou");

    cr_assert_eq(result, 0, "inserting a key equaling its value");
}

Test(ht_insert, case_02)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = ht_insert(ht, "", "coucou");

    cr_assert_eq(result, 84, "inserting a key \\0 with a value");
}

Test(ht_insert, case_03)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = ht_insert(ht, NULL, "hey");

    cr_assert_eq(result, 84, "inserting a key equaling NULL and a value");
}

Test(ht_insert, case_04)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = ht_insert(ht, "Où est le crash?", NULL);

    cr_assert_eq(result, 84, "inserting a key with a NULL value.");
}

Test(ht_insert, case_05)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = ht_insert(ht, "Où est le crash?", "oui");

    result = ht_insert(ht, "Où est le crash?", "peut-être ici");
    cr_assert_eq(result, 0, "Replacing a value of an already existent key.");
}

Test(ht_insert, case_06)
{
    int result = ht_insert(NULL, "Où est le crash?", "là!");

    cr_assert_eq(result, 84, "inserting a key with a value in a NULL ht.");
}

Test(ht_delete, case_01)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    int result = 0;

    ht_insert(ht, "Où est le crash?", "peut-être ici");
    result = ht_delete(ht, "Où est le crash?");
    cr_assert_eq(result, 0, "deleting an existent key.");
    for (int i = 0; i != 5; i++)
        cr_assert_eq(ht[i].list, NULL, "not NULL");
}

Test(ht_delete, case_02)
{
    hashtable_t *ht = new_hashtable(hash, 20);
    int result = ht_insert(ht, "Où est le crash?", "oui");

    result = ht_insert(ht, "Où est le crash?", "peut-être ici");
    result = ht_delete(ht, "Où est le crash?");
    cr_assert_eq(result, 0, "Deleting a key after replacing its value.");
    for (int i = 0; i != 5; i++)
        cr_assert_eq(ht[i].list, NULL, "not NULL");
}

Test(ht_delete, case_03)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    int result = 0;

    ht_insert(ht, "Où est le crash?", "peut-être ici");
    result = ht_delete(ht, "Où");
    cr_assert_eq(result, 84, "deleting an unexistent key.");
}

Test(ht_search, case_01)
{
    char *result = ht_search(NULL, NULL);

    cr_assert_eq(result, NULL, "searching in NULL ht a NULL key.");
}

Test(ht_search, case_02)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    char *result = ht_search(ht, NULL);

    cr_assert_eq(result, NULL, "searching in ht a NULL key.");
}

Test(ht_search, case_03)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    char *result = ht_search(ht, "");

    cr_assert_eq(result, NULL, "searching in ht an unexistent key.");
}

Test(ht_search, case_04)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    ht_insert(ht, "réussi", " ");
    char *result = ht_search(ht, " ");

    cr_assert_eq(result, NULL, "searching in ht a value instead of a key.");
}

Test(ht_search, case_05)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    ht_insert(ht, " ", "réussi");
    char *result = ht_search(ht, " ");

    cr_assert_str_eq(result, "réussi", "searching in ht an existent key.");
}

Test(ht_search, case_06)
{
    hashtable_t *ht = new_hashtable(hash, 5);
    ht_insert(ht, " ", "réussi");
    ht_insert(ht, " ", "échec");
    char *result = ht_search(ht, " ");

    cr_assert_str_eq(result, "échec", "searching in ht an existent key after changing its value.");
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ht_dump, case_01, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    ht_insert(ht, NULL, "réussi");
    ht_insert(ht, NULL, "échec");
    ht_dump(ht);

    cr_assert_stdout_eq_str("[0]:\n", "dumping empty ht.");
}

Test(ht_dump, case_02, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    ht_insert(ht, " ", "réussi");
    ht_insert(ht, " ", "échec");
    ht_dump(ht);

    cr_assert_stdout_eq_str("[0]:\n> 1089 - échec\n", "Dumping ht with 1 element.");
}

Test(ht_dump, case_03, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(hash, 1);
    ht_insert(ht, "Hey !", "réussi");
    ht_insert(ht, "Bon...", "échec");
    ht_dump(ht);

    cr_assert_stdout_eq_str("[0]:\n> 361 - échec\n> 9604 - réussi\n", "Dumping ht with 2 elements.");
}
