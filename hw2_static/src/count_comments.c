#include "count_comments.h"

int count_zero_votes_comments(comment *comments, size_t size) {
    if (!comments) {
        return ARRAY_IS_NULL;
    }
    size_t count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (!comments[i].votes_count) {
            ++count;
        }
    }

    return count;
}

int print_and_write_result_to_file(int result) {
    printf("Static library: there are %d comments with 0 votes", result);
    FILE *file = fopen("result_static.txt", "w");
    if (!file) {
        return FILE_NOT_FOUND;
    }
    fprintf(file, "%d", result);
    fclose(file);
    return SUCCESS;
}