/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** index
*/

#include <criterion/criterion.h>

extern char *index(const char *s, int c);

Test(index, first_char_of_string)
{
    char str[] = "Hello World!";
    int c = 'H';
    char *res;

    res = index(str, c);

    cr_assert_str_eq(res, "Hello World!");
}

Test(index, char_in_string)
{
    char str[] = "Hello World!";
    int c = 'l';
    char *res;

    res = index(str, c);

    cr_assert_str_eq(res, "llo World!");
}

Test(index, last_char_before_terminator)
{
    char str[] = "Hello World!";
    int c = '!';
    char *res;

    res = index(str, c);

    cr_assert_str_eq(res, "!");
}

Test(index, null_terminator)
{
    char str[] = "Hello World!";
    int c = '\0';
    char *res;

    res = index(str, c);

    cr_assert_str_eq(res, "");
}

Test(index, char_not_in_string)
{
    char str[] = "Hello World!";
    int c = 'z';
    char *res;

    res = index(str, c);

    cr_assert_eq(res, NULL);
}
