//
// Created by Tasselmi liang on 2020/8/30.
//

#ifndef ALGORITHMS_IN_CPP_LINKEDBINARYTREE_H
#define ALGORITHMS_IN_CPP_LINKEDBINARYTREE_H

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "../chapter09/ArrayQueue.h"

using std::cout;
using std::endl;

template<class E>
class LinkedBinaryTree : public BinaryTree<BinaryTreeNode<E>>
{
    protected:
        BinaryTreeNode<E> *root;

        int treeSize;

        static void (*visit)(BinaryTreeNode<E>*); //静态数据成员visit

        static void preOrder(BinaryTreeNode<E> *t) {
            if (t != nullptr) {
                visit(t);
                preOrder(t->leftChild);
                preOrder(t->rightChild);
            }
        }

        static void midOrder(BinaryTreeNode<E> *t) {
            if (t != nullptr) {
                midOrder(t->leftChild);
                visit(t);
                midOrder(t->rightChild);
            }
        }

        static void postOrder(BinaryTreeNode<E> *t) {
            if (t != nullptr) {
                postOrder(t->leftChild);
                postOrder(t->rightChild);
                visit(t);
            }
        }

        static void dispose(BinaryTreeNode<E> *t) {
            delete t;
        }

        static void output(BinaryTreeNode<E> *t) {
            cout << t->element << ' ';
        }

        static int height(BinaryTreeNode<E> *t) {
            if (t == nullptr) return 0;
            int hl = height(t->leftChild);
            int hr = height(t->rightChild);
            if (hl > hr) return ++hl;
            else return ++hr;
        }

    public:
        LinkedBinaryTree() {
            root = nullptr;
            treeSize = 0;
        }

        void erase() {
            postOrder(dispose);
            root = nullptr;
            treeSize = 0;
        }

        ~LinkedBinaryTree() {
            erase();
        }

        bool empty() {
            return treeSize == 0;
        }

        int size() {
            return treeSize;
        }

        void preOrder(void(*theVisit)(BinaryTreeNode<E> *)) {
            visit = theVisit;
            preOrder(root);
        }

        void midOrder(void(*theVisit)(BinaryTreeNode<E> *)) {
            visit = theVisit;
            midOrder(root);
        }

        void postOrder(void(*theVisit)(BinaryTreeNode<E> *)) {
            visit = theVisit;
            postOrder(root);
        }

        void levelOrder(void(*theVisit)(BinaryTreeNode<E> *)) {
            ArrayQueue<BinaryTreeNode<E> *> q;
            BinaryTreeNode<E> *t = root;

            while (t != nullptr) {
                theVisit(t);

                if (t->leftChild != nullptr) {
                    q.push(t->leftChild);
                }
                if (t->rightChild != nullptr) {
                    q.push(t->rightChild);
                }

                try {
                    t = q.front();
                } catch (QueueEmpty &) {
                    return;
                }

                q.pop();
            }
        }

        void preOrderOutput() {
            preOrder(output);
            cout << endl;
        }

        void midOrderOutput() {
            midOrder(output);
            cout << endl;
        }

        void postOrderOutput() {
            postOrder(output);
            cout << endl;
        }

        void levelOrderOutput() {
            levelOrder(output);
            cout << endl;
        }
};

#endif //ALGORITHMS_IN_CPP_LINKEDBINARYTREE_H
