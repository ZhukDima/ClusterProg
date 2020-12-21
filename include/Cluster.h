#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <stack>

class Cluster
{
public:
    Cluster();
    Cluster(const std::vector<size_t>& indexes);

    void addIndexElem(size_t index);

    std::vector<size_t> getClusteringIndexes() const;

    template<typename Data>
    std::stack<Data> getClusteringDataByData(const std::vector<Data>& data) const;

private:
    std::vector<size_t> indexes;
};

#endif