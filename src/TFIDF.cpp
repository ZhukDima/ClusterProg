#include "TFIDF.h"
#include <math.h> // log

TFIDF::TFIDF(const std::vector<FileInfo> &vecFileInfo)
{
    for (auto fi = vecFileInfo.begin(); fi != vecFileInfo.end(); ++fi)
    {
        for (auto p = fi->getAllMetric().begin(); p != fi->getAllMetric().end(); ++p)
        {
            metricTF[fi->getPath()][p->first] = (double)p->second / fi->getAmountOfWords();
            metricIDF[p->first] += 1;
        }
    }
    for (auto m = metricIDF.begin(); m != metricIDF.end(); ++m)
    {
        m->second = std::log(vecFileInfo.size() / m->second);
    }
}

double TFIDF::calculate(const std::string &word, const std::string &path) const
{
    try
    {
        return metricTF.at(path).at(word) * metricIDF.at(word);
    }
    catch(const std::out_of_range& e)
    {
        return 0;
    }
}

std::map<std::string, double> TFIDF::mapTFIDFforFile(const std::string &path) const
{
    std::map<std::string, double> resualt;
    for (auto p = metricTF.at(path).begin(); p != metricTF.at(path).end(); ++p)
    {
        resualt[p->first] = calculate(p->first, path);
    }
    return resualt;
}