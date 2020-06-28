//
// Created by Tasselmi liang on 2020/6/29.
//

#ifndef ALGORITHMS_IN_CPP_SKIPNODE_H
#define ALGORITHMS_IN_CPP_SKIPNODE_H

#include <utility>
using std::pair;

template<typename K, typename E>
struct SkipNode
{
    using pair_type = pair<const K, E>;
    pair_type element;
    SkipNode<K, E> **next; //指针数组

    SkipNode(const pair_type &thePair, int size) : element(thePair) {
        next = new SkipNode<K, E> * [size];
    }
};

#endif //ALGORITHMS_IN_CPP_SKIPNODE_H
