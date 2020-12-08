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
    EXPECT_NO_THROW(a.getNextWord());
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
    int cnt = 0;
    while (a.hasNextWord()) {
        std::string word;
        EXPECT_NO_THROW(word = a.getNextWord());
        if (word != "") ++cnt;
    }
    EXPECT_EQ(cnt, 69);
}
