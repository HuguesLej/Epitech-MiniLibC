/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strpbrk
*/

#include <criterion/criterion.h>

extern char *strpbrk(const char *s, const char *accept);

Test(strpbrk, first_char_in_string)
{
    char str[] = "Hello";
    char accept[] = "abcdefgHij";
    char *res;

    res = strpbrk(str, accept);

    cr_assert_str_eq(res, "Hello");
}

Test(strpbrk, last_char_in_string)
{
    char str[] = "Hello";
    char accept[] = "\0";
    char *res;

    res = strpbrk(str, accept);

    cr_assert_eq(res, NULL);
}

Test(strpbrk, last_char_before_terminator)
{
    char str[] = "Hello";
    char accept[] = "aoz";
    char *res;

    res = strpbrk(str, accept);

    cr_assert_str_eq(res, "o");
}

Test(strpbrk, char_in_string)
{
    char str[] = "Hello";
    char accept[] = "gezt";
    char *res;

    res = strpbrk(str, accept);

    cr_assert_str_eq(res, "ello");
}

Test(strpbrk, char_not_in_string)
{
    char str[] = "Hello";
    char accept[] = "gzt";
    char *res;

    res = strpbrk(str, accept);

    cr_assert_eq(res, NULL);
}
