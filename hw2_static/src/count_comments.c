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