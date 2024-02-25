/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strchr
*/

#include <criterion/criterion.h>

extern char *strchr(const char *s, int c);

Test(strchr, string)
{
    char str[] = "Hello World!";
    int c = 'l';
    char *res;

    res = strchr(str, c);

    cr_assert_str_eq(res, "llo World!");
}

Test(strchr, start_of_string)
{
    char str[] = "Hello World!";
    int c = 'H';
    char *res;

    res = strchr(str, c);

    cr_assert_str_eq(res, "Hello World!");
}

Test(strchr, last_char_before_terminator)
{
    char str[] = "Hello World!";
    int c = '!';
    char *res;

    res = strchr(str, c);

    cr_assert_str_eq(res, "!");
}

Test(strchr, null_terminator)
{
    char str[] = "Hello World!";
    int c = '\0';
    char *res;

    res = strchr(str, c);

    cr_assert_str_eq(res, "");
}

Test(strchr, char_not_in_str)
{
    char str[] = "Hello World!";
    int c = 'z';
    char *res;

    res = strchr(str, c);

    cr_assert_eq(res, NULL);
}
