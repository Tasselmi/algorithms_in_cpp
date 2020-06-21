//
// Created by Tasselmi liang on 2020/6/20.
//

#ifndef ALGORITHMS_IN_CPP_EXTENDEDLINEARLIST_H
#define ALGORITHMS_IN_CPP_EXTENDEDLINEARLIST_H

#include "../chapter05/LinearList.h"

template<typename T>
class ExtendedLinearList : LinearList<T>
{
public:
    virtual ~ExtendedLinearList() = default;
    virtual void clear() = 0;
    virtual void push_back(const T& theElement) = 0;
};

#endif //ALGORITHMS_IN_CPP_EXTENDEDLINEARLIST_H
