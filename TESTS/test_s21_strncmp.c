#include "all_test.h"

START_TEST(strncmp_1)
{
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2)
{
    const char *str1 = "Apple";
    const char *str2 = "Banana";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3)
{
    const char *str1 = "Zebra";
    const char *str2 = "Apple";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4)
{
    const char *str1 = "Hello";
    const char *str2 = "Hello, world!";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5)
{
    const char *str1 = "abcdef";
    const char *str2 = "abzdef";
    s21_size_t n = 6;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6)
{
    const char *str1 = "Hello";
    const char *str2 = "World";
    s21_size_t n = 0;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7)
{
    const char *str1 = "Hello";
    const char *str2 = "HelloWorld";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8)
{
    const char *str1 = "abcd";
    const char *str2 = "abce";
    s21_size_t n = 4;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9)
{
    const char *str1 = "abc";
    const char *str2 = "abcde";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10)
{
    const char *str1 = "abc";
    const char *str2 = "abc";
    s21_size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11)
{
    const char str1[] = {'a', 'b', '\0', 'c', 'd'};
    const char str2[] = {'a', 'b', '\0', 'e', 'f'};
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_12)
{
    const char *str1 = "hello";
    const char *str2 = "Hello";
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_13)
{
    const char *str1 = "";
    const char *str2 = "";
    s21_size_t n = 1;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14)
{
    const char *str1 = "a\tb";
    const char *str2 = "a\nb";
    s21_size_t n = 3;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_15)
{
    const char *str1 = "привет";
    const char *str2 = "пока";
    s21_size_t n = 2;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *test_strncmp(void)
{
    Suite *s = suite_create("strncmp_s");
    TCase *tc = tcase_create("strncmp_tc");

    tcase_add_test(tc, strncmp_1);
    tcase_add_test(tc, strncmp_2);
    tcase_add_test(tc, strncmp_3);
    tcase_add_test(tc, strncmp_4);
    tcase_add_test(tc, strncmp_5);
    tcase_add_test(tc, strncmp_6);
    tcase_add_test(tc, strncmp_7);
    tcase_add_test(tc, strncmp_8);
    tcase_add_test(tc, strncmp_9);
    tcase_add_test(tc, strncmp_10);
    tcase_add_test(tc, strncmp_11);
    tcase_add_test(tc, strncmp_12);
    tcase_add_test(tc, strncmp_13);
    tcase_add_test(tc, strncmp_14);
    tcase_add_test(tc, strncmp_15);

    suite_add_tcase(s, tc);
    return s;
}