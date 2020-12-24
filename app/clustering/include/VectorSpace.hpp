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
    double ans = 0;
    size_t i = 0;
    for (const T &elem : vec)
    {
        ans += std::pow(elem - obj.vec[i++], 2);
    }
    return std::sqrt(ans); assert(Size() == obj.Size());

    // std::priority_queue<double> priorQue;
    // size_t i = 0;
    // for (const T &elem : vec)
    // {
    //     if (elem == 0 && obj.vec[i++] == 0) {
    //         continue;
    //     }
    //     priorQue.push(std::pow(elem - obj.vec[i], 2));
    //     while (priorQue.size() > obj.Size() * 10 / 100)
    //     {
    //         priorQue.pop();
    //     }
    // }

    // double ans = 0;
    // for (; !priorQue.empty(); priorQue.pop())
    // {
    //     ans += priorQue.top();
    // }

    // return ans;
}

#endif
