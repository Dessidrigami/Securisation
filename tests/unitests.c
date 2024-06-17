/*
** EPITECH PROJECT, 2023
** unitests.c
** File description:
** unitests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(hash, good_hash_01) {
    int hi = hash("hi", my_strlen("hi"));
    int hey = hash("hey!", my_strlen("hey!"));

    cr_assert_neq(hi, hey, "Hash isn't good enough: %d vs %d", hi, hey);   
}

Test(hash, good_hash_02)
{
    int hey = hash("hey!", my_strlen("hey!"));
    int coucou = hash("coucou", my_strlen("coucou"));

    cr_assert_neq(coucou, hey, "Hash isn't good enough: %d vs %d", coucou,
    hey);
}

Test(hash, good_hash_03)
{
    int hi = hash("hi", my_strlen("hi"));
    int coucou = hash("coucou", my_strlen("coucou"));

    cr_assert_neq(hi, coucou, "Hash isn't good enough: %d vs %d", hi, coucou);
}

Test(hash, good_hash_04)
{
    int hey = hash("hey!", my_strlen("hey!"));

    cr_assert_eq(hey, hey, "Hum... wtff? Should be the same...");
}

Test(hash, good_hash_05)
{
    int hello = hash("hello", my_strlen("hello"));
    int salut = hash("salut", my_strlen("salut"));

    cr_assert_neq(hello, salut, "Hash isn't good enough: %d vs %d", hello,
    salut);
}

Test(hash, good_hash_06)
{
    int bonjour = hash("bonjour", my_strlen("bonjour"));
    int salutations = hash("salutations", my_strlen("salutations"));

    cr_assert_neq(salutations, bonjour, "Hash isn't good enough: %d vs %d",
    salutations, bonjour);
}

Test(hash, good_hash_07)
{
    int bonjour = hash("bonjour", my_strlen("bonjour"));
    int hey = hash("hey!", my_strlen("hey!"));

    cr_assert_neq(bonjour, hey, "Hash isn't good enough: %d vs %d", bonjour,
    hey);
}

Test(hash, good_hash_08)
{
    int salutations = hash("salutations", my_strlen("salutations"));
    int hey = hash("hey!", my_strlen("hey!"));

    cr_assert_neq(salutations, hey, "Hash isn't good enough: %d vs %d",
    salutations, hey);}

Test(hash, good_hash_09)
{
    int hi = hash("hi", my_strlen("hi"));
    int bonjour = hash("bonjour", my_strlen("bonjour"));

    cr_assert_neq(hi, bonjour, "Hash isn't good enough: %d vs %d", hi,
    bonjour);
}

Test(hash, good_hash_10)
{
    int bye = hash("bye", my_strlen("bye"));
    int boum = hash("boum", my_strlen("boum"));

    cr_assert_neq(bye, boum, "Hash isn't good enough: %d vs %d", bye, boum);
}
