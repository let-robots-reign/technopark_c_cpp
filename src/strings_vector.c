#include "strings_vector.h"


char *input_line(FILE *file) {
    const size_t CHUNK = 64;
    char *input = NULL;
    char buffer[CHUNK];
    size_t input_len = 0, temp_len = 0;
    do {
        if (fgets(buffer, CHUNK, file) == NULL) {
            return NULL;
        }
        temp_len = strlen(buffer);
        char *old_input = input; // save pointer in case realloc fails
        input = realloc(input, input_len + temp_len + 1);
        if (!input) {
            free(old_input);
            return NULL;
        }
        strcpy(input + input_len, buffer);
        input_len += temp_len;
    } while (temp_len == CHUNK - 1 && buffer[CHUNK - 2] != '\n');

    return input;
}

StringsVector input_strings_vector(FILE *file) {
    size_t size = INIT_SIZE;
    size_t capacity = 0;

    char **strings = (char **) malloc(size * sizeof(char *));
    if (!strings) {
        return empty_strings_vector();
    }

    char *line = input_line(file);
    size_t len;
    while (line != NULL && (len = strlen(line)) > 1) {
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

        line = input_line(file);
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
