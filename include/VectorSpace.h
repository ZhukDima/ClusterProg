#ifndef VECTORSPACE_H
#define VECTORSPACE_H

#include <vector>

template <class T>
struct VectorSpace
{
public:
    VectorSpace(size_t N);
    VectorSpace(const VectorSpace &) = delete;
    VectorSpace operator=(const VectorSpace &) = delete;

    T &operator[](int index);
    T operator[](int index) const;
    VectorSpace &operator+=(const VectorSpace &obj);
    VectorSpace &operator/=(T a);
    double operator-(const VectorSpace &obj) const;

private:
    size_t N;
    std::vector<T> vec;
};

#endif