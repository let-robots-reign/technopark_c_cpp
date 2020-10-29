#include <iostream>
#include <fstream>
#include <chrono>

extern "C" {
#include "read_comments.h"
#include "count_comments.h"
}

int main() {
    const char *file_name = "stress_test.txt";
    comment *comments = nullptr;
    int comments_count = read_comments_from_file(file_name, &comments);

    size_t total_time = 0;
    const size_t TRIES = 10;
    for (size_t i = 0; i < TRIES; ++i) {
        auto start = std::chrono::steady_clock::now();
        count_zero_votes_comments(comments, comments_count);
        auto finish = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        total_time += elapsed.count();
    }

    std::cout << total_time / TRIES << std::endl;
    return 0;
}
