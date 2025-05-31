#include "all_test.h"

START_TEST(strcspn_1)
{
    const char *str1 = "";
    const char *str2 = "abc";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2)
{
    const char *str1 = "hello";
    const char *str2 = "";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3)
{
    const char *str1 = "";
    const char *str2 = "";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4)
{
    const char *str1 = "12345";
    const char *str2 = "abc";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5)
{
    const char *str1 = "apple";
    const char *str2 = "a";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6)
{
    const char *str1 = "hello";
    const char *str2 = "l";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7)
{
    const char *str1 = "world";
    const char *str2 = "d";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8)
{
    const char *str1 = "test";
    const char *str2 = "xs";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9)
{
    const char *str1 = "aaa";
    const char *str2 = "a";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10)
{
    const char *str1 = "hello";
    const char *str2 = "xl";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_11)
{
    const char *str1 = "example";
    const char *str2 = "aee";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_12)
{
    const char *str1 = "abc\0def";
    const char *str2 = "xyz";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_13)
{
    const char *str1 = "abcdef";
    const char *str2 = "x\0y";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_14)
{
    const char *str1 = "a\nb\tc";
    const char *str2 = "\t";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_15)
{
    const char *str1 = "user123";
    const char *str2 = "0123456789";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void)
{
    Suite *s = suite_create("strcspn_s");
    TCase *tc = tcase_create("strcspn_tc");

    tcase_add_test(tc, strcspn_1);
    tcase_add_test(tc, strcspn_2);
    tcase_add_test(tc, strcspn_3);
    tcase_add_test(tc, strcspn_4);
    tcase_add_test(tc, strcspn_5);
    tcase_add_test(tc, strcspn_6);
    tcase_add_test(tc, strcspn_7);
    tcase_add_test(tc, strcspn_8);
    tcase_add_test(tc, strcspn_9);
    tcase_add_test(tc, strcspn_10);
    tcase_add_test(tc, strcspn_11);
    tcase_add_test(tc, strcspn_12);
    tcase_add_test(tc, strcspn_13);
    tcase_add_test(tc, strcspn_14);
    tcase_add_test(tc, strcspn_15);

    suite_add_tcase(s, tc);
    return s;
}
