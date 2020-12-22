#ifndef UNIVERSALMAKECENTROID_H
#define UNIVERSALMAKECENTROID_H

#include <vector>

struct UniversalMakeCentroid
{
public:
    UniversalMakeCentroid() = delete;

    template <typename Data>
    static Data make(const Data &data);

    template <typename Data>
    static Data make(const std::vector<Data> &vec);
};

#endif
