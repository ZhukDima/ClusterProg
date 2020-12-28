#ifndef VECTORSPACE_H
#define VECTORSPACE_H

#include <vector>
#include <cmath> // abs
#include <assert.h>
#include <queue>

template <class T>
struct VectorSpace
{
public:
    VectorSpace(size_t N);
    VectorSpace(const VectorSpace &) = default;
    VectorSpace &operator=(const VectorSpace &) = default;

    size_t Size() const;
    T &operator[](int index);
    const T &operator[](int index) const;
    VectorSpace &operator+=(const VectorSpace &obj);
    bool operator==(const VectorSpace &obj) const;
    VectorSpace &operator/=(T a);
    double operator-(const VectorSpace &obj) const;

protected:
    std::vector<T> vec;
};

template <class T>
VectorSpace<T>::VectorSpace(size_t N) : vec(N) {}

template <class T>
size_t VectorSpace<T>::Size() const
{
    return vec.size();
}

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
    assert(Size() == obj.Size());
    size_t i = 0;
    for (T &elem : vec)
    {
        elem += obj.vec[i++];
    }
    return *this;
}

template <class T>
bool VectorSpace<T>::operator==(const VectorSpace<T> &obj) const
{
    assert(Size() == obj.Size());
    size_t i = 0;
    for (const T &elem : vec)
    {
        if (elem != obj.vec[i++])
        {
            return false;
        }
    }
    return true;
}

template <class T>
VectorSpace<T> &VectorSpace<T>::operator/=(T divider)
{
    for (T &elem : vec)
    {
        elem /= divider;
    }
    return *this;
}

#include <iostream>

template <class T>
double VectorSpace<T>::operator-(const VectorSpace<T> &obj) const
{
    assert(Size() == obj.Size());
    double sqrX = 0, sqrY = 0, X_Y = 0;
    size_t i = 0;
    for (const T &elem : vec)
    {
        X_Y += elem * obj.vec[i];
        sqrX += elem * elem;
        sqrY += obj.vec[i] * obj.vec[i];
        i++;
    }
    return 1 - X_Y / std::sqrt(sqrX) / std::sqrt(sqrY);
}

#endif
