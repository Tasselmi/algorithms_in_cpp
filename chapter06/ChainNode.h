//
// Created by Tasselmi liang on 2020/6/20.
//

#ifndef ALGORITHMS_IN_CPP_CHAINNODE_H
#define ALGORITHMS_IN_CPP_CHAINNODE_H

template <typename T>
struct ChainNode
{
    T element;
    ChainNode<T>* next;

    ChainNode() = default;
    explicit ChainNode(const T& elem) {
        element = elem;
    }
    ChainNode(const T& elem, ChainNode<T>* nt) {
        element = elem;
        next = nt;
    }
};

#endif //ALGORITHMS_IN_CPP_CHAINNODE_H
