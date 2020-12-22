#ifndef KMEANS_H
#define KMEANS_H

#include "Cluster.hpp"
#include <set>
#include <vector>

template <typename Data>
class KMeans
{
public:
    KMeans(const std::vector<Data> &data);
    KMeans(const KMeans &) = delete;
    KMeans &operator=(const KMeans &) = delete;

    // CalcDelta:
    //                  static double   calc(const Data&, const Data&)
    // CompEqual:
    //                  static bool     comp(const Data&, const Data&)
    // MakeCentroid:
    //                  static Data     make(const std::stack<Data>&),
    //                  static Data     make(const Data&)
    template <class CalcDelta, class CompEqual, class MakeCentroid>
    std::vector<Cluster> calculate(size_t k) const;

private:
    std::vector<Data> data;
};

template <typename Data>
KMeans<Data>::KMeans(const std::vector<Data> &data) : data(data) {}

template <typename Data>
template <class CalcDelta, class CompEqual, class MakeCentroid>
std::vector<Cluster> KMeans<Data>::calculate(size_t k) const
{
    // 1 step
    std::vector<Data> centroids(k);

    {
        std::set<size_t> s;
        while (s.size() < k)
        {
            s.insert(std::rand() % data.size());
        }
        size_t i = 0;
        for (size_t j : s)
        {
            centroids[i++] = MakeCentroid::make(data[j]);
        }
    }

    // 2 step
    std::vector<Cluster> clustersNewCentroids;
    while (true)
    {
        clustersNewCentroids = std::vector<Cluster>(k);

        for (size_t vi = 0; vi < k; vi++)
        {
            Data v = data[vi];
            size_t indexBestCentroid = 0;
            double deltaBestCentroid = CalcDelta::calc(v, centroids[indexBestCentroid]);
            for (size_t i = 1; i < k; i++)
            {
                double newDeltaCentroid = CalcDelta::calc(v, centroids[i]);
                if (newDeltaCentroid < deltaBestCentroid)
                {
                    indexBestCentroid = i;
                    deltaBestCentroid = newDeltaCentroid;
                }
            }

            clustersNewCentroids[indexBestCentroid].addIndexElem(vi);
        }

        std::vector<Data> newCentroids;
        for (const auto &clusterNewCentroid : clustersNewCentroids)
        {
            newCentroids.push_back(MakeCentroid::make(clusterNewCentroid.getClusteringDataByData(data)));
        }

        centroids.swap(newCentroids);

        // 3 step
        bool flag = true;
        for (size_t i = 0; flag && i < k; i++)
            flag = CompEqual::comp(centroids[i], newCentroids[i]);

        if (flag)
        {
            break;
        }
    }

    // 4 step
    return clustersNewCentroids;
<<<<<<< HEAD:src/KMeans.cpp
}
=======
}

#endif
>>>>>>> 85a4219aea66811d2abf6a81c00a538637bef59f:include/KMeans.hpp
