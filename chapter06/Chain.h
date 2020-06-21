//
// Created by Tasselmi liang on 2020/6/16.
//

#ifndef ALGORITHMS_IN_CPP_CHAIN_H
#define ALGORITHMS_IN_CPP_CHAIN_H

#include <sstream>
#include "../chapter05/LinearList.h"
#include "ChainNode.h"

template <typename T>
class Chain : public LinearList<T>
{
protected:
    void checkIndex(int theIndex) const;
    ChainNode<T> * firstNode;
    int listSize;

public:
    explicit Chain(int initialCapacity);
    Chain(const Chain<T>& theList);
    ~Chain();

    bool empty() const override;
    int size() const override;
    T &get(int theIndex) const override;
    int indexOf(const T &theElement) const override;
    void erase(int theIndex) override;
    void insert(int theIndex, const T &theElement) override;
    void output(ostream &out) const override;

    class Iterator;
    Iterator begin() { return Iterator(firstNode); }
    Iterator end() { return Iterator(); }

    //bin sort 箱排序； shell sort 希尔排序； bucket sort 桶排序；
    void binSort(int range);

    class Iterator
    {
    protected:
        ChainNode<T>* node;

    public:
        explicit Iterator(ChainNode<T>* theNode = nullptr) { node = theNode; }

        T& operator*() const { return node->element; }
        T* operator->() const { return &(node->element); }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        Iterator operator++(int) {
            auto old = *this;
            node = node->next;
            return old;
        }

        bool operator!=(const Iterator right) const {
            return node != right.node;
        }
        bool operator==(const Iterator right) const {
            return node == right.node;
        }
    };
};


template<typename T>
void Chain<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalParameterValue(s.str());
    }
}

template<typename T>
Chain<T>::Chain(int initialCapacity) {
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    firstNode = nullptr;
    listSize = 0;
}

template<typename T>
Chain<T>::Chain(const Chain<T> &theList) {
    listSize = theList.listSize;

    if (listSize == 0) {
        firstNode = nullptr;
        listSize = 0;
    }

    ChainNode<T>* sourceNode = theList.firstNode;
    firstNode = new ChainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    ChainNode<T>* targetNode = firstNode;
    while (sourceNode != NULL) {
        targetNode->next = new ChainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template<typename T>
Chain<T>::~Chain() {
    while (firstNode != NULL) {
        ChainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<typename T>
bool Chain<T>::empty() const {
    return listSize == 0;
}

template<typename T>
int Chain<T>::size() const {
    return listSize;
}

template<typename T>
T &Chain<T>::get(int theIndex) const {
    checkIndex(theIndex);
    ChainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; ++i) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<typename T>
int Chain<T>::indexOf(const T &theElement) const {
    ChainNode<T>* currentNode = firstNode;
    int idx = 0;

    while (currentNode != NULL && currentNode->element != theElement) {
        currentNode = currentNode->next;
        idx++;
    }

    if (currentNode == NULL) return -1;
    else return idx;
}

template<typename T>
void Chain<T>::erase(int theIndex) {
    checkIndex(theIndex);

    ChainNode<T>* deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        ChainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; ++i) p = p->next; // theIndex-1 拿到被删除的节点前面一个节点
        deleteNode = p->next; //被删除的节点
        p->next = p->next->next; //前一个节点指向被删除的节点后面一个节点
    }

    listSize--;
    delete deleteNode; //释放被删除节点的内存
}

template<typename T>
void Chain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalParameterValue(s.str());
    }

    if (theIndex == 0) firstNode = new ChainNode<T>(theElement, firstNode);
    else {
        ChainNode<T>* previousNode = firstNode;
        for (int i = 0; i < theIndex - 1; ++i) {
            previousNode = previousNode->next;
        }
        previousNode->next = new ChainNode<T>(theElement, previousNode->next);
    }

    listSize++;
}

template<typename T>
void Chain<T>::output(ostream &out) const {
    for (ChainNode<T>* node = firstNode; node != NULL; node = node->next)
       out << node->element << " ";
}

template<typename T>
void Chain<T>::binSort(int range) {
    ChainNode<T> **bottom, **top; // ChainNode<T>类型数据的指针数组
    bottom = new ChainNode<T>* [range + 1];
    top = new ChainNode<T>* [range + 1];
    for (int b = 0; b <= range; b++) bottom[b] = nullptr;

    for (; firstNode != nullptr; firstNode = firstNode->next) {
        int theBin = firstNode->element;
        if (bottom[theBin] == nullptr) bottom[theBin] = top[theBin] = firstNode;
        else {
            top[theBin]->next = firstNode;
            top[theBin] = firstNode;
        }
    }

    ChainNode<T>* y = nullptr;
    for (int theBin = 0; theBin <= range; theBin++) {
        if (bottom[theBin] != nullptr) {
            if (y == nullptr) firstNode = bottom[theBin];
            else y->next = bottom[theBin];
            y = top[theBin];
        }
    }
    if (y != nullptr) y->next = nullptr;

    delete [] top;
    delete [] bottom;
}

template<typename T>
ostream & operator<<(ostream& out, const Chain<T>& x) {
    x.output(out);
    return out;
}

#endif //ALGORITHMS_IN_CPP_CHAIN_H
