#ifndef TFIDF_H
#define TFIDF_H

#include "FileInfo.h"
#include <vector>
#include <set>
#include <map>

class TFIDF
{
public:
    TFIDF(const std::vector<FileInfo> &filesInfo);
    TFIDF(const TFIDF &) = delete;
    TFIDF &operator=(const TFIDF &) = delete;

    int countUnicWords() const;
    std::set<std::string> getSetUnicWords() const;
    double calculateTFIDFMetric(const std::string &word, const std::string &path) const;
    size_t getNumberFilesWithWord(const std::string &word) const;
    FileInfo TFIDFForFile(const std::string &path) const;

protected:
    std::vector<FileInfo> countWordInFiles;
    std::map<std::string, size_t> countFilesWithWord;
    std::set<std::string> setUnicWords;
    std::map<std::string, size_t> pathToIndex;
    std::vector<FileInfo> TFMetrics;
    std::map<std::string, double> IDFMetrics;
};

#endif
