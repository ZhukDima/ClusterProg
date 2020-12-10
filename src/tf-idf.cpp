#include "tf-idf.h"

#include "math.h" // log

TFIDF::TFIDF(const std::vector<FileInfo>& vecFileInfo)
{
    for (auto &fi : vecFileInfo)
    {
        for (auto &p : fi.getAllMetric())
        {
            metricTF[fi.getPath()][p.first] = (double)p.second / fi.getAmountOfWords();
            metricIDF[p.first] += 1;
        }
    }
    for (auto &m : metricIDF)
    {
        m.second = std::log(vecFileInfo.size() / m.second);
    }
}

double TFIDF::calculate(const std::string &word, const std::string &path) const
{
    return metricTF.at(path).at(word) * metricIDF.at(word);
}

std::map<std::string, double> TFIDF::mapTFIDFforFile(const std::string &path) const
{
    std::map<std::string, double> resualt;
    for (auto &p : metricTF.at(path))
    {
        resualt[p.first] = calculate(p.first, path);
    }
    return resualt;
}