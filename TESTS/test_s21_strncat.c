#include "all_test.h"

START_TEST(strncat_1)
{
    char dest1[12] = "Hello";
    char dest2[12] = "Hello";
    char src[] = "World";
    s21_size_t n = 6;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_2)
{
    char dest1[10] = "Test";
    char dest2[10] = "Test";
    char src[] = "ing123";
    s21_size_t n = 3;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_3) {
    char dest1[10] = "Hello";
    char dest2[10] = "Hello";
    char src[] = " World";
    s21_size_t n = 0;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_4) {
    char dest1[10] = "Start";
    char dest2[10] = "Start";
    char src[] = "End";
    s21_size_t n = 10;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_5) {
    char dest1[10] = "Hello";
    char dest2[10] = "Hello";
    char src[] = "";
    s21_size_t n = 5;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_6) {
    char dest1[10] = "";
    char dest2[10] = "";
    char src[] = "Append";
    s21_size_t n = 6;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_7) {
    char dest1[15] = "Hello";
    char dest2[15] = "Hello";
    char src[] = " Wo\0rld";
    s21_size_t n = 5;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_8) {
    char dest1[6] = "Small";
    char dest2[6] = "Small";
    char src[] = "Bigger";
    s21_size_t n = 6;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_9) {
    char buf1[10] = "Overlap";
    char buf2[10] = "Overlap";
    s21_size_t n = 3;

    ck_assert_str_eq(s21_strncat(buf1, buf1 + 2, n), strncat(buf2, buf2 + 2, n));
}
END_TEST

START_TEST(strncat_10) {
    char dest1[15] = "Complete";
    char dest2[15] = "Complete";
    char src[] = "Me";
    s21_size_t n = 2;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_11) {
    char dest1[10] = "One";
    char dest2[10] = "One";
    char src[] = "Two";
    s21_size_t n = 1;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_12) {
    char dest1[15] = "NoChange";
    char dest2[15] = "NoChange";
    char src[] = "\0\0\0";
    s21_size_t n = 3;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_13) {
    char dest1[10] = {'H', 'i', '\0', 'x', 'x', 'x'};
    char dest2[10] = {'H', 'i', '\0', 'x', 'x', 'x'};
    char src[] = "Test";
    s21_size_t n = 4;

    ck_assert_str_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

Suite *test_strncat(void) {
    Suite *s = suite_create("strncat_s");
    TCase *tc = tcase_create("strncat_tc");

    tcase_add_test(tc, strncat_1);
    tcase_add_test(tc, strncat_2);
    tcase_add_test(tc, strncat_3);
    tcase_add_test(tc, strncat_4);
    tcase_add_test(tc, strncat_5);
    tcase_add_test(tc, strncat_6);
    tcase_add_test(tc, strncat_7);
    tcase_add_test(tc, strncat_8);
    tcase_add_test(tc, strncat_9);
    tcase_add_test(tc, strncat_10);
    tcase_add_test(tc, strncat_11);
    tcase_add_test(tc, strncat_12);
    tcase_add_test(tc, strncat_13);

    suite_add_tcase(s, tc);
    return s;
}