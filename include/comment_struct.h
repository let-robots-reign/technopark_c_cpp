#ifndef TECHNOPARK_C_CPP_COMMENT_STRUCT_H
#define TECHNOPARK_C_CPP_COMMENT_STRUCT_H

#include <stdlib.h>

#define DEFAULT_OUT_STREAM stdout

#define SUCCESS 0
#define FILE_NOT_FOUND -1
#define EMPTY_FILE -2
#define WRONG_FILE_FORMAT -3
#define WRONG_COUNT -4
#define MALLOC_ERROR -5
#define GRADE_INVALID -6

#define ARRAY_IS_NULL -7

#define SECTION_ALLOC_ERROR -8
#define CREATE_THREAD_ERROR -9

typedef struct comment {
    size_t id;
    double avg_grade;
    unsigned int votes_count;
} comment;

#endif //TECHNOPARK_C_CPP_COMMENT_STRUCT_H
