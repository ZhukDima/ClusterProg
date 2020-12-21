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
std::stack<Data> Cluster::getClusteringDataByData(const std::vector<Data> &data) const
{
    std::stack<Data> ans;
    for (int index : indexes)
    {
        ans.push(data[index]);
    }
    return ans;
}