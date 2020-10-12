/*
 * Вариант #65
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих, как минимум, три различных символа.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на
 * вектор строк, их количество и указатель на результирующую структуру. На выход
 * функция должна возвращать количество строк в результирующей структуре.
 * Результат обработки выводится на экран.
 */

#include <stdio.h>
#include <stdlib.h>

#include "filter.h"
#include "string_functions.h"

#define INIT_SIZE 2
#define LINE_LENGTH 100

typedef struct StringsVector {
    char **strings;
    size_t size;
    size_t capacity;
} StringsVector;

StringsVector input_strings_vector();

StringsVector empty_strings_vector();

void print_vector(char **strings, size_t size);

void free_vector(char **strings, size_t size);

int main() {
    puts("Enter lines. To stop, enter a blank line");
    const StringsVector sv = input_strings_vector();
    if (!sv.strings && !sv.size) {
        puts("Failed to allocate memory for input strings");
        return 1;
    }
    if (!sv.capacity) {
        puts("No lines were entered. Filtration cannot be performed");
        return 0;
    }

    char **filtered = (char **) malloc(sv.capacity * sizeof(char *));
    if (!filtered) {
        puts("Failed to allocate memory for filtered strings");
        return 1;
    }
    const int count_filtered = filter_strings((const char **) sv.strings, sv.capacity, filtered);
    if (count_filtered == FILTER_FAILED) {
        puts("Failed to allocate memory for a filtered string");
        free(filtered);
        return 1;
    }

    puts("Entered lines:");
    print_vector(sv.strings, sv.capacity);

    printf("%d lines remain after filtration\n", count_filtered);

    puts("Filtered lines:");
    print_vector(filtered, count_filtered);

    free_vector(sv.strings, sv.capacity);
    free_vector(filtered, count_filtered);

    return 0;
}

StringsVector input_strings_vector() {
    size_t size = INIT_SIZE;
    size_t capacity = 0;
    char line[LINE_LENGTH];
    size_t len;

    char **strings = (char **) malloc(size * sizeof(char *));
    if (!strings) {
        return empty_strings_vector();
    }

    while (fgets(line, LINE_LENGTH, stdin) != NULL && (len = strlen(line)) > 1) {
        // grow array if necessary
        if (size == capacity) {
            size *= 2;
            char **old_buffer = strings;  // save pointer in case realloc fails
            strings = (char **) realloc(strings, size * sizeof(char *));
            if (!strings) {
                free(old_buffer);
                return empty_strings_vector();
            }
        }

        // remove trailing '\n'
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *new_line = (char *) malloc(strlen(line) + 1);
        if (!new_line) {
            return empty_strings_vector();
        }
        strings[capacity] = new_line;
        strcpy(strings[capacity], line);
        ++capacity;
    }

    StringsVector sv = {strings, size, capacity};
    return sv;
}

StringsVector empty_strings_vector() {
    StringsVector sv = {NULL, 0, 0};
    return sv;
}

void print_vector(char **strings, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        puts(strings[i]);
    }
}

void free_vector(char **strings, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        free(strings[i]);
    }
    free(strings);
}
