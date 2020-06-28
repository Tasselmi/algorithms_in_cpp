//
// Created by Tasselmi liang on 2020/6/28.
//

#ifndef ALGORITHMS_IN_CPP_PAIRNODE_H
#define ALGORITHMS_IN_CPP_PAIRNODE_H

#include <utility>

template<typename K, typename V>
struct PairNode
{
    using pair_type = std::pair<const K, V>;
    using node_type = PairNode<K, V>;
    pair_type element;
    node_type * next;

    explicit PairNode(const pair_type thePair) : element(thePair) { }
    PairNode(const pair_type& thePair, node_type * theNext) : element(thePair) {
        next = theNext;
    }
};

#endif //ALGORITHMS_IN_CPP_PAIRNODE_H
