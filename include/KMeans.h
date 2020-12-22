#ifndef KMEANS_H
#define KMEANS_H

#include "Cluster.h"

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

#endif
