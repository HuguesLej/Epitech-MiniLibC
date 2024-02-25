/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strncmp
*/

#include <criterion/criterion.h>

extern int strncmp(const char *s1, const char *s2, size_t n);

Test(strncmp, compare_equal_strings)
{
    char s1[] = "Hello";
    char s2[] = "Hello";
    int res;

    res = strncmp(s1, s2, 3);

    cr_assert_eq(res, 0);
}

Test(strncmp, compare_equal_substrings)
{
    char s1[] = "Hello World!";
    char s2[] = "Hello";
    int res;

    res = strncmp(s1, s2, 5);

    cr_assert_eq(res, 0);
}

Test(strncmp, compare_differents_substrings)
{
    char s1[] = "Hello World!";
    char s2[] = "Hello world!";
    int res;

    res = strncmp(s1, s2, 7);

    cr_assert_eq(res, -32);
}

Test(strncmp, compare_different_length_substrings)
{
    char s1[] = "Hello World!";
    char s2[] = "Hello";
    int res;

    res = strncmp(s1, s2, 7);

    cr_assert_eq(res, 32);
}

Test(strncmp, compare_empty_string)
{
    char s1[] = "";
    char s2[] = "Hello";
    int res;

    res = strncmp(s1, s2, 7);

    cr_assert_eq(res, -72);
}
