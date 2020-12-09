#include <map>
#include <string>
#include "FileInfoImpl.h"
#include "FileReader.h"

FileInfoImpl::FileInfoImpl(): pathToFile(""), amountOfWords(0) {}

FileInfoImpl::FileInfoImpl(std::string _pathToFile, const std::map<std::string, double>& _metric): pathToFile(_pathToFile) {
    for (auto i : _metric) {
        metric[i.first] = i.second;
    }
    FileReader file(pathToFile);
    while (file.hasNextWord()) {
        std::string word = file.getNextWord();
        if (word != "") {
            ++amountOfWords;
        }
    }
}

FileInfoImpl::FileInfoImpl(const FileInfoImpl& obj) {
    amountOfWords = obj.getAmountOfWords();
    pathToFile = obj.getPath();
    for (auto i : obj.getAllMetric()) {
        metric[i.first] = i.second;
    }
}

FileInfoImpl& FileInfoImpl::operator=(const FileInfoImpl& obj) {
    if (this == &obj) {
        return *this;
    }
    amountOfWords = obj.getAmountOfWords();
    pathToFile = obj.getPath();
    for (auto i : obj.getAllMetric()) {
        metric[i.first] = i.second;
    }
    return *this;
}

FileInfoImpl::FileInfoImpl(std::string _pathToFile): pathToFile(_pathToFile) {
    FileReader file(pathToFile);
    while (file.hasNextWord()) {
        std::string word = file.getNextWord();
        if (word != "") {
            metric[word]++;
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

const std::map<std::string, double>& FileInfoImpl::getAllMetric() const {
    return metric;
}

void FileInfoImpl::setMetric(std::string key, double value) {
    metric[key] = value;
}
