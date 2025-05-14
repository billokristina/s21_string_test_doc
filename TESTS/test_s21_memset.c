#include "all_test.h"

START_TEST(memset_1)
{
    char s[] = "abcdefgh";
    int c = 0;
    s21_size_t n = 3;
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_2)
{
    char s[] = "abcdefgh";
    int c = 'A';
    s21_size_t n = 2;
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_3)
{
    char s[] = "abcd";
    int c = 'x';
    s21_size_t n = sizeof(s);
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_4)
{
    char s[] = "test";
    int c = '1';
    s21_size_t n = 0;
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_5)
{
    char s[] = {1, 2, 3, 4, 5};
    int c = -1;
    s21_size_t n = 3;
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_6)
{
    char s[] = {1, 2, 3, 4, 5};
    int c = 0x1234;
    s21_size_t n = 2;
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_7)
{
    int s[] = {1, 2, 3};
    int c = 0;
    s21_size_t n = sizeof(s);
    ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_8)
{
    typedef struct
    {
        char a;
        int b;
    } test_struct;
    test_struct s = {'x', 42};
    int c = 0;
    s21_size_t n = sizeof(s);
    ck_assert_str_eq(memset(&s, c, n), s21_memset(&s, c, n));
}
END_TEST

START_TEST(memset_9)
{
    char s[10] = {0};
    int c = 'a';
    s21_size_t n = 5;
    ck_assert_ptr_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

Suite *test_memset(void)
{
    Suite *s = suite_create("memset_s");
    TCase *tc = tcase_create("memset_tc");

    tcase_add_test(tc, memset_1);
    tcase_add_test(tc, memset_2);
    tcase_add_test(tc, memset_3);
    tcase_add_test(tc, memset_4);
    tcase_add_test(tc, memset_5);
    tcase_add_test(tc, memset_6);
    tcase_add_test(tc, memset_7);
    tcase_add_test(tc, memset_8);
    tcase_add_test(tc, memset_9);

    suite_add_tcase(s, tc);

    return s;
}