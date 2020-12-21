#ifndef UNIVERSALMAKECENTROID_H
#define UNIVERSALMAKECENTROID_H

#include <stack>

struct UniversalMakeCentroid
{
public:
    UniversalMakeCentroid() = delete;

    template <typename Data>
    static Data make(const Data &data);

    template <typename Data>
    static Data make(const std::stack<Data> &st);
};

#endif