//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_BSTREE_H
#define ALGORITHMS_IN_CPP_BSTREE_H

#include "../chapter10/Dictionary.h"

template<class K, class E>
class BSTree : public Dictionary<K, E>
{
    public:
        virtual void ascend() = 0;
};

#endif //ALGORITHMS_IN_CPP_BSTREE_H
