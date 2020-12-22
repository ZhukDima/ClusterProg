#include "VectorSpace.h"
#include <assert.h>
#include <cmath> // abs

template <class T>
VectorSpace<T>::VectorSpace(size_t N) : vec(N) {}

template <class T>
T &VectorSpace<T>::operator[](int index)
{
    return vec[index];
}

template <class T>
const T &VectorSpace<T>::operator[](int index) const
{
    return vec[index];
}

template <class T>
VectorSpace<T> &VectorSpace<T>::operator+=(const VectorSpace<T> &obj)
{
    assert(vec.size() == obj.vec.size());
    size_t i = 0;
    for (T &elem : vec)
    {
        elem += obj.vec[i++];
    }
    return *this;
}

template <class T>
VectorSpace<T> &VectorSpace<T>::operator/=(T a)
{
    for (T &elem : vec)
    {
        elem /= divider;
    }
    return *this;
}

template <class T>
double VectorSpace<T>::operator-(const VectorSpace<T> &obj) const
{
    assert(vec.size() == obj.vec.size());
    double ans = 0;
    size_t i = 0;
    for (const T &elem : vec)
    {
        ans += std::abs(elem - obj.vec[i]);
    }
    return ans;
}
