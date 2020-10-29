#include "gtest/gtest.h"
#include <fstream>
#include <string>

TEST(CompareTwoLibraries, compare_received_results) {
    std::ifstream static_result_file("result_static.txt");
    std::ifstream shared_result_file("result_shared.txt");
    if (static_result_file && shared_result_file) {
        std::string static_res, shared_res;
        static_result_file >> static_res;
        shared_result_file >> shared_res;
        EXPECT_EQ(static_res, shared_res);
    }
}
