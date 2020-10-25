#include "read_comments.h"

bool valid_grade(double grade) {
    // Из условия: целое 0 или вещественное от 1,0 до 5,0
    double eps = 10e3;
    return grade == 0 || (grade - 1) >= eps && (grade - 5) <= eps;
}

int read_comments_count(FILE *infile) {
    int comments_count = 0;
    int args_read = fscanf(infile, "%d", &comments_count);
    if (args_read == EOF) {
        return EMPTY_FILE;
    }
    // ожидаем одно число - число структур
    if (args_read != 1) {
        return WRONG_FILE_FORMAT;
    }
    if (comments_count < 0) {
        return WRONG_COUNT;
    }
    return comments_count;
}

int read_id(FILE *infile, size_t *id) {
    int args_read = fscanf(infile, "%zu", id);
    if (args_read == EOF) {
        return EMPTY_FILE;
    }
    if (args_read != 1) {
        return WRONG_FILE_FORMAT;
    }
    return SUCCESS;
}

int read_grade(FILE *infile, double *grade) {
    int args_read = fscanf(infile, "%lf", grade);
    if (args_read == EOF) {
        return EMPTY_FILE;
    }
    if (args_read != 1) {
        return WRONG_FILE_FORMAT;
    }
    if (!valid_grade(*grade)) {
        return GRADE_INVALID;
    }
    return SUCCESS;
}

int read_votes(FILE *infile, unsigned int *votes) {
    long long tmp_votes = 0;
    int args_read = fscanf(infile, "%lld", &tmp_votes);
    if (args_read == EOF) {
        return EMPTY_FILE;
    }
    if (args_read != 1) {
        return WRONG_FILE_FORMAT;
    }
    if (tmp_votes < 0) {
        return WRONG_FILE_FORMAT;
    }
    *votes = (unsigned int) tmp_votes;
    return SUCCESS;
}

int read_comments_from_file(const char *infile, comment **comments) {
    FILE *file = fopen(infile, "r");
    if (!file) {
        return FILE_NOT_FOUND;
    }

    int comments_count = read_comments_count(file);
    if (comments_count < 0) {
        fclose(file);
        return comments_count;
    }

    comment *array = (comment *) malloc(sizeof(comment) * comments_count);
    if (!array) {
        fclose(file);
        return MALLOC_ERROR;
    }
    *comments = array;

    size_t id = 0;
    double avg_grade = 0;
    unsigned int votes_count = 0;
    for (int i = 0; i < comments_count; ++i) {
        int ret_code;
        if ((ret_code = read_id(file, &id)) < 0) return ret_code;
        if ((ret_code = read_grade(file, &avg_grade)) < 0) return ret_code;
        if ((ret_code = read_votes(file, &votes_count)) < 0) return ret_code;

        comment cmnt = {id, avg_grade, votes_count};
        (*comments)[i] = cmnt;
    }

    fclose(file);
    return comments_count;
}