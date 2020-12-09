#include <map>
#include <string>
#include "FileInfoImpl.h"
#include "FileReader.h"

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

std::string FileInfoImpl::getPath() {
    return pathToFile;
}

int FileInfoImpl::getAmountOfWords() {
    return amountOfWords;
}

const std::map<std::string, double>& FileInfoImpl::getAllMetric() {
    return metric;
}
