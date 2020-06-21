//
// Created by Tasselmi liang on 2020/6/20.
//

#ifndef ALGORITHMS_IN_CPP_EXTENDEDCHAIN_H
#define ALGORITHMS_IN_CPP_EXTENDEDCHAIN_H

#include "ExtendedLinearList.h"
#include "Chain.h"

template<typename T>
class ExtendedChain : public ExtendedLinearList<T>, public Chain<T>
{
protected:
    ChainNode<T>* lastNode;

public:
    explicit ExtendedChain(int initialCapacity = 10) : Chain<T>(initialCapacity) { }
    ExtendedChain(const ExtendedChain<T>& c) : Chain<T>(c) { }

    bool empty() const override;

    int size() const override;

    T &get(int theIndex) const override;

    int indexOf(const T &theElement) const override;

    void erase(int theIndex) override;

    void insert(int theIndex, const T &theElement) override;

    void output(ostream &out) const override;

    void clear() override;

    void push_back(const T &theElement) override;
};

template<typename T>
bool ExtendedChain<T>::empty() const {
    return Chain<T>::empty();
}

template<typename T>
int ExtendedChain<T>::size() const {
    return Chain<T>::listSize;
}

template<typename T>
T &ExtendedChain<T>::get(int theIndex) const {
    return Chain<T>::get(theIndex);
}

template<typename T>
int ExtendedChain<T>::indexOf(const T &theElement) const {
    return Chain<T>::indexOf(theElement);
}

template<typename T>
void ExtendedChain<T>::erase(int theIndex) {
    Chain<T>::checkIndex(theIndex);

    ChainNode<T>* deleteNode;
    if (theIndex == 0) {
        deleteNode = this->firstNode;
        this->firstNode = this->firstNode->next;
    } else {
        ChainNode<T>* p = this->firstNode;
        for (int i = 0; i < theIndex - 1; ++i) {
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;

        if (deleteNode == lastNode) lastNode = p;
    }

    this->listSize--;
    delete deleteNode;
}

template<typename T>
void ExtendedChain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > this->listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalParameterValue(s.str());
    }

    if (theIndex == 0) {
        this->firstNode = new ChainNode<T>(theElement, this->firstNode);
        if (this->listSize == 0) lastNode = this->firstNode;
    } else {
        ChainNode<T>* p = this->firstNode;
        for (int i = 0; i < theIndex - 1; ++i) {
            p = p->next;
        }
        p->next = new ChainNode<T>(theElement, p->next);
        if (this->listSize == theIndex) lastNode = p->next;
    }

    this->listSize++;
}

template<typename T>
void ExtendedChain<T>::output(ostream &out) const {
    Chain<T>::output(out);
}

template<typename T>
void ExtendedChain<T>::clear() {
    while (this->firstNode != nullptr) {
        ChainNode<T>* nextNode = this->firstNode->next;
        delete this->firstNode;
        this->firstNode = nextNode;
    }
    this->listSize = 0;
}

template<typename T>
void ExtendedChain<T>::push_back(const T &theElement) {
    auto newNode = new ChainNode<T>(theElement, nullptr);
    if (this->firstNode == nullptr) this->firstNode = lastNode = newNode;
    else {
        lastNode->next = newNode;
        lastNode = newNode;
    }
    this->listSize++;
}

#endif //ALGORITHMS_IN_CPP_EXTENDEDCHAIN_H
