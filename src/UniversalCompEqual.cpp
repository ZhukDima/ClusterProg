#include "UniversalCompEqual.h"

template <typename Data>
double UniversalCompEqual::comp(const Data &a, const Data &b)
{
    return a == b;
}
