#ifndef TFIDF_H
#define TFIDF_H

#include "FileInfo.h"
#include <vector>

class TFIDF
{
private:
    std::map<std::string, int> pathToIndex;
    std::vector<FileInfo> TFMetrics;
    std::map<std::string, double> IDFMetrics;

public:
    TFIDF(const std::vector<FileInfo> &filesInfo);
    TFIDF(const TFIDF &) = delete;
    TFIDF &operator=(const TFIDF &) = delete;

    double calculate(const std::string &word, const std::string &path) const;
    FileInfo TFIDFForFile(const std::string &path) const;
};

#endif