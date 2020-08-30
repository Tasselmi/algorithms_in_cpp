//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_BINARYTREENODE_H
#define ALGORITHMS_IN_CPP_BINARYTREENODE_H

template<class T>
struct BinaryTreeNode
{
    T element;

    BinaryTreeNode<T> *leftChild;

    BinaryTreeNode<T> *rightChild;

    BinaryTreeNode() {
        leftChild = rightChild = nullptr;
    }

    BinaryTreeNode(const T& theElement, BinaryTreeNode *theLeftChild, BinaryTreeNode *theRightChild) {
        element = theElement;
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }

};

#endif //ALGORITHMS_IN_CPP_BINARYTREENODE_H
