#include "VectorSpace.h"
#include <assert.h>

template <class T>
VectorSpace<T>::VectorSpace(size_t N) : N(N), vec(N) {}

template <class T>
T &VectorSpace<T>::operator[](int index)
{
    return vec[index];
}

template <class T>
T VectorSpace<T>::operator[](int index) const
{
    return vec[index];
}

template <class T>
VectorSpace<T> &VectorSpace<T>::operator+=(const VectorSpace<T> &obj)
{
    assert(N == obj.N);
    for (size_t i = 0; i < N; i++)
    {
        arr[i] += obj.arr[i];
    }
    return this;
}

template <class T>
VectorSpace<T> &VectorSpace<T>::operator/=(T a)
{
    for (size_t i = 0; i < N; i++)
    {
        arr[i] /= a;
    }
    return this;
}

template <class T>
double VectorSpace<T>::operator-(const VectorSpace<T> &obj) const
{
    assert(N == obj.N);
    double ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        ans += arr[i] - obj.arr[i];
    }
    return ans;
}