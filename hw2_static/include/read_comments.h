#ifndef TECHNOPARK_C_CPP_READ_COMMENTS_H
#define TECHNOPARK_C_CPP_READ_COMMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define FILE_NOT_FOUND -1
#define EMPTY_FILE -2
#define WRONG_FILE_FORMAT -3
#define WRONG_COUNT -4
#define MALLOC_ERROR -5
#define GRADE_INVALID -6

typedef struct comment {
    size_t id;
    double avg_grade;
    unsigned int votes_count;
} comment;

bool valid_grade(double grade);

int read_comments_count(FILE *infile);

int read_id(FILE *infile, size_t *id);

int read_grade(FILE *infile, double *grade);

int read_votes(FILE *infile, unsigned int *votes);

int read_comments_from_file(const char *infile, comment **comments);

#endif //TECHNOPARK_C_CPP_READ_COMMENTS_H
