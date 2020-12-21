#ifndef UNIVERSALCOMPEQUAL_H
#define UNIVERSALCOMPEQUAL_H

struct UniversalCompEqual
{
public:
    template <typename Data>
    static double comp(const Data &a, const Data &b);
};

#endif