/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strcspn
*/

#include <criterion/criterion.h>

extern size_t strcspn(const char *s, const char *reject);

Test(strcspn, char_at_middle_of_string)
{
    char str[] = "Hello World!";
    char reject[] = "agty ";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 5);
}

Test(strcspn, char_at_start_of_string)
{
    char str[] = "Hello World!";
    char reject[] = "agtHy ";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 0);
}

Test(strcspn, char_at_end_of_string)
{
    char str[] = "Hello World!";
    char reject[] = "agt!y";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 11);
}

Test(strcspn, char_not_in_string)
{
    char str[] = "Hello World!";
    char reject[] = "agty";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 12);
}

Test(strcspn, empty_string)
{
    char str[] = "";
    char reject[] = "agty";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 0);
}

Test(strcspn, empty_reject)
{
    char str[] = "Hello World!";
    char reject[] = "";
    size_t res;

    res = strcspn(str, reject);

    cr_assert_eq(res, 12);
}
