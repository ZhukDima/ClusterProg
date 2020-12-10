#include "KMeans.h"
#include <cmath> // pow

double KMeans::deltaBetweenTFIDF(const std::map<std::string, double> &m1, const std::map<std::string, double> &m2) const
{
    double result = 0;

    for (auto p = m1.begin(); p != m1.end(); ++p)
    {
        auto v = m2.find(p->first);
        if (v != m2.end())
        {
            result += std::pow(p->second - v->second, 2);
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

    for (auto i = l.begin(), j = r.begin(); i != l.end(); ++i, ++j)
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

    for (auto i = centroids.begin(), j = newCentroids.begin(); i != centroids.end(); ++i, ++j)
    {
        if (!equalCentroid(*i, *j))
        {
            return false;
        }
    }
    return true;
}

KMeans::KMeans(const std::vector<FileInfo> &_vecFileInfo)
{
    TFIDF ti(_vecFileInfo);
    for (auto i = _vecFileInfo.begin(); i != _vecFileInfo.end(); ++i)
    {
        vecFileInfo.push_back(FileInfo(i->getPath(), ti.mapTFIDFforFile(i->getPath())));
    }
}

std::vector<std::set<std::string>> KMeans::calculate(size_t k)
{
    // 1 step
    centroids = std::vector<std::map<std::string, double>>(k);

    {
        std::set<size_t> s;
        while (s.size() < k)
        {
            s.insert(std::rand() % vecFileInfo.size());
        }
        size_t j = 0;
        for (auto i = s.begin(); i != s.end(); ++i)
        {
            centroids[j] = vecFileInfo[*i].getAllMetric();
        }
    }

    // 2 step
    while (true)
    {
        std::vector<std::map<std::string, double>> newCentroids(k);
        std::vector<size_t> countElemAtCentroids(k);

        for (auto v = vecFileInfo.begin(); v != vecFileInfo.end(); ++v)
        {
            size_t indexBestCentroid = 0;
            double deltaBestCentroid = deltaBetweenTFIDF(v->getAllMetric(), centroids[indexBestCentroid]);
            for (size_t i = 1; i < k; i++)
            {
                double newDeltaCentroid = deltaBetweenTFIDF(v->getAllMetric(), centroids[i]);
                if (newDeltaCentroid < deltaBestCentroid)
                {
                    indexBestCentroid = i;
                    deltaBestCentroid = newDeltaCentroid;
                }
            }

            countElemAtCentroids[indexBestCentroid] += 1;
            for (auto p = v->getAllMetric().begin(); p != v->getAllMetric().end(); ++p)
            {
                newCentroids[indexBestCentroid][p->first] += p->second;
            }
        }

        for (size_t i = 0; i < k; i++)
        {
            for (auto p = newCentroids[i].begin(); p != newCentroids[i].end(); ++p)
            {
                p->second /= countElemAtCentroids[i];
            }
        }

        centroids.swap(newCentroids);

        // 3 step
        if (!equalCentroidsWithBase(newCentroids))
        {
            break;
        }
    }

    // 4 step
    std::vector<std::set<std::string>> resualt(k);

    for (auto v = vecFileInfo.begin(); v != vecFileInfo.end(); ++v)
    {
        size_t indexBestCentroid = 0;
        double deltaBestCentroid = deltaBetweenTFIDF(v->getAllMetric(), centroids[indexBestCentroid]);
        for (size_t i = 1; i < k; i++)
        {
            double newDeltaCentroid = deltaBetweenTFIDF(v->getAllMetric(), centroids[i]);
            if (newDeltaCentroid < deltaBestCentroid)
            {
                indexBestCentroid = i;
                deltaBestCentroid = newDeltaCentroid;
            }
        }

        resualt[indexBestCentroid].insert(v->getPath());
    }

    return resualt;
}