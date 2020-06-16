//
// Created by Tasselmi liang on 2020/6/16.
//

#ifndef ALGORITHMS_IN_CPP_LINKEDLIST_H
#define ALGORITHMS_IN_CPP_LINKEDLIST_H

#include <sstream>
#include "../chapter05/LinearList.h"

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
};

template<typename T>
void Chain<T>::checkIndex(int theIndex) const {

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
    return false;
}

template<typename T>
int Chain<T>::size() const {
    return 0;
}

template<typename T>
T &Chain<T>::get(int theIndex) const {
    return ;
}

template<typename T>
int Chain<T>::indexOf(const T &theElement) const {
    return 0;
}

template<typename T>
void Chain<T>::erase(int theIndex) {

}

template<typename T>
void Chain<T>::insert(int theIndex, const T &theElement) {

}

template<typename T>
void Chain<T>::output(ostream &out) const {

}

#endif //ALGORITHMS_IN_CPP_LINKEDLIST_H
