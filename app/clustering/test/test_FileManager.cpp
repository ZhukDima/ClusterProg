#include "gtest/gtest.h"
#include "FileManager.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

TEST(createDir, correctDir)
{
    std::string newDir = "newDir";
    FileManager::createDir(newDir);
    fs::path newDirPath = fs::current_path() / newDir;
    std::cout << newDirPath;
    EXPECT_TRUE(fs::exists(newDirPath));
}

TEST(createDir, deepDir)
{
    std::string newDir = "newDir/a/b/c/";
    FileManager::createDir(newDir);
    fs::path newDirPath = fs::current_path() / newDir;
    EXPECT_TRUE(fs::exists(newDirPath));
}

TEST(createDir, systemDir)
{
    std::string errorDirPath = "/test";
    EXPECT_THROW(FileManager::createDir(errorDirPath), std::runtime_error);
    try
    {
        FileManager::createDir(errorDirPath);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

TEST(moveFile, correctPath)
{
    std::string baseFileName = "test";
    const int fileCount = 3;
    for (size_t i = 0; i < fileCount; i++)
    {
        std::string filePathStr = baseFileName + std::to_string(i) + ".txt";
        std::string fileDistinationPathStr = "newDir/" + filePathStr;
        std::fstream fileDescriptor;
        fileDescriptor.open(filePathStr, std::ios_base::out);
        fileDescriptor.close();
        FileManager::moveFile(filePathStr, fileDistinationPathStr);
        fs::path filePath(fileDistinationPathStr);
        EXPECT_TRUE(fs::exists(filePath));
    }
}

TEST(moveFile, notExistingFile)
{
    std::string notExistingFileName = "notExist.txt";
    std::string notExistingFileDistination = "newDir/" + notExistingFileName;
    EXPECT_THROW(FileManager::moveFile(notExistingFileName, notExistingFileDistination), fs::filesystem_error);
    try
    {
        FileManager::moveFile(notExistingFileName, notExistingFileDistination);
    }
    catch(const fs::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

TEST(moveFile, systemDirectory)
{
    std::string fileName = "test0.txt";
    std::string systemPath = "/" + fileName;
    EXPECT_THROW(FileManager::moveFile(fileName, systemPath), fs::filesystem_error);
    try
    {
        FileManager::moveFile(fileName, systemPath);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

TEST(moveFile, sameFileName)
{
    std::string firstFile = "newDir/test0.txt";
    std::string secondFile = "newDir/a/test0.txt";
    std::string firstFileDestination = secondFile;
    std::fstream secondFileDescriptor;
    secondFileDescriptor.open(secondFile, std::ios_base::out);
    secondFileDescriptor.close();
    FileManager::moveFile(firstFile, firstFileDestination);
    fs::path secondFilePath(secondFile);
    std::string newFirstFileName = secondFilePath.stem().string() + "_1" + secondFilePath.extension().string();
    fs::path firstFileDestinationPath = secondFilePath.parent_path() / newFirstFileName;
    std::cout << firstFileDestinationPath;
    EXPECT_TRUE(fs::exists(firstFileDestinationPath));
    EXPECT_TRUE(fs::exists(secondFilePath));
}