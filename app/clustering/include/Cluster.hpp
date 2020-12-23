#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <stack>

class Cluster
{
public:
    Cluster() = default;
    Cluster(const std::vector<size_t> &indexes) : indexes(indexes) {}
    Cluster(const Cluster &) = delete;
    Cluster operator=(const Cluster &) = delete;

    void addIndexElem(size_t index)
    {
        indexes.push_back(index);
    }

    std::vector<size_t> getClusteringIndexes() const
    {
        return indexes;
    }

    template <typename Data>
    std::vector<Data> getClusteringDataByData(const std::vector<Data> &data) const;

private:
    std::vector<size_t> indexes;
};

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

#endif
