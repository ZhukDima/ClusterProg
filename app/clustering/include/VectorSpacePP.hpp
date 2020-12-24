#ifndef VECTORSPACEPP_H
#define VECTORSPACEPP_H

#include "VectorSpace.hpp"
#include <queue>

template <class T>
struct VectorSpacePP : public VectorSpace
{
public:
    VectorSpacePP(size_t N);

    double operator-(const VectorSpacePP &obj) const;
};

template <class T>
VectorSpacePP<T>::VectorSpacePP(size_t N) : VectorSpace(N) {}

template <class T>
double VectorSpacePP<T>::operator-(const VectorSpacePP<T> &obj) const
{
    assert(Size() == obj.Size());

    std::priority_queue<double> priorQue;
    for (const T &elem : vec)
    {
        priorQue.push(std::pow(elem - obj.vec[i++], 2));
        while (priorQue.size() > obj.Size() * 80 / 100)
        {
            priorQue.pop();
        }
    }

    double ans = 0;
    for (; !priorQue.empty(); priorQue.pop())
    {
        ans += priorQue.top();
    }

    return ans;
}

#endif
