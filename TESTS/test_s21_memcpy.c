#include <all_test.h>

START_TEST(memcpy_1)
{
    const char src[] = "hello";
    char dest1[6] = {0};
    char dest2[6] = {0};
    size_t n = strlen(src) + 1;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(memcpy_2)
{
    const char src[] = "\x01\x02\x03\x04";
    char dest1[4], dest2[4];
    size_t n = sizeof(src) - 1;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(memcpy_3)
{
    const char src[] = "abc";
    char dest1[4] = {0};
    char dest2[4] = {0};
    size_t n = 0;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_4)
{
    const char src[] = "abcdef";
    char dest1[7] = {0};
    char dest2[7] = {0};
    size_t n = 3;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_5)
{
    char data1[] = "abcdef";
    char data2[] = "abcdef";
    size_t n = 5;

    void *res1 = s21_memcpy(data1 + 1, data1, n);
    void *res2 = memcpy(data2 + 1, data2, n);

    ck_assert_ptr_eq(res1, data1 + 1);
    ck_assert_ptr_eq(res2, data2 + 1);
    ck_assert_mem_eq(data1, data2, sizeof(data1));
}
END_TEST

START_TEST(memcpy_6)
{
    char dest1[5] = {0};
    char dest2[5] = {0};
    size_t n = 5;

    void *res1 = s21_memcpy(dest1, NULL, n);
    void *res2 = memcpy(dest2, NULL, n);

    ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(memcpy_7)
{
    const char src[] = "abc";
    size_t n = 3;

    void *res1 = s21_memcpy(NULL, src, n);
    void *res2 = memcpy(NULL, src, n);

    ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(memcpy_8)
{
    const size_t MB = 1024 * 1024;
    char *src = (char *)malloc(MB);
    char *dest1 = (char *)malloc(MB);
    char *dest2 = (char *)malloc(MB);
    memset(src, 'a', MB);

    void *res1 = s21_memcpy(dest1, src, MB);
    void *res2 = memcpy(dest2, src, MB);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, MB);

    free(src);
    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(memcpy_9)
{
    const char src[] = "ab\0cd";
    char dest1[6] = {0};
    char dest2[6] = {0};
    size_t n = 5;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(memcpy_10)
{
    const char src[] = "abcdef";
    char dest1[3] = {0};
    char dest2[3] = {0};
    size_t n = 6;

    void *res1 = s21_memcpy(dest1, src, n);
    void *res2 = memcpy(dest2, src, n);

    ck_assert_ptr_eq(res1, dest1);
    ck_assert_ptr_eq(res2, dest2);
    ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

START_TEST(memcpy_11)
{
    const char src[] = "\x01\x00\x00\x00";
    int dest1 = 0, dest2 = 0;
    size_t n = 4;

    void *res1 = s21_memcpy(&dest1, src, n);
    void *res2 = memcpy(&dest2, src, n);

    ck_assert_ptr_eq(res1, &dest1);
    ck_assert_ptr_eq(res2, &dest2);
    ck_assert_int_eq(dest1, dest2);
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