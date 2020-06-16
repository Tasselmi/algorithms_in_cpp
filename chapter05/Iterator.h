//
// Created by Apple on 2020/6/16.
//

#ifndef ALGORITHMS_IN_CPP_ITERATOR_H
#define ALGORITHMS_IN_CPP_ITERATOR_H

#include <iterator>
using namespace std;

template <typename S>
class Iterator
{
protected:
    S* position;

public:
    typedef bidirectional_iterator_tag iterator_category;
    typedef S value_type;
    typedef ptrdiff_t difference_type;
    typedef S* pointer;
    typedef S&  reference;

    explicit Iterator(S* thePosition = 0) {
        position = thePosition;
    }

    S& operator*() const { return *position; }
    //指针(*)、取地址(&)、解引用(*)、引用(&)，这里的分别是解引用和取地址
    S* operator->() const { return &*position; }

    Iterator& operator++() {
        ++position;
        return *this;
    }
    Iterator operator++(int) {
        Iterator old = *this;
        ++position;
        return old;
    }
    Iterator& operator--() {
        --position;
        return *this;
    }
    Iterator operator--(int) {
        Iterator old = *this;
        --position;
        return old;
    }

    bool operator!=(const Iterator right) {
        return position != right.position;
    }
    bool operator==(const Iterator right) {
        return position == right.position;
    }
};

#endif //ALGORITHMS_IN_CPP_ITERATOR_H
