#include "strings_vector.h"

StringsVector input_strings_vector(FILE *file) {
    size_t size = INIT_SIZE;
    size_t capacity = 0;
    char line[LINE_LENGTH];
    size_t len;

    char **strings = (char **) malloc(size * sizeof(char *));
    if (!strings) {
        return empty_strings_vector();
    }

    while (fgets(line, LINE_LENGTH, file) != NULL && (len = strlen(line)) > 1) {
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
