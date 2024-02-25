/*
** EPITECH PROJECT, 2024
** B-ASM-400-REN-4-1-asmminilibc-hugues.lejeune [WSL: Ubuntu]
** File description:
** strstr
*/

#include <criterion/criterion.h>

extern char *strstr(const char *haystack, const char *needle);

Test(strstr, search_same_string)
{
    char haystack[] = "Hello World!";
    char needle[] = "Hello World!";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_str_eq(res, "Hello World!");
}

Test(strstr, search_substring_in_string)
{
    char haystack[] = "Hello World!";
    char needle[] = "lo Wo";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_str_eq(res, "lo World!");
}

Test(strstr, search_substring_at_start)
{
    char haystack[] = "Hello World!";
    char needle[] = "Hell";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_str_eq(res, "Hello World!");
}

Test(strstr, search_substring_at_end)
{
    char haystack[] = "Hello World!";
    char needle[] = "orld!";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_str_eq(res, "orld!");
}

Test(strstr, substring_not_in_string)
{
    char haystack[] = "Hello World!";
    char needle[] = "zaza";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_eq(res, NULL);
}

Test(strstr, search_null_terminator)
{
    char haystack[] = "";
    char needle[] = "";
    char *res;

    res = strstr(haystack, needle);

    cr_assert_str_eq(res, "");
}
