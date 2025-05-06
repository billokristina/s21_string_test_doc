#include "all_test.h"

START_TEST(memcmp_1)
{
    const char *str1 = "abc";
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_2)
{
    const char *str1 = "abc";
    const char *str2 = "abd";
    s21_size_t n = 3;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_3)
{
    const char *str1 = "abd";
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_4)
{
    const char *str1 = "abc";
    const char *str2 = "def";
    s21_size_t n = 0;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_5)
{
    const char *str1 = "abc";
    const char *str2 = "ab";
    s21_size_t n = 2;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_6)
{
    const char *str1 = "ab\0c";
    const char *str2 = "ab\0d";
    s21_size_t n = 4;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_7)
{
    const char *str1 = "\x01\x02\x03";
    const char *str2 = "\x01\x02\x04";
    s21_size_t n = 3;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_8)
{
    const char *str1 = "café";
    const char *str2 = "café";
    s21_size_t n = 5;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_9)
{
    const char *str1 = s21_NULL;
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_10)
{
    const char *str1 = "abc";
    const char *str2 = "abc";
    s21_size_t n = 10;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_11)
{
    const s21_size_t size = 1024 * 1024;
    char *str1 = (char *)malloc(size);
    char *str2 = (char *)malloc(size);

    memset(str1, 'a', size);
    memset(str2, 'a', size);

    str2[size - 1] = 'b';

    int result = s21_memcmp(str1, str2, size);
    int expected = memcmp(str1, str2, size);

    ck_assert_int_eq(result, expected);

    free(str1);
    free(str2);
}
END_TEST

START_TEST(memcmp_12)
{
    const char *str1 = "aaaaa";
    const char *str2 = "aaaab";
    s21_size_t n = 5;

    int result = s21_memcmp(str1, str2, n);
    int expected = memcmp(str1, str2, n);

    ck_assert_int_eq(result, expected);
}
END_TEST

Suite *test_memcmp(void)
{
    Suite *s = suite_create("memcmp_s");
    TCase *tc = tcase_create("memcmp_tc");

    tcase_add_test(tc, memcmp_1);
    tcase_add_test(tc, memcmp_2);
    tcase_add_test(tc, memcmp_3);
    tcase_add_test(tc, memcmp_4);
    tcase_add_test(tc, memcmp_5);
    tcase_add_test(tc, memcmp_6);
    tcase_add_test(tc, memcmp_7);
    tcase_add_test(tc, memcmp_8);
    tcase_add_test(tc, memcmp_9);
    tcase_add_test(tc, memcmp_10);
    tcase_add_test(tc, memcmp_11);
    tcase_add_test(tc, memcmp_12);

    suite_add_tcase(s, tc);
    return s;
}