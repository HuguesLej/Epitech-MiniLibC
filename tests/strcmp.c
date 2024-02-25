/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strcmp
*/

#include <criterion/criterion.h>

extern int strcmp(const char *s1, const char *s2);

Test(strcmp, equal_strings)
{
    char s1[] = "hello";
    char s2[] = "hello";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, 0);
}

Test(strcmp, s1_lt)
{
    char s1[] = "hella";
    char s2[] = "hello";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, -14);
}

Test(strcmp, s1_gt)
{
    char s1[] = "hello";
    char s2[] = "hella";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, 14);
}

Test(strcmp, different_lenght)
{
    char s1[] = "hello world";
    char s2[] = "hello";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, 32);
}

Test(strcmp, empty_string)
{
    char s1[] = "";
    char s2[] = "hello";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, -104);
}

Test(strcmp, two_empty_strings)
{
    char s1[] = "";
    char s2[] = "";
    int res;

    res = strcmp(s1, s2);

    cr_assert_eq(res, 0);
}
