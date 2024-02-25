/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** rindex
*/

#include <criterion/criterion.h>

extern char *rindex(const char *s, int c);

Test(rindex, first_char_of_string)
{
    char str[] = "Hello World!";
    int c = 'H';
    char *res;

    res = rindex(str, c);

    cr_assert_str_eq(res, "Hello World!");
}

Test(rindex, char_in_string)
{
    char str[] = "Hello World!";
    int c = 'l';
    char *res;

    res = rindex(str, c);

    cr_assert_str_eq(res, "ld!");
}

Test(rindex, last_char_before_terminator)
{
    char str[] = "Hello World!";
    int c = '!';
    char *res;

    res = rindex(str, c);

    cr_assert_str_eq(res, "!");
}

Test(rindex, null_terminator)
{
    char str[] = "Hello World!";
    int c = '\0';
    char *res;

    res = rindex(str, c);

    cr_assert_str_eq(res, "");
}

Test(rindex, char_not_in_string)
{
    char str[] = "Hello World!";
    int c = 'z';
    char *res;

    res = rindex(str, c);

    cr_assert_eq(res, NULL);
}
