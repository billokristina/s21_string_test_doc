#include "all_test.h"

int main(void)
{
    int fail = 0;
    Suite *s21_string_test[] = {test_memchr(), test_memcmp(), test_memcpy(), test_memset(), test_strncat(), NULL};
    for (int i = 0; s21_string_test[i] != NULL; i++)
    {
        SRunner *sr = srunner_create(s21_string_test[i]);
    }
}