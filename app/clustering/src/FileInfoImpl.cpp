#include <map>
#include <string>
#include "FileInfoImpl.h"
#include "FileReader.h"
#include "LevenshteinDistance.hpp"

FileInfoImpl::FileInfoImpl() : pathToFile(""), amountOfWords(0) {}

FileInfoImpl::FileInfoImpl(std::string _pathToFile, const std::map<std::wstring, double> &_metric) : pathToFile(
        _pathToFile) {
    metric = _metric;
    FileReader file(pathToFile);
    while (file.hasNextWord()) {
        std::wstring word = file.getNextWord();
        if (!word.empty()) {
            ++amountOfWords;
        }
    }
}

FileInfoImpl::FileInfoImpl(const FileInfoImpl &obj) {
    swap(obj);
}

void FileInfoImpl::swap(const FileInfoImpl &obj) noexcept {
    pathToFile = obj.getPath();
    amountOfWords = obj.getAmountOfWords();
    metric = obj.getAllMetric();
}

FileInfoImpl &FileInfoImpl::operator=(const FileInfoImpl &obj) {
    if (this == &obj) {
        return *this;
    }
    FileInfoImpl tmp(obj);
    swap(tmp);
    return *this;
}

FileInfoImpl::FileInfoImpl(std::string _pathToFile) : pathToFile(_pathToFile) {
    FileReader file(pathToFile);
    while (file.hasNextWord()) {
        std::wstring word = file.getNextWord();
        bool updated = false;
        if (!word.empty()) {
            for (const auto&[key, value] : metric) {
                size_t temp = LevenshteinDistance<std::wstring>::calculate(word, key);
                if (temp <= MaxLevenshteinDistance &&
                    std::max(word.size(), key.size()) * coefOfLength >= static_cast<double>(temp)) {
                    ++metric[key];
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                metric[word]++;
            }
            ++amountOfWords;
        }
    }
}

std::string FileInfoImpl::getPath() const {
    return pathToFile;
}

int FileInfoImpl::getAmountOfWords() const {
    return amountOfWords;
}

const std::map<std::wstring, double> &FileInfoImpl::getAllMetric() const {
    return metric;
}

void FileInfoImpl::setMetric(std::wstring key, double value) {
    metric[key] = value;
}