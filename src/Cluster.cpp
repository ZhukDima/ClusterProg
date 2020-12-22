#include "Cluster.h"

Cluster::Cluster() {}

Cluster::Cluster(const std::vector<size_t> &indexes) : indexes(indexes) {}

void Cluster::addIndexElem(size_t index)
{
    indexes.push_back(index);
}

std::vector<size_t> Cluster::getClusteringIndexes() const
{
    return indexes;
}

template <typename Data>
std::vector<Data> Cluster::getClusteringDataByData(const std::vector<Data> &data) const
{
    std::vector<Data> ans;
    for (int index : indexes)
    {
        ans.push_back(data[index]);
    }
    return ans;
}