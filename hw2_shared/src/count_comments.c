#include "count_comments.h"
#include <pthread.h>
#include <unistd.h>

typedef struct comments_section {
    comment *comments;
    size_t section_size;
    size_t zeroes_count_for_section;
} comments_section;


void *start_count(void *arg) {
    comments_section *section = (comments_section *) arg;
    for (size_t i = 0; i < section->section_size; ++i) {
        if (section->comments[i].votes_count == 0) {
            ++section->zeroes_count_for_section;
        }
    }

    pthread_exit(0);
}

comments_section *create_sections_for_threads(comment *comments, size_t array_size,
                                              size_t threads_number, size_t section_size) {
    comments_section *sections = (comments_section *) malloc(threads_number * sizeof(struct comments_section));
    if (!sections) {
        return NULL;
    }

    for (size_t i = 0; i < threads_number; ++i) {
        sections[i].comments = comments;
        sections[i].section_size = section_size;
        sections[i].zeroes_count_for_section = 0;
        comments += section_size;
    }
    sections[threads_number - 1].section_size += array_size - section_size * threads_number;

    return sections;
}

int count_zero_votes_comments(comment *comments, size_t size) {
    if (!comments) {
        return ARRAY_IS_NULL;
    }

    size_t threads_number = sysconf(_SC_NPROCESSORS_ONLN);

    pthread_t threads_array[threads_number];
    size_t section_size = size / threads_number;

    comments_section *sections = create_sections_for_threads(comments, size, threads_number, section_size);
    if (!sections) {
        return SECTION_ALLOC_ERROR;
    }

    for (size_t i = 0; i < threads_number; ++i) {
        int error_code = pthread_create(&threads_array[i], NULL, start_count, &sections[i]);
        if (error_code != 0) {
            return CREATE_THREAD_ERROR;
        }
    }

    size_t total_zeroes = 0;
    for (size_t i = 0; i < threads_number; ++i) {
        pthread_join(threads_array[i], NULL);
        total_zeroes += sections[i].zeroes_count_for_section;
    }

    free(sections);
    return total_zeroes;
}

int print_and_write_result_to_file(int result) {
    printf("Shared library: there are %d comments with 0 votes", result);
    FILE *file = fopen("result_shared.txt", "w");
    if (!file) {
        return FILE_NOT_FOUND;
    }
    fprintf(file, "%d", result);
    fclose(file);
    return SUCCESS;
}