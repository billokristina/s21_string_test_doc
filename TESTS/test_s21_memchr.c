#include "all_test.h"

START_TEST(memchr_1)
{
    const char str[] = "a0bcdefg";
    int c = 'a';
    s21_size_t n = strlen(str);

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2)
{
    const char str[] = "abcd!efg";
    int c = '!';
    s21_size_t n = strlen(str);

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3)
{
    const char str[] = "abc_defg";
    int c = 'g';
    s21_size_t n = strlen(str);

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4)
{
    const char str[] = "abcdefg12532";
    int c = 'k';
    s21_size_t n = strlen(str);

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5)
{
    const char str[] = "abcdefg12532";
    int c = '0';
    s21_size_t n = strlen(str);

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6)
{
    const char str[] = "abcdefg";
    int c = 'a';
    s21_size_t n = 0;

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7)
{
    const char str[] = "abcdefg";
    int c = 'd';
    s21_size_t n = 1;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST


START_TEST(memchr_8)
{
    const char str[] = "abcd\0efg";
    int c = '\0';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9)
{
    const char str[] = "abcdefg";
    int c = '\0';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST


START_TEST(memchr_10)
{
    const char str[] = "";
    int c = '1';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_11)
{ 
    const char str[] = s21_NULL;
    int c = '\0';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST


START_TEST(memchr_12)
{
    const char str[] = "café";
    int c = 'é';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_13)
{
    const char str[] = "\x01\x02\x03\x04\x05";
    int c = '\x03';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_14)
{
    const char str[] = "aabbcc";
    int c = 'a';
    s21_size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite *test_memchr(void)
{
    Suite *s = suite_create("memchr_s");
    TCase *tc = tcase_create("memchr_tc");

    tcase_add_test(tc, memchr_1);
    tcase_add_test(tc, memchr_2);
    tcase_add_test(tc, memchr_3);
    tcase_add_test(tc, memchr_4);
    tcase_add_test(tc, memchr_5);
    tcase_add_test(tc, memchr_6);
    tcase_add_test(tc, memchr_7);
    tcase_add_test(tc, memchr_8);
    tcase_add_test(tc, memchr_9);
    tcase_add_test(tc, memchr_10);
    tcase_add_test(tc, memchr_11);
    tcase_add_test(tc, memchr_12);
    tcase_add_test(tc, memchr_13);
    tcase_add_test(tc, memchr_14);

    suite_add_tcase(s, tc);
    return s;
}