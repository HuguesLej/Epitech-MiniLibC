/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** memcpy
*/

#include <criterion/criterion.h>

extern void *memcpy(void *dest, const void *src, size_t n);

Test(memcpy, simple_copy)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";

    memcpy(dest, src, 5);

    cr_assert_str_eq(dest, "Helloyuiop");
}

Test(memcpy, verify_return)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";
    char *res;

    res = memcpy(dest, src, 5);

    cr_assert_str_eq(dest, "Helloyuiop");
}

Test(memcpy, copy_zero_bytes)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";
    char *res;

    res = memcpy(dest, src, 0);

    cr_assert_str_eq(res, "azertyuiop");
}

Test(memcpy, copy_int)
{
    int src = 1111;
    int dest = 0;
    int *res;

    res = memcpy(&dest, &src, 2);

    cr_assert_eq(*res, 1111);
}
