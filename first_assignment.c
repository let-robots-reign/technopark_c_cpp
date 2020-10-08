/*
 * Вариант #65
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих, как минимум, три различных символа.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 * их количество и указатель на результирующую структуру. На выход функция должна возвращать количество строк
 * в результирующей структуре. Результат обработки выводится на экран.
 */

#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 2
#define LINE_LENGTH 100


size_t strlen(const char *str) {
    for (size_t len = 0; ; ++str, ++len) {
        if (!*str) return len;
    }
}

char* strcpy(char *to, const char *from) {
    char *tmp = to;
    while ((*to++ = *from++));
    return tmp;
}

int filter_strings(char **strings_vector, int vector_size, char **filtered) {
    for (int i = 0; i < vector_size; ++i) {

    }
}

int main() {
    char **strings;
    int size = INIT_SIZE;
    int capacity = 0;
    char line[LINE_LENGTH];
    size_t len = 0;

    strings = (char**) malloc(size * sizeof(char*));

    while (fgets(line, LINE_LENGTH, stdin) != NULL && (len = strlen(line)) > 1) {
        // grow array if necessary
        if (size == capacity) {
            size *= 2;
            strings = (char**) realloc(strings, size * sizeof(char*));
        }

        // remove trailing '\n'
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        strings[capacity] = (char*) malloc((strlen(line) + 1) * sizeof(char));
        strcpy(strings[capacity], line);
        ++capacity;
    }

    for (int i = 0; i < capacity; ++i) {
        puts(strings[i]);
        free(strings[i]);
    }

    free(strings);

    return 0;
}