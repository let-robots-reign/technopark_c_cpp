#include "gtest/gtest.h"

extern "C" {
#include "read_comments.h"
}

TEST(ReadFromFile, read_random_values) {
    const char *infile = "../test_input_files/random_values.txt";
    comment *comments = nullptr;
    const size_t correct_size = 5;
    const comment correct_comments[correct_size] = {
            {0, 1.7, 20},
            {1, 3.8,   17},
            {2, 0,   0},
            {3, 2.3, 4},
            {4, 0,   0}
    };
    const size_t size = read_comments_from_file(infile, &comments);
    EXPECT_EQ(size, correct_size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(comments[i].id, correct_comments[i].id);
        EXPECT_EQ(comments[i].avg_grade, correct_comments[i].avg_grade);
        EXPECT_EQ(comments[i].votes_count, correct_comments[i].votes_count);
    }
    free(comments);
}

TEST(ReadFromFile, test_file_not_found) {
    const char *infile = "../test_input_files/non_existent.txt";
    comment *comments = nullptr;
    EXPECT_EQ(read_comments_from_file(infile, &comments), FILE_NOT_FOUND);
    EXPECT_EQ(comments, nullptr);
}

TEST(ReadFromFile, test_empty_file) {
    const char *infile = "../test_input_files/empty_file.txt";
    comment *comments = nullptr;
    EXPECT_EQ(read_comments_from_file(infile, &comments), EMPTY_FILE);
    EXPECT_EQ(comments, nullptr);
}

TEST(ReadFromFile, test_negative_count) {
    const char *infile_negative_count = "../test_input_files/negative_comments_count.txt";
    comment *comments = nullptr;
    EXPECT_EQ(read_comments_from_file(infile_negative_count, &comments), WRONG_COUNT);
    EXPECT_EQ(comments, nullptr);
}

TEST(ReadFromFile, test_wrong_data_format) {
    comment *comments = nullptr;

    const char *infile_invalid_id = "../test_input_files/wrong_id_format.txt";
    EXPECT_EQ(read_comments_from_file(infile_invalid_id, &comments), WRONG_FILE_FORMAT);
    EXPECT_EQ(comments, nullptr);

    const char *infile_invalid_votes = "../test_input_files/wrong_votes_format.txt";
    EXPECT_EQ(read_comments_from_file(infile_invalid_votes, &comments), WRONG_FILE_FORMAT);
    EXPECT_EQ(comments, nullptr);
}

TEST(ReadFromFile, test_eofs) {
    const char *infile_id_eof = "../test_input_files/id_eof.txt";
    comment *comments = nullptr;
    EXPECT_EQ(read_comments_from_file(infile_id_eof, &comments), EMPTY_FILE);
    EXPECT_EQ(comments, nullptr);

    const char *infile_grade_eof = "../test_input_files/grade_eof.txt";
    EXPECT_EQ(read_comments_from_file(infile_grade_eof, &comments), EMPTY_FILE);
    EXPECT_EQ(comments, nullptr);

    const char *infile_votes_eof = "../test_input_files/votes_eof.txt";
    EXPECT_EQ(read_comments_from_file(infile_votes_eof, &comments), EMPTY_FILE);
    EXPECT_EQ(comments, nullptr);
}

TEST(ReadFromFile, test_invalid_grade) {
    comment *comments = nullptr;

    const char *infile_invalid_grade = "../test_input_files/invalid_grade.txt";
    EXPECT_EQ(read_comments_from_file(infile_invalid_grade, &comments), GRADE_INVALID);
    EXPECT_EQ(comments, nullptr);
}
