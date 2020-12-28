#include <string>
#include <filesystem>
#include <iostream>
#include "FileManager.h"

using namespace std::filesystem;

// PUBLIC

void FileManager::moveFile(std::string_view pathToSource, std::string pathToDestination) {
    try {
        pathToDestination = getNewFilePathIfExists(pathToDestination);
        rename(pathToSource, pathToDestination);
    }
    catch (const filesystem_error &e) {
        throw e;
    }
}

void FileManager::createDir(std::string_view path) {
    if (!create_directories(path) && !exists(path)) {
        throw std::runtime_error("Can't create directory on this path");
    }
}

// PRIVATE

const int FileManager::SAME_FILE_INDEX = 0;

std::string FileManager::getNewFilePathIfExists(std::string_view path, const int idx) {
    std::string newPath = constructNewPath(path, idx);
    if (exists(newPath)) {
        return getNewFilePathIfExists(path, idx + 1);
    }
    return newPath;
}

std::string FileManager::constructNewPath(std::string_view _path, const int idx) {
    path oldPath(_path);
    path newPath = oldPath.parent_path() / (path(oldPath.stem().string() +
                        (idx == FileManager::SAME_FILE_INDEX ? "" : "_" + std::to_string(idx)) +
                        oldPath.extension().string()));
    return newPath.string();
}
