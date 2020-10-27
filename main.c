/*
 * Вариант #65
 * В вашем распоряжении — массив из 10 млн. структур, содержащих числовой идентификатор записи (комментария)
 * в социальной сети, а также поля с семантикой средней оценки (целое 0 или вещественное от 1,0 до 5,0) и
 * числа поданных голосов (неотрицательное целое). Составьте наивный алгоритм подсчета количества записей,
 * не получивших ни единой оценки, а затем реализуйте параллельный алгоритм с использованием нескольких потоков
 * с учетом возможной реорганизации структуры и выравнивания ее элементов по линиям кэш-памяти.
*/

#include <stdio.h>
#include "read_comments.h"
#include "count_comments.h"

const char *input_file_name(int argc, const char *argv[]);

const char *get_error_message_for_code(int error_code);

int main(int argc, const char *argv[]) {
    const char *file_name = input_file_name(argc, argv);
    if (!file_name) {
        puts("Wrong number of arguments");
        return 1;
    }
    comment *comments = NULL;
    int read_status = read_comments_from_file(file_name, &comments);
    if (read_status < 0) {
        puts(get_error_message_for_code(read_status));
        return 1;
    }
    int count_status = count_zero_votes_comments(comments, read_status);
    if (count_status < 0) {
        puts(get_error_message_for_code(count_status));
        return 1;
    }
    printf("There are %d comments with 0 votes", count_status);
    free(comments);

    return 0;
}

const char *input_file_name(int argc, const char *argv[]) {
    const char *file_name = NULL;
    if (argc == 1) {
        file_name = "test_input_files/random_values.txt";
    } else if (argc == 2) {
        file_name = argv[1];
    }
    return file_name;
}

const char *get_error_message_for_code(int error_code) {
    switch (error_code) {
        case FILE_NOT_FOUND:
            return "File doesn't exist";
        case EMPTY_FILE:
            return "File is empty";
        case WRONG_FILE_FORMAT:
            return "Data is in wrong format";
        case WRONG_COUNT:
            return "Wrong number of parameters";
        case MALLOC_ERROR:
            return "Failed to allocate memory";
        case GRADE_INVALID:
            return "Value of grade is invalid";
        case ARRAY_IS_NULL:
            return "Array is NULL";
        case SECTION_ALLOC_ERROR:
            return "Failed to allocate memory for comments' section";
        case CREATE_THREAD_ERROR:
            return "Failed to create a thread";
        default:
            return "Unknown error";
    }
}