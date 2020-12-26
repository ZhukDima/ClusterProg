#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include <map>
#include "FileInfo.h"
#include "FileInfoImpl.h"

TEST(constructor, incorrect_path) {
    EXPECT_THROW(FileInfo("vabalabadabdab.txt"), const char*);
    try {
        FileInfo a("vabalabadabdab.txt");
    } catch (const char* err) {
        std::string eq = "Unable to read file";
        EXPECT_EQ(eq.compare(err), 0);
    }
}
TEST(constructor_with_string, correct_creation) {
    EXPECT_NO_THROW(FileInfo("../test.txt"));
}

TEST(constructor_with_string_map, correct_creation) {
    std::map<std::wstring, double> metric, answ;
    metric[L"gg"] = 2;
    metric[L"wp"] = 3;
    FileInfo obj;
    EXPECT_NO_THROW(obj = FileInfo("../test.txt", metric));
    answ = obj.getAllMetric();
    EXPECT_EQ(answ[L"gg"], metric[L"gg"]);
    EXPECT_EQ(answ[L"wp"], metric[L"wp"]);
}
TEST(constructor_with_string_map, incorrect_path) {
    std::map<std::wstring, double> metric;
    metric[L"gg"] = 2;
    metric[L"wp"] = 3;
    EXPECT_THROW(FileInfo("vabalabadabdab.txt", metric), const char*);
    try {
        FileInfo a("vabalabadabdab.txt", metric);
    } catch (const char* err) {
        std::string eq = "Unable to read file";
        EXPECT_EQ(eq.compare(err), 0);
    }
}
TEST(copy_constructor, correct_copy) {
    FileInfo a("../test.txt");
    FileInfo b(a);
    EXPECT_EQ(a.getPath(), b.getPath());
    EXPECT_EQ(a.getAmountOfWords(), b.getAmountOfWords());
    EXPECT_EQ(a.getAllMetric(), b.getAllMetric());
}
TEST(operator_assignment, correct_copy) {
    FileInfo a("../test.txt");
    FileInfo b;
    b = a;
    EXPECT_EQ(a.getPath(), b.getPath());
    EXPECT_EQ(a.getAmountOfWords(), b.getAmountOfWords());
    EXPECT_EQ(a.getAllMetric(), b.getAllMetric());
}
TEST(get_path, test_txt) {
    FileInfo a("../test.txt");
    EXPECT_EQ(a.getPath(), "../test.txt");
}
TEST(getAmountOfWords, cnt_words_in_lorem) {
    FileInfo a("../test.txt");
    EXPECT_EQ(a.getAmountOfWords(), 69);
}
TEST(getAllMetric, lorem) {
    std::map<std::wstring, double> metric;
    std::wstring word = L"", lorem = L"lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum ";
    for (auto c : lorem) {
        if (c == L' ') {
            if (!word.empty() && word != L" ") {
                metric[word]++;
            }
            word = L"";
        } else {
            word += c;
        }
    }
    FileInfo a("../test.txt");
    EXPECT_EQ(a.getAllMetric(), metric);
}
TEST(getImpl, FileInfoImpl) {
    FileInfo a("../test.txt");
    std::string path = "../test.txt";
    int amountOfWords = 69;
    std::map<std::wstring, double> metric;
    std::wstring word = L"", lorem = L"lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum ";
    for (auto c : lorem) {
        if (c == ' ') {
            if (!word.empty() && word != L" ") {
                metric[word]++;
            }
            word = L"";
        } else {
            word += c;
        }
    }
    FileInfoImpl impl = a.getImpl();
    EXPECT_EQ(impl.getPath(), path);
    EXPECT_EQ(impl.getAmountOfWords(), amountOfWords);
    EXPECT_EQ(impl.getAllMetric(), metric);
}
