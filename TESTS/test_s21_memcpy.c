#include <all_test.h>

START_TEST(memcpy_1)
{
    const char *src = "hello";
    char dest[6];
    size_t n = 6;

    void *result = s21_memcpy(dest, src, n);
    ck_assert_ptr_eq(result, dest);
    ck_assert_str_eq(dest, "hello");
}
END_TEST

START_TEST(memcpy_2)
{
    const char *src = "\x01\x02\x03\x04";
    char dest[4];
    size_t n = 4;

    void *result = s21_memcpy(dest, src, n);
    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, src, n);
}
END_TEST

START_TEST(memcpy_3)
{
    const char *src = "abc";
    char dest[4] = {0};
    size_t n = 0;

    void *result = s21_memcpy(dest, src, n);
    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, "\0\0\0\0", n);
}
END_TEST

START_TEST(memcpy_4)
{
    const char *src = "abcdef";
    char dest[7] = {0};
    size_t n = 3;

    void *result = s21_memcpy(dest, src, n);
    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, "abc\0\0\0", 7);
}
END_TEST

START_TEST(memcpy_5)
{
    char dest = "abcdef";
    size_t n = 5;

    void *result = s21_memcpy(dest + 1, dest, n);
    ck_assert_ptr_eq(result, dest + 1);
    ck_assert_str_eq(dest, "aabcde");
}
END_TEST

START_TEST(memcpy_6)
{
    const char *src = s21_NULL;
    char dest[5] = {0};
    size_t n = 5;

    void *result = s21_memcpy(dest, src, n);

    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(memcpy_7)
{
    const char *src = "abc";
    char dest[10] = {0};
    size_t n = 10;

    void *result = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, "abc\0", 4);
}
END_TEST

START_TEST(memcpy_8)
{
    const size_t MB = 1024 * 1024;
    char *src = (char *)malloc(MB);
    char *dest = (char *)malloc(MB);
    memset(src, 'a', MB);

    void *result = s21_memcpy(dest, src, MB);

    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, src, MB);
    free(src);
    free(dest);
}
END_TEST

START_TEST(memcpy_9)
{
    const char src[] = "ab\0cd";
    char dest[6] = {0};
    size_t n = 5;

    void *result = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, src, n);
}
END_TEST

START_TEST(memcpy_10)
{
    const char *src = "abcdef";
    char dest[3] = {0};
    size_t n = 6;

    void *result = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, "abc", 3);
}
END_TEST

START_TEST(memcpy_11)
{
    const char src[] = "\x01\x00\x00\x00";
    int dest = 0;
    size_t n = 4;

    void *result = s21_memcpy(&dest, src, n);

    ck_assert_ptr_eq(result, &dest);
    ck_assert_int_eq(dest, 1);
}
END_TEST

Suite *test_memcpy(void)
{
    Suite *s = suite_create("memcpy_s");
    TCase *tc = tcase_create("memcpy_tc");

    tcase_add_test(tc, memcpy_1);
    tcase_add_test(tc, memcpy_2);
    tcase_add_test(tc, memcpy_3);
    tcase_add_test(tc, memcpy_4);
    tcase_add_test(tc, memcpy_5);
    tcase_add_test(tc, memcpy_6);
    tcase_add_test(tc, memcpy_7);
    tcase_add_test(tc, memcpy_8);
    tcase_add_test(tc, memcpy_9);
    tcase_add_test(tc, memcpy_10);
    tcase_add_test(tc, memcpy_11);

    suite_add_tcase(s, tc);

    return s;
}