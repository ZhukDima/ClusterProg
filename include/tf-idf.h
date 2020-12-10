#include "fileinfo.h"
#include "vector"

class TFIDF
{
private:
    std::map<std::string, std::map<std::string, double>> metricTF; // map<path, map<word, metric>>
    std::map<std::string, double> metricIDF;                       // map<word, metric>

public:
    TFIDF(const std::vector<FileInfo> &vecFileInfo);
    double calculate(const std::string &word, const std::string &path) const;
    std::map<std::string, double> mapTFIDFforFile(const std::string &path) const;
};