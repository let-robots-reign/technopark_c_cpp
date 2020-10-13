#include <gtest/gtest.h>

extern "C" {
#include "../src/string_functions.h"
}

TEST(StringFunctionsTest, test_length) {
    char *str = (char *) "test_string";
    EXPECT_EQ(strlen(str), 11); // the right length
    EXPECT_STREQ(str, "test_string"); // string shouldn't be changed

    char *empty_str = (char *) "";
    EXPECT_EQ(strlen(empty_str), 0);
    EXPECT_STREQ(empty_str, "");
}

TEST(StringFunctionsTest, test_copy) {
    char *lesser_string = (char *) "abcd";
    char wider_string[10];
    EXPECT_STREQ(strcpy(wider_string, lesser_string), "abcd");
    EXPECT_STREQ(lesser_string, "abcd"); // source shouldn't be changed after copy
    EXPECT_FALSE(strcpy(lesser_string, NULL));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
