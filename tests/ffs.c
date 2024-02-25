/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** ffs
*/

#include <criterion/criterion.h>

extern int ffs(int i);

Test(ffs, zero)
{
    int i = 0;
    int res;

    res = ffs(i);

    cr_assert_eq(res, 0);
}

Test(ffs, one)
{
    int i = 1;
    int res;

    res = ffs(i);

    cr_assert_eq(res, 1);
}

Test(ffs, result_nine)
{
    int i = 256;
    int res;

    res = ffs(i);

    cr_assert_eq(res, 9);
}
