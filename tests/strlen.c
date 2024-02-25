/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strlen
*/

#include <criterion/criterion.h>

extern size_t strlen(const char *str);

Test(strlen, string)
{
    char str[] = "Hello World!";
    size_t len;

    len = strlen(str);

    cr_assert_eq(len, 12);
}

Test(strlen, zero_len)
{
    char str[] = "";
    size_t len;

    len = strlen(str);

    cr_assert_eq(len, 0);
}

Test(strlen, string_with_null_byte)
{
    char str[] = "Hello\0World";
    size_t len;

    len = strlen(str);

    cr_assert_eq(len, 5);
}
