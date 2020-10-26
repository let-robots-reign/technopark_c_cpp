#ifndef TECHNOPARK_C_CPP_READ_COMMENTS_H
#define TECHNOPARK_C_CPP_READ_COMMENTS_H

#include <stdio.h>
#include <stdbool.h>
#include "comment_struct.h"

bool valid_grade(double grade);

int read_comments_count(FILE *infile);

int read_id(FILE *infile, size_t *id);

int read_grade(FILE *infile, double *grade);

int read_votes(FILE *infile, unsigned int *votes);

int read_comments_from_file(const char *infile, comment **comments);

void abort_read(FILE *file, comment *array);

#endif //TECHNOPARK_C_CPP_READ_COMMENTS_H
