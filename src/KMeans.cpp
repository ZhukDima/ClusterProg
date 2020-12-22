#include "KMeans.h"
#include <set>
#include <stack>

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
}