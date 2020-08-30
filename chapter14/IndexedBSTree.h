//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_INDEXEDBSTREE_H
#define ALGORITHMS_IN_CPP_INDEXEDBSTREE_H

#include "BSTree.h"

template<class K, class E>
class IndexedBSTree : public BSTree<K, E>
{
public:
    virtual pair<const K, E> *get(int) const = 0;
    virtual void erase(int) = 0;
};


#endif //ALGORITHMS_IN_CPP_INDEXEDBSTREE_H
