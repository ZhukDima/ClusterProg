#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <stack>

class Cluster
{
public:
    Cluster();
    Cluster(const std::vector<size_t> &indexes);
    Cluster(const Cluster &) = delete;
    Cluster operator=(const Cluster &) = delete;

    void addIndexElem(size_t index);

    std::vector<size_t> getClusteringIndexes() const;

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
