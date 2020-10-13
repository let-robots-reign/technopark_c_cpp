#ifndef TECHNOPARK_C_CPP_STRINGS_VECTOR_H
#define TECHNOPARK_C_CPP_STRINGS_VECTOR_H

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

StringsVector input_strings_vector(FILE *file);

StringsVector empty_strings_vector();

void print_vector(char **strings, size_t size);

void free_vector(char **strings, size_t size);

#endif //TECHNOPARK_C_CPP_STRINGS_VECTOR_H
