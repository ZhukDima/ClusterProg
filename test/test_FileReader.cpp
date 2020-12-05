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
