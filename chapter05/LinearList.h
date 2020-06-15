//
// Created by Tasselmi liang on 2020/6/15.
//

#ifndef ALGORITHMS_IN_CPP_LINEARLIST_H
#define ALGORITHMS_IN_CPP_LINEARLIST_H

#include <ostream>
#include "../exception/myExceptions.h"
using std::ostream;

template <typename T>
class LinearList
{
public:
    virtual ~LinearList() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int theIndex) const = 0;
    virtual int indexOf(const T& theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output(ostream& out) const = 0;
};

#endif //ALGORITHMS_IN_CPP_LINEARLIST_H
