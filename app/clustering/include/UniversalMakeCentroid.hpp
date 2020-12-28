#ifndef UNIVERSALMAKECENTROID_H
#define UNIVERSALMAKECENTROID_H

#include <vector>
#include <assert.h>

struct UniversalMakeCentroid
{
public:
    UniversalMakeCentroid() = delete;

    template <typename Data>
    static Data make(const Data &data);

    template <typename Data>
    static Data make(const std::vector<Data> &vec);
};

template <typename Data>
Data UniversalMakeCentroid::make(const Data &data)
{
    return data;
}

template <typename Data>
Data UniversalMakeCentroid::make(const std::vector<Data> &vec)
{
    assert(vec.size() > 0);
    Data ans(vec[0]);
    for (size_t i = 1; i < vec.size(); i++)
    {
        ans += vec[i];
    }
    return ans /= vec.size();
}

#endif
