#include "UniversalMakeCentroid.h"

template <typename Data>
Data UniversalMakeCentroid::make(const Data &data)
{
    return data;
}

template <typename Data>
Data UniversalMakeCentroid::make(const std::stack<Data> &st)
{
    Data ans;
    for (auto &d : st)
    {
        ans += d;
    }
    return ans /= st.size();
}