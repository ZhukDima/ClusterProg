#include <string>
#include <filesystem>
#include <iostream>
#include "FileManager.h"

namespace fs = std::filesystem;

// PUBLIC

void FileManager::moveFile(std::string_view pathToSource, std::string pathToDestination)
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

void FileManager::createDir(std::string_view path)
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

const int FileManager::SAME_FILE_INDEX = 0;

std::string FileManager::getNewFilePathIfExists(std::string_view path, const int idx)
{
    std::string newPath = constructNewPath(path, idx);
    if (fs::exists(newPath))
    {
        return getNewFilePathIfExists(path, idx + 1);
    }
    return newPath;
}

std::string FileManager::constructNewPath(std::string_view path, const int idx)
{
    fs::path oldPath(path);
    fs::path newPath = oldPath.parent_path() / ( fs::path( oldPath.stem().string() + (idx == FileManager::SAME_FILE_INDEX ? "" : "_" + std::to_string(idx)) + oldPath.extension().string() ) );
    return newPath.string();
}