#ifndef TFIDF_H
#define TFIDF_H

#include "FileInfo.h"
#include <vector>
#include <set>

class TFIDF
{
public:
    TFIDF(const std::vector<FileInfo> &filesInfo);
    TFIDF(const TFIDF &) = delete;
    TFIDF &operator=(const TFIDF &) = delete;

    int countUnicWords() const;
    std::set<std::string> setUnicWords() const;
    double calculate(const std::string &word, const std::string &path) const;
    FileInfo TFIDFForFile(const std::string &path) const;

private:
    std::map<std::string, int> pathToIndex;
    std::vector<FileInfo> TFMetrics;
    std::map<std::string, double> IDFMetrics;
};

#endif