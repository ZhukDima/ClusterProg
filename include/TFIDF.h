#ifndef TFIDF_H
#define TFIDF_H

#include "FileInfo.h"
#include <vector>

class TFIDF
{
private:
    std::map<std::string, std::map<std::string, double>> metricTF; // map<path, map<word, metric>>
    std::map<std::string, double> metricIDF;                       // map<word, metric>

public:
    TFIDF() = delete;
    TFIDF(const TFIDF &obj) = delete;
    TFIDF &operator=(const TFIDF &obj) = delete;

    TFIDF(const std::vector<FileInfo> &vecFileInfo);
    double calculate(const std::string &word, const std::string &path) const;
    std::map<std::string, double> mapTFIDFforFile(const std::string &path) const;
};

#endif
