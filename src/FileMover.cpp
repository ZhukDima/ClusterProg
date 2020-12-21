#include <string>
#include <filesystem>
#include <iostream>
#include "FileMover.h"

namespace fs = std::filesystem;

// PUBLIC

void FileMover::moveFile(const std::string& pathToSource, std::string pathToDestination)
{
    try
    {
        pathToDestination = getNewFilePathIfExists(pathToDestination);
        fs::rename(pathToSource, pathToDestination);
    }
    catch(const fs::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileMover::createDir(const std::string& path)
{
    try
    {
        fs::create_directories(path);
    }
    catch(const fs::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// PRIVATE

const int FileMover::SAME_FILE_INDEX = 0;

std::string FileMover::getNewFilePathIfExists(std::string path, int idx)
{
    std::string newPath = constructNewPath(path, idx);
    if (fs::exists(newPath))
    {
        return getNewFilePathIfExists(path, idx + 1);
    }
    return newPath;
}

std::string FileMover::constructNewPath(std::string path, int idx)
{
    fs::path oldPath(path);
    fs::path newPath = oldPath.parent_path() / ( fs::path( oldPath.stem().string() + (idx == FileMover::SAME_FILE_INDEX ? "" : "_" + std::to_string(idx)) + oldPath.extension().string() ) );
    return newPath.string();
}