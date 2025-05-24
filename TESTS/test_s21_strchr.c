#include "all_test.h"

START_TEST(strchr_1)
{
    char str[] = "Hello, world!";
    int c = 'H';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2)
{
    char str[] = "Hello, world!";
    int c = 'o';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3)
{
    char str[] = "Hello, world!";
    int c = '!';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4)
{
    char str[] = "Hello, world!";
    int c = 'z';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5)
{
    char str[] = "Hello";
    int c = '\0';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_6)
{
    char str[] = "";
    int c = 'a';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_7)
{
    char str[] = "Hello, world!";
    int c = 'l';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_8)
{
    char str[] = "Hello";
    int c = 1084;
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_9)
{
    char str[] = "Hello";
    int c = 'h';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *test_strchr(void)
{
    Suite *suite = suite_create("strchr_s");
    TCase *tc_core = tcase_create("strchr_tc");

    tcase_add_test(tc_core, strchr_1);
    tcase_add_test(tc_core, strchr_2);
    tcase_add_test(tc_core, strchr_3);
    tcase_add_test(tc_core, strchr_4);
    tcase_add_test(tc_core, strchr_5);
    tcase_add_test(tc_core, strchr_6);
    tcase_add_test(tc_core, strchr_7);
    tcase_add_test(tc_core, strchr_8);
    tcase_add_test(tc_core, strchr_9);

    suite_add_tcase(suite, tc_core);
    return suite;
}
