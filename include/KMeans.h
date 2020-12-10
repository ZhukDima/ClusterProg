#ifndef KMEANS_H
#define KMEANS_H

#include "TFIDF.h"
#include <set>

class KMeans
{
private:
    std::vector<FileInfo> vecFileInfo;
    std::vector<std::map<std::string, double>> centroids;

    double deltaBetweenTFIDF(const std::map<std::string, double> &m1, const std::map<std::string, double> &m2) const;
    bool equalCentroid(const std::map<std::string, double> &l, const std::map<std::string, double> &r) const;
    bool equalCentroidsWithBase(const std::vector<std::map<std::string, double>> &newCentroids) const;

public:
    KMeans() = delete;
    KMeans(const KMeans &obj) = delete;
    KMeans &operator=(const KMeans &obj) = delete;

    KMeans(const std::vector<FileInfo> &_vecFileInfo);
    std::vector<std::set<std::string>> calculate(size_t k);
};

#endif