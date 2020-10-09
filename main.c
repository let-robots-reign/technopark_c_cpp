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

typedef struct StringsVector {
    char **strings;
    size_t size;
    size_t capacity;
} StringsVector;

StringsVector input_strings_vector();
void print_and_free_vector(char **strings, size_t size);


int main() {
    puts("Enter lines. To stop, enter a blank line");
    const StringsVector sv = input_strings_vector();
    if (!sv.capacity) {
        puts("No lines were entered. Filtration cannot be performed");
        return 0;
    }

    char **filtered = (char**) malloc(sv.capacity * sizeof(char*));
    size_t count_filtered = filter_strings((const char **) sv.strings, sv.capacity, filtered);

    puts("Entered lines:");
    print_and_free_vector(sv.strings, sv.capacity);

    printf("%zu lines remain after filtration\n", count_filtered);

    puts("Filtered lines:");
    print_and_free_vector(filtered, count_filtered);

    return 0;
}


StringsVector input_strings_vector() {
    char **strings;
    size_t size = INIT_SIZE;
    size_t capacity = 0;
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

    StringsVector sv = {strings, size, capacity};
    return sv;
}


void print_and_free_vector(char **strings, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        puts(strings[i]);
        free(strings[i]);
    }
    free(strings);
}
