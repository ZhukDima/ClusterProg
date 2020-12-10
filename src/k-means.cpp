#include "k-means.h"
#include <cmath> // pow

double KMeans::deltaBetweenTFIDF(const std::map<std::string, double> &m1, const std::map<std::string, double> &m2) const
{
    double result = 0;
    for (auto &p : m1)
    {
        auto v = m2.find(p.first);
        if (v != m2.end())
        {
            result += std::pow(p.second - v->second, 2);
        }
    }
    return result;
}

bool KMeans::equalCentroid(const std::map<std::string, double> &l, const std::map<std::string, double> &r) const
{
    if (l.size() != r.size())
    {
        return false;
    }

    std::map<std::string, double>::const_iterator i, j;
    for (i = l.begin(), j = r.begin(); i != l.end(); ++i, ++j)
    {
        if (*i != *j)
        {
            return false;
        }
    }

    return true;
}

bool KMeans::equalCentroidsWithBase(const std::vector<std::map<std::string, double>> &newCentroids) const
{
    if (centroids.size() != newCentroids.size())
    {
        return false;
    }

    for (int i = 0; i < centroids.size(); i++)
    {
        if (!equalCentroid(centroids[i], newCentroids[i]))
        {
            return false;
        }
    }
    return true;
}

KMeans::KMeans(const std::vector<FileInfo> &_vecFileInfo)
{
    TFIDF ti(_vecFileInfo);
    for (auto &v : vecFileInfo)
    {
        vecFileInfo.push_back(FileInfo(v.getPath(), ti.mapTFIDFforFile(v.getPath())));
    }
}

std::vector<std::set<std::string>> KMeans::calculate(size_t k)
{
    // 1 step
    centroids.resize(0);
    centroids.resize(k);

    {
        std::set<size_t> s;
        while (s.size() < k)
        {
            s.insert(std::rand() % vecFileInfo.size());
        }
        int j = 0;
        for (size_t i : s)
        {
            centroids[j] = vecFileInfo[i].getAllMetric();
        }
    }

    // 2 step
    while (true)
    {
        std::vector<std::map<std::string, double>> newCentroids(k);
        std::vector<int> countElemAtCentroids(k);

        for (auto &v : vecFileInfo)
        {
            int indexBestCentroid = 0;
            double deltaBestCentroid = deltaBetweenTFIDF(v.getAllMetric(), centroids[indexBestCentroid]);
            for (int i = 1; i < k; i++)
            {
                double newDeltaCentroid = deltaBetweenTFIDF(v.getAllMetric(), centroids[i]);
                if (newDeltaCentroid < deltaBestCentroid)
                {
                    indexBestCentroid = i;
                    deltaBestCentroid = newDeltaCentroid;
                }
            }

            countElemAtCentroids[indexBestCentroid] += 1;
            for (auto &p : v.getAllMetric())
            {
                newCentroids[indexBestCentroid][p.first] += p.second;
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (auto &p : newCentroids[i])
            {
                p.second /= countElemAtCentroids[i];
            }
        }

        std::swap(centroids, newCentroids);

        // 3 step
        if (!equalCentroidsWithBase(newCentroids))
        {
            break;
        }
    }

    // 4 step
    std::vector<std::set<std::string>> resualt(k);

    for (auto &v : vecFileInfo)
    {
        int indexBestCentroid = 0;
        double deltaBestCentroid = deltaBetweenTFIDF(v.getAllMetric(), centroids[indexBestCentroid]);
        for (int i = 1; i < k; i++)
        {
            double newDeltaCentroid = deltaBetweenTFIDF(v.getAllMetric(), centroids[i]);
            if (newDeltaCentroid < deltaBestCentroid)
            {
                indexBestCentroid = i;
                deltaBestCentroid = newDeltaCentroid;
            }
        }

        resualt[indexBestCentroid].insert(v.getPath());
    }

    return resualt;
}