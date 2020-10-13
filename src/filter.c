#include <stdlib.h>
#include "filter.h"
#include "string_functions.h"

bool filter_condition(const char *line) {
    /* searching for unique chars for each line
    *  we don't need to count all unique chars in the line
    *  just search for NEEDED_UNIQUES number of them */
    char unique[NEEDED_UNIQUES];
    for (size_t i = 0; i < NEEDED_UNIQUES; ++i) unique[i] = '\0';
    size_t count_unique = 0;
    for (size_t i = 0; i < strlen(line); ++i) {
        const char cur_symbol = line[i];
        bool if_unique = true;
        for (size_t j = 0; j < NEEDED_UNIQUES; ++j) {
            if (unique[j] == cur_symbol) {
                if_unique = false;
            }
        }
        if (if_unique) {
            unique[count_unique] = cur_symbol;
            ++count_unique;
        }
        if (count_unique == NEEDED_UNIQUES) {
            return true;
        }
    }

    return false;
}

int filter_strings(const char **strings_vector, size_t vector_size, char **filtered) {
    size_t filtered_line_index = 0;
    for (size_t i = 0; i < vector_size; ++i) {
        const char *cur_line = strings_vector[i];
        if (filter_condition(cur_line)) {
            // if the line satisfies the condition, add to filtered
            char *new_line = (char *) malloc(strlen(cur_line) + 1);
            if (!new_line) {
                // if unable to allocate memory, must clear memory from all the previous allocations
                for (size_t j = 0; j < filtered_line_index; ++j) {
                    free(filtered[j]);
                }
                return FILTER_FAILED;
            }
            filtered[filtered_line_index] = new_line;
            strcpy(filtered[filtered_line_index], cur_line);
            ++filtered_line_index;
        }
    }

    return filtered_line_index;
}
