/*
 * Вариант #65
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих, как минимум, три различных символа.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на
 * вектор строк, их количество и указатель на результирующую структуру. На выход
 * функция должна возвращать количество строк в результирующей структуре.
 * Результат обработки выводится на экран.
 */

#include "strings_vector.h"

int main() {
    puts("Enter lines. To stop, enter a blank line");
    const StringsVector sv = input_strings_vector(stdin);
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
