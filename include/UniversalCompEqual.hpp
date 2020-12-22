#ifndef UNIVERSALCOMPEQUAL_H
#define UNIVERSALCOMPEQUAL_H

struct UniversalCompEqual
{
public:
    UniversalCompEqual() = delete;

    template <typename Data>
    static double comp(const Data &a, const Data &b);
};

template <typename Data>
double UniversalCompEqual::comp(const Data &a, const Data &b)
{
    return a == b;
}

#endif
