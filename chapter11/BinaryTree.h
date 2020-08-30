//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_BINARYTREE_H
#define ALGORITHMS_IN_CPP_BINARYTREE_H

#include <functional>

template<class T>
class BinaryTree
{
    public:
        virtual ~BinaryTree() = default;
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual void preOrder(void (*)(T*)) = 0;
        virtual void midOrder(void (*)(T*)) = 0;
        virtual void postOrder(void (*)(T*)) = 0;
        virtual void levelOrder(void (*)(T*)) = 0;
};

#endif //ALGORITHMS_IN_CPP_BINARYTREE_H
