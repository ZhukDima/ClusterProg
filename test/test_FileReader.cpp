#include <fstream>
#include <string>
#include "gtest/gtest.h"
#include "FileReader.h"

TEST(constructor, failed) {
    EXPECT_THROW(FileReader("vabalabadabdab.txt"), char*);
}
