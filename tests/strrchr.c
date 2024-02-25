/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strrchr
*/

#include <criterion/criterion.h>

extern char *strrchr(const char *s, int c);

Test(strrchr, string)
{
    char str[] = "Hello World!";
    int c = 'W';
    char *res;

    res = strrchr(str, c);

    cr_assert_str_eq(res, "World!");
}

Test(strrchr, multiple_occurrences)
{
    char str[] = "Hello World!";
    int c = 'l';
    char *res;

    res = strrchr(str, c);

    cr_assert_str_eq(res, "ld!");
}

Test(strrchr, first_char)
{
    char str[] = "Hello World!";
    int c = 'H';
    char *res;

    res = strrchr(str, c);

    cr_assert_str_eq(res, "Hello World!");
}

Test(strrchr, last_char_before_terminator)
{
    char str[] = "Hello World!";
    int c = '!';
    char *res;

    res = strrchr(str, c);

    cr_assert_str_eq(res, "!");
}

Test(strrchr, null_terminator)
{
    char str[] = "Hello World!";
    int c = '\0';
    char *res;

    res = strrchr(str, c);

    cr_assert_str_eq(res, "");
}

Test(strrchr, char_not_in_string)
{
    char str[] = "Hello World!";
    int c = 'z';
    char *res;

    res = strrchr(str, c);

    cr_assert_eq(res, NULL);
}
