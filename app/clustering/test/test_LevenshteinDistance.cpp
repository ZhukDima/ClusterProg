#include <string>

#include "gtest/gtest.h"
#include "LevenshteinDistance.hpp"

TEST(Const, Calculate) {
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("", ""), 0);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("qwerty", "qwer"), 2);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("", "zxcvbnm"), 7);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("qwer_asdfg", "qwer_p"), 5);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("абвгд", "абвгд"), 0);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("QQasd", "asd"), 2);
    EXPECT_EQ(LevenshteinDistance<std::string>::calculate("AAvbnPP", "AAiopPP"), 3);
}

TEST(Generate, Calculate) {
    std::string str1;
    for (char i = 97; i <= 122; ++i) {
        str1 += i;
    }

    std::string str2;
    size_t j = 25;
    for (char i = 97; i <= 122; ++i) {
        str2 += i;
        EXPECT_EQ(LevenshteinDistance<std::string>::calculate(str1, str2), j);
        --j;
    }
}

