/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** memset
*/

#include <criterion/criterion.h>

extern void *memset(void *s, int c, size_t n);

Test(memset, fill_string)
{
    char str[10];
    int c = '0';

    str[9] = '\0';

    memset(str, c, 9);

    cr_assert_str_eq(str, "000000000");
}

Test(memset, verify_return)
{
    char str[10];
    int c = '0';
    char *res;

    str[9] = '\0';

    res = memset(str, c, 9);

    cr_assert_str_eq(res, "000000000");
}

Test(memset, fill_all_bytes)
{
    char str[10];
    int c = '0';
    char *res;

    res = memset(str, c, 10);

    cr_assert_str_eq(res, "0000000000");
}

Test(memset, fill_int)
{
    int s;
    int c = 0;
    int *res;

    res = memset(&s, c, sizeof(int));

    cr_assert_eq(*res, 0000);
}
