#include <map>
#include <string>
#include "FileInfo.h"
#include "FileInfoImpl.h"

FileInfo::FileInfo(std::string _pathToFile): impl(new FileInfoImpl(_pathToFile)) {}

FileInfo::FileInfo(std::string _pathToFile, const std::map<std::string, double>& _metric):
    impl(new FileInfoImpl(_pathToFile, _metric)) {}

std::string FileInfo::getPath() {
    return impl->getPath();
}

int FileInfo::getAmountOfWords() {
    return impl->getAmountOfWords();
}

const std::map<std::string, double>& FileInfo::getAllMetric() {
    return impl->getAllMetric();
}

FileInfo::~FileInfo() {
    delete impl;
}
