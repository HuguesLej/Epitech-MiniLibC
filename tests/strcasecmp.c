/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strcasecmp
*/

#include <criterion/criterion.h>

extern int strcasecmp(const char *s1, const char *s2);

Test(strcasecmp, equal_strings)
{
    char s1[] = "Hello";
    char s2[] = "Hello";
    int res;

    res = strcasecmp(s1, s2);

    cr_assert_eq(res, 0);
}

Test(strcasecmp, equal_strings_with_case_differences)
{
    char s1[] = "Hello";
    char s2[] = "heLlO";
    int res;

    res = strcasecmp(s1, s2);

    cr_assert_eq(res, 0);
}

Test(strcasecmp, different_strings_without_case)
{
    char s1[] = "hello";
    char s2[] = "hel lo";
    int res;

    res = strcasecmp(s1, s2);

    cr_assert_eq(res, 76);
}

Test(strcasecmp, different_strings_with_case)
{
    char s1[] = "helLo";
    char s2[] = "hel lo";
    int res;

    res = strcasecmp(s1, s2);

    cr_assert_eq(res, 76);
}

Test(strcasecmp, last_char_before_terminator)
{
    char s1[] = "hellO";
    char s2[] = "hello";
    int res;

    res = strcasecmp(s1, s2);

    cr_assert_eq(res, 0);
}
