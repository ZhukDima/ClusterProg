#include "VectorSpace.h"

template <class T, size_t N>
VectorSpace<T, N>::VectorSpace() {}

template <class T, size_t N>
T &VectorSpace<T, N>::operator[](int index)
{
    return arr[index];
}

template <class T, size_t N>
T VectorSpace<T, N>::operator[](int index) const
{
    return arr[index];
}

template <class T, size_t N>
VectorSpace<T, N> &VectorSpace<T, N>::operator+=(const VectorSpace<T, N> &obj)
{
    for (size_t i = 0; i < N; i++)
    {
        arr[i] += obj.arr[i];
    }
    return this;
}

template <class T, size_t N>
VectorSpace<T, N> &VectorSpace<T, N>::operator/=(T a)
{
    for (size_t i = 0; i < N; i++)
    {
        arr[i] /= a;
    }
    return this;
}

template <class T, size_t N>
double VectorSpace<T, N>::operator-(const VectorSpace<T, N> &obj) const
{
    double ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        ans += arr[i] - obj.arr[i];
    }
    return ans;
}