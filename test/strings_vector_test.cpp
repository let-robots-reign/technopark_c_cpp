#include <gtest/gtest.h>

extern "C" {
#include "../src/strings_vector.h"
}

TEST(StringsVectorTest, test_empty_strings) {
    StringsVector sv = empty_strings_vector();
    EXPECT_FALSE(sv.strings);
    EXPECT_EQ(sv.capacity, 0);
    EXPECT_EQ(sv.size, 0);
}

TEST(StringsVectorTest, test_print_vector) {
    const size_t SIZE = 3;
    char *vector[SIZE] = {"abcd", "hello", "111"};
    char *copy_vector[SIZE];
    memcpy(copy_vector, vector, sizeof(vector));
    print_vector(vector, SIZE);
    EXPECT_TRUE(vector);  // vector is still valid
    for (size_t i = 0; i < SIZE; ++i) {
        EXPECT_STREQ(vector[i], copy_vector[i]); // no string should be changed
    }
}

TEST(StringsVectorTest, test_free_vector) {
    const size_t SIZE = 3;
    const char *set[SIZE] = {"abcd", "hello", "111"};
    char **vector = (char**) malloc(SIZE * sizeof(char*));
    for (size_t i = 0; i < SIZE; ++i) {
        char *str = (char*) malloc(strlen(set[i]) + 1);
        vector[i] = str;
        strcpy(vector[i], set[i]);
    }
    free_vector(vector, SIZE);
    ASSERT_TRUE(vector); // vector is still valid
}

TEST(StringVectorTest, test_input_vector) {
    StringsVector sv = input_strings_vector(fopen("/home/travis/build/let-robots-reign/technopark_c_cpp/test/test_input.txt", "r"));
    EXPECT_TRUE(sv.strings);
    EXPECT_EQ(sv.capacity, 6);
    EXPECT_EQ(sv.size, 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
