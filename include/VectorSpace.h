#ifndef VECTORSPACE_H
#define VECTORSPACE_H

#include <array>

template <class T, size_t N>
struct VectorSpace
{
public:
    VectorSpace();
    VectorSpace(const VectorSpace &) = delete;
    VectorSpace operator=(const VectorSpace &) = delete;

    T &operator[](int index);
    T operator[](int index) const;
    VectorSpace &operator+=(const VectorSpace &obj);
    VectorSpace &operator/=(T a);
    double operator-(const VectorSpace &obj) const;

private:
    std::array<T, N> arr;
};

#endif