#ifndef TECHNOPARK_C_CPP_FILTER_H
#define TECHNOPARK_C_CPP_FILTER_H

#define NEEDED_UNIQUES 3
#define FILTER_FAILED -1

#include <stdbool.h>
#include <stddef.h>

bool filter_condition(const char *line);

int filter_strings(const char **strings_vector, size_t vector_size,
                   char **filtered);

#endif  // TECHNOPARK_C_CPP_FILTER_H
