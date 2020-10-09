#ifndef TECHNOPARK_C_CPP_FILTER_H
#define TECHNOPARK_C_CPP_FILTER_H

#define NEEDED_UNIQUES 3

typedef enum {
    false,
    true
} bool;

bool filter_condition(const char *line);
size_t filter_strings(const char **strings_vector, int vector_size, char **filtered);

#endif //TECHNOPARK_C_CPP_FILTER_H
