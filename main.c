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
#include "string_functions.h"
#include "filter.h"

#define INIT_SIZE 2
#define LINE_LENGTH 100

void print_and_free_vector(char **strings, size_t size) {
    for (int i = 0; i < size; ++i) {
        puts(strings[i]);
        free(strings[i]);
    }
    free(strings);
}

int main() {
    char **strings;
    int size = INIT_SIZE;
    int capacity = 0;
    char line[LINE_LENGTH];
    size_t len;

    strings = (char**) malloc(size * sizeof(char*));

    while (fgets(line, LINE_LENGTH, stdin) != NULL && (len = strlen(line)) > 1) {
        // grow array if necessary
        if (size == capacity) {
            size *= 2;
            strings = (char**) realloc(strings, size * sizeof(char*));
        }

        // remove trailing '\n'
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        strings[capacity] = (char*) malloc((strlen(line) + 1) * sizeof(char));
        strcpy(strings[capacity], line);
        ++capacity;
    }

    char **filtered = (char**) malloc(capacity * sizeof(char*));
    int count_filtered = filter_strings(strings, capacity, filtered);

    puts("Initial:");
    print_and_free_vector(strings, capacity);

    puts("Filtered:");
    print_and_free_vector(filtered, count_filtered);

    return 0;
}
