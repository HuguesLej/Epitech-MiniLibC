/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** memmove
*/

#include <criterion/criterion.h>

extern void *memmove(void *dest, const void *src, size_t n);

Test(memmove, simple_copy)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";

    memmove(dest, src, 5);

    cr_assert_str_eq(dest, "Helloyuiop");
}

Test(memmove, verify_return)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";
    char *res;

    res = memmove(dest, src, 5);

    cr_assert_str_eq(dest, "Helloyuiop");
}

Test(memmove, copy_zero_bytes)
{
    char src[] = "Hello World!";
    char dest[] = "azertyuiop";
    char *res;

    res = memmove(dest, src, 0);

    cr_assert_str_eq(res, "azertyuiop");
}

Test(memmove, copy_int)
{
    int src = 1111;
    int dest = 0;
    int *res;

    res = memmove(&dest, &src, 2);

    cr_assert_eq(*res, 1111);
}

Test(memmove, overlapping)
{
    char src[] = "Hello World!";
    char *res;

    res = memmove(src, src, 5);

    cr_assert_str_eq(res, "Hello World!");
}

Test(memmove, dest_before_src)
{
    char src[] = "Hello World!";
    char *res;

    res = memmove(src, src + 2, 5);

    cr_assert_str_eq(res, "llo W World!");
}

Test(memmove, src_before_dest)
{
    char src[] = "Hello World!";
    char *res;

    res = memmove(src + 2, src, 5);

    cr_assert_str_eq(res, "Helloorld!");
}

Test(memmove, verify_original_string)
{
    char src[] = "Hello World!";

    memmove(src + 2, src, 5);

    cr_assert_str_eq(src, "HeHelloorld!");
}
