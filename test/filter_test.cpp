#include <gtest/gtest.h>

extern "C" {
#include "../src/filter.h"
}

TEST(FilterTest, test_filter_condition) {
    EXPECT_TRUE(filter_condition("hello"));
    EXPECT_TRUE(filter_condition("11123"));
    EXPECT_TRUE(filter_condition("\t\r\n"));
    EXPECT_FALSE(filter_condition("   "));
    EXPECT_FALSE(filter_condition("\n"));
}


TEST(FilterTest, test_filter_vector) {
    const size_t SIZE = 5;
    const char *vector[SIZE] = {"abcd", "eeee", "ijjj", "mnoo", "qrst"};
    char **filtered = (char**) malloc(SIZE * sizeof(char*));
    const int count_filtered = filter_strings((const char **) vector, SIZE, filtered);
    ASSERT_EQ(count_filtered, 3);
    const char *right_filtered[3] = {"abcd", "mnoo", "qrst"};
    for (size_t i = 0; i < count_filtered; ++i) {
        EXPECT_STREQ(filtered[i], right_filtered[i]);
    }
}
