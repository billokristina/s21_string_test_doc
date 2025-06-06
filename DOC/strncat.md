1. Обычное объединение строк
    - **Описание:** Проверка стандартного случая, когда к dest добавляется часть строки src (не превышающая n символов).
    - **Входные данные:**
        - `dest = "Hello"`
        - `src = " World"`
        - `n = 6`
    - **Ожидаемый результат:** dest становится "Hello World".

2. Объединение с `n` меньше длины `src`
    - **Описание:** Проверка, что добавляются только первые n символов из src.
    - **Входные данные:**
        - `dest = "Test"`
        - `src = "ing123"`
        - `n = 3`
    - **Ожидаемый результат:** `dest` становится `"Testing"`.

3. Объединение с `n` равным нулю
    - **Описание:** Проверка, что при `n = 0` строка `dest` не изменяется.
    - **Входные данные:**
        - `dest = "Hello"`
        - `src = " World"`
        - `n = 0`
    - **Ожидаемый результат:** `dest` остается `"Hello"`.

4. Объединение с `n` больше длины `src`
    - **Описание:** Проверка, что вся строка `src` добавляется, даже если `n` больше её длины.
    - **Входные данные:**
        - `dest = "Start"`
        - `src = "End"`
        - `n = 10`
    - **Ожидаемый результат:** `dest` становится `"StartEnd"`.

5. Пустая строка `src`
    - **Описание:** Проверка, что при пустой `src` строка `dest` не изменяется.
    - **Входные данные:**
        - `dest = "Hello"`
        - `src = ""`
        - `n = 5`
    - **Ожидаемый результат:** Ожидаемый результат: `dest` остается `"Hello"`.

6. Пустая строка `dest`
    - **Описание:** Проверка, что `src` добавляется к пустой строке `dest`.
    - **Входные данные:**
        - `dest = ""`
        - `src = "Append"`
        - `n = 6`
    - **Ожидаемый результат:** `dest` становится `"Append"`.

7. Добавление части строки с нулевым символом внутри `src`
    - **Описание:** Проверка, что функция корректно обрабатывает `src` с нулевым символом
    - **Входные данные:**
        - `dest = "Hello"`
        - `src = " Wo\0rld"`
        - `n = 5`
    - **Ожидаемый результат:** `dest` становится `"Hello Wo"` (так как `strncat` останавливается на `\0` в `src`).

8. Переполнение буфера `dest`
    - **Описание:** Проверка, что функция не выходит за пределы буфера `dest` (небезопасное поведение, но должно быть учтено в тестах).
    - **Входные данные:**
        - `dest = "Small"`
        - `src = "Bigger"`
        - `n = 6`
    - **Ожидаемый результат:** еопределенное поведение (UB), но в тестах можно проверить, что функция не падает (например, с помощью `valgrind`).

9. `dest` и `src` перекрываются
    - **Описание:** Проверка неопределенного поведения при перекрывающихся строках.
    - **Входные данные:**
        - `char buf[10] = "Overlap"`
        - `dest = buf`
        - `src = buf + 2`
        - `n = 3`
    - **Ожидаемый результат:** Неопределенное поведение (UB), но можно проверить, что функция не падает.

10. Добавление строки с `n` равным длине `src`
    - **Описание:** Проверка, что при `n = strlen(src)` добавляется вся строка `src`.
    - **Входные данные:**
        - `dest = "Complete"`
        - `src = "Me"`
        - `n = 2`
    - **Ожидаемый результат:** `dest` становится `"CompleteMe"`.

11. Добавление строки с `n` равным 1
    - **Описание:** Проверка, что добавляется только первый символ `src`
    - **Входные данные:**
        - `dest = "One"`
        - `src = "Two"`
        - `n = 1`
    - **Ожидаемый результат:** `dest` становится `"OneT"`.

12. `src` содержит только нулевые символы
    - **Описание:** Проверка, что если `src` состоит из `\0`, `dest` не изменяется.
    - **Входные данные:**
        - `dest = "NoChange"`
        - `src = "\0\0\0"`
        - `n = 3`
    - **Ожидаемый результат:** `dest` остается `"NoChange"`.

13. `dest` изначально содержит мусор, но оканчивается нулевым символом
    - **Описание:** Проверка, что функция корректно обрабатывает `dest` с мусором, но валидным `\0`.
    - **Входные данные:**
        - `char dest[10] = {'H', 'i', '\0', 'x', 'x', 'x'}`
        - `src = "Test"`
        - `n = 4`
    - **Ожидаемый результат:** `dest` становится `"HiTest"` (остальные символы буфера не проверяются).