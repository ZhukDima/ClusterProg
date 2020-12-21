#ifndef VECTORSPACE_H
#define VECTORSPACE_H

#include <array>

template <class T, size_t N>
struct VectorSpace
{
public:
    VectorSpace();
    T &operator[](int index);
    T operator[](int index) const;
    VectorSpace &operator+=(const VectorSpace &obj);
    VectorSpace &operator/=(T a);

private:
    std::array<T, N> arr;
};

#endif