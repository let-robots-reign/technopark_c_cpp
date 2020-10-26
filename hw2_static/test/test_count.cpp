#include "gtest/gtest.h"

extern "C" {
#include "count_comments.h"
}

TEST(CountComments, count_in_correct_random_array) {
    const size_t array_size = 5;
    const comment comments[array_size] = {
            {0, 1.7, 20},
            {1, 3.8,   17},
            {2, 0,   0},
            {3, 2.3, 4},
            {4, 0,   0}
    };
    const size_t zero_votes_comments = 2;
    EXPECT_EQ(count_zero_votes_comments(comments, array_size), zero_votes_comments);
}

TEST(CountComments, count_all_zeroes) {
    const size_t array_size = 4;
    const comment comments[array_size] = {
            {0, 0, 0},
            {1, 0, 0},
            {2, 0, 0},
            {3, 0, 0}
    };
    EXPECT_EQ(count_zero_votes_comments(comments, array_size), array_size);
}

TEST(CountComments, count_none_zeroes) {
    const size_t array_size = 4;
    const comment comments[array_size] = {
            {0, 4.1, 3},
            {1, 2.8, 12},
            {2, 4.9, 37},
            {3, 3.4, 73}
    };
    EXPECT_EQ(count_zero_votes_comments(comments, array_size), 0);
}
