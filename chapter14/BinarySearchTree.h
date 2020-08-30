//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_BINARYSEARCHTREE_H
#define ALGORITHMS_IN_CPP_BINARYSEARCHTREE_H

#include "BSTree.h"
#include "../chapter11/LinkedBinaryTree.h"

template<class K, class E>
class BinarySearchTree : public BSTree<K, E>, public LinkedBinaryTree<pair<const K, E>>
{
    using _pt = pair<const K, E>;
    using _lbtt = LinkedBinaryTree<_pt>;

public:
    bool empty() const override {
        return BSTree<K, E>::empty();
    }

    int size() const override {
        return BSTree<K, E>::size();
    }

    pair<const K, E> *find(const K &theKey) const override;

    void erase(const K &theKey) override;

    void insert(const _pt &thePair) override;

    void ascend() override {
        LinkedBinaryTree<_pt>::midOrderOutput();
    }
};

template<class K, class E>
pair<const K, E> *BinarySearchTree<K, E>::find(const K &theKey) const {
    BinaryTreeNode<pair<const K, E>> *p = LinkedBinaryTree<_pt>::root;

    while (p != nullptr) {
        if (theKey < p->element.first) {
            p = p->leftChild;
        } else {
            if (theKey > p->element.first) {
                p = p->rightChild;
            } else {
                return &(p->element);
            }
        }
    }

    return nullptr;
}

template<class K, class E>
void BinarySearchTree<K, E>::erase(const K &theKey) {
    BinaryTreeNode<_pt> *p = LinkedBinaryTree<_pt>::root,
                        *pp = nullptr;

    while (p != nullptr && p->element.first != theKey) {
        pp = p;
        if (theKey < p->element.first) {
            p = p->leftChild;
        } else
            p = p->rightChild;
    }
    if (p == nullptr)
        return;

    //找到的节点有两个孩子
    if (p->leftChild != nullptr && p->rightChild != nullptr) {
        BinaryTreeNode<_pt> *s = p->leftChild, *ps = p;

        //s是左树，在左树的右节点一直寻找，找到左树的最大值
        while (s->rightChild != nullptr) {
            ps = s;
            s = s->rightChild;
        }

        auto *q = new BinaryTreeNode<_pt>(s->element, p->leftChild, p->rightChild);
        if (pp == nullptr) {
            LinkedBinaryTree<_pt>::root = q;
        } else {
            if (p == pp->leftChild) {
                pp->leftChild = q;
            } else {
                pp->rightChild = q;
            }
        }
        if (ps == p) {
            pp = q;
        } else {
            pp = ps;
        }

        delete p;
        p = s;
    }

    BinaryTreeNode<_pt> *c;
    if (p->leftChild != nullptr) {
        c = p->leftChild;
    } else {
        c = p->rightChild;
    }
    if (p == _lbtt::root) {
        _lbtt :: root = c;
    } else {
        if (p == pp->leftChild) {
            pp->leftChild = c;
        } else {
            pp->rightChild = c;
        }
    }

    _lbtt :: treeSize--;
    delete p;
}

template<class K, class E>
void BinarySearchTree<K, E>::insert(const _pt &thePair) {
    BinaryTreeNode<_pt> *p = LinkedBinaryTree<_pt>::root,
                        *pp = nullptr;

    while (p != nullptr) {
        pp = p;
        if (thePair.first < p->element.first) {
            p = p->leftChild;
        } else {
            if (thePair.first > p->element.first) {
                p = p->rightChild;
            } else {
                p->element.second = thePair.second;
                return;
            }
        }
    }

    auto *newNode = new BinaryTreeNode<_pt>(thePair);
    if (LinkedBinaryTree<_pt>::root != nullptr) {
       if (thePair.first < pp->element.first) {
           pp->leftChild = newNode;
       } else {
           pp->rightChild = newNode;
       }
    } else
        LinkedBinaryTree<_pt>::root = newNode;

    LinkedBinaryTree<_pt>::treeSize++;
}

#endif //ALGORITHMS_IN_CPP_BINARYSEARCHTREE_H
