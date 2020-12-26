#include <fstream>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "FileReader.h"

TEST(constructor, failed) {
    EXPECT_THROW(FileReader("vabalabadabdab.txt"), const char*);
    try {
        FileReader a("vabalabadabdab.txt");
    } catch (const char* err) {
        std::string eq = "Unable to read file";
        EXPECT_EQ(eq.compare(err), 0);
    }
}
TEST(constructor, correct_creation) {
    EXPECT_NO_THROW(FileReader("../test.txt"));
}
TEST(hasNextWord, return_true) {
    FileReader a("../test.txt");
    EXPECT_EQ(a.hasNextWord(), true);
}
TEST(hasNextWord, return_false) {
    FileReader a("../empty.txt");
    EXPECT_NO_THROW(a.getNextWord());
    EXPECT_EQ(a.hasNextWord(), false);
}
TEST(getNextWord, read_empty_file) {
    FileReader a("../empty.txt");
    std::wstring answ;
    EXPECT_NO_THROW(answ = a.getNextWord());
    EXPECT_EQ(answ.empty(), true);
    EXPECT_THROW(a.getNextWord(), const char*);
    try {
        a.getNextWord();
    } catch (const char* err) {
        std::string eq = "Unable to read next word";
        EXPECT_EQ(eq.compare(err), 0);
    }
}
TEST(getNextWord, read_lorem) {
    FileReader a("../test.txt");
    std::wstring lorem = L"lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum ";
    int cnt = 0;
    std::wstring answ = L"";
    while (a.hasNextWord()) {
        std::wstring word;
        EXPECT_NO_THROW(word = a.getNextWord());
        if (!word.empty()) {
            ++cnt;
            answ += word + L" ";
        }
    }
    EXPECT_EQ(cnt, 69);
    EXPECT_EQ(lorem, answ);
}