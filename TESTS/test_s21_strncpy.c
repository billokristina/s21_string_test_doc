#include "all_test.h"

START_TEST(strncpy_1)
{
    char src[] = "Hello";
    char dest1[6] = {0};
    char dest2[6] = {0};
    s21_size_t n = 6;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_2)
{
    char src[] = "Hello, World!";
    char dest1[5] = {0};
    char dest2[5] = {0};
    s21_size_t n = 5;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_3)
{
    char src[] = "Hello";
    char dest1[10] = "abc";
    char dest2[10] = "abc";
    s21_size_t n = 0;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_4)
{
    char src[] = "";
    char dest1[5] = {0};
    char dest2[5] = {0};
    s21_size_t n = 5;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_5)
{
    char src[] = "Hi";
    char dest1[5] = {0};
    char dest2[5] = {0};
    s21_size_t n = 5;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_6)
{
    char str1[10] = "Hello";
    char str2[10] = "Hello";
    s21_size_t n = 3;

    ck_assert_pstr_eq(s21_strncpy(str1 + 2, str1, n), strncpy(str2 + 2, str2, n));
}
END_TEST

START_TEST(strncpy_7)
{
    char src[] = "Hello, World!";
    char dest1[5] = {0};
    char dest2[5] = {0};
    s21_size_t n = 5;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_8)
{
    char src[] = "Test";
    char dest1[6] = {0};
    char dest2[6] = {0};
    s21_size_t n = 6;

    ck_assert_pstr_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
}
END_TEST

Suite *test_strncpy(void)
{
    Suite *s = suite_create("strncpy_s");

    TCase *tc_core = tcase_create("strncpy_tc");
    tcase_add_test(tc_core, strncpy_1);
    tcase_add_test(tc_core, strncpy_2);
    tcase_add_test(tc_core, strncpy_3);
    tcase_add_test(tc_core, strncpy_4);
    tcase_add_test(tc_core, strncpy_5);
    tcase_add_test(tc_core, strncpy_8);
    suite_add_tcase(s, tc_core);

    TCase *tc_edge = tcase_create("Edge");
    tcase_add_test(tc_edge, strncpy_6);
    tcase_add_test(tc_edge, strncpy_7);
    suite_add_tcase(s, tc_edge);

    return s;
}