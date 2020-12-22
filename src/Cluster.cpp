#include "Cluster.hpp"

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
