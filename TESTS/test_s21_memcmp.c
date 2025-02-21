#include <all_test.h>

START_TEST(memcmp_1) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = my_memcmp(str1, str2, n); // Ваша реализация
    int expected = memcmp(str1, str2, n);  // Оригинальная реализация

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_2) {
    const char *str1 = "abc";
    const char *str2 = "abd";
    s21_size_t n = 3;

    int result = my_memcmp(str1, str2, n); // Ваша реализация
    int expected = memcmp(str1, str2, n);  // Оригинальная реализация

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_3) {
    const char *str1 = "abd";
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = my_memcmp(str1, str2, n); // Ваша реализация
    int expected = memcmp(str1, str2, n);  // Оригинальная реализация

    ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_4) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    s21_size_t n = 3;

    int result = my_memcmp(str1, str2, n); // Ваша реализация
    int expected = memcmp(str1, str2, n);  // Оригинальная реализация

    ck_assert_int_eq(result, expected);
}
END_TEST