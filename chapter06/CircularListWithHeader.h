//
// Created by Tasselmi liang on 2020/6/20.
//

#ifndef ALGORITHMS_IN_CPP_CIRCULARLISTWITHHEADER_H
#define ALGORITHMS_IN_CPP_CIRCULARLISTWITHHEADER_H

#include <iostream>
#include <sstream>
#include <string>
#include "ChainNode.h"
#include "../exception/myExceptions.h"
using namespace std;

template<class T>
class CircularListWithHeader
{
protected:
    ChainNode<T>* headerNode;
    int listSize;
    void checkIndex(int theIndex) const;

public:
    CircularListWithHeader();
    int size() const;
    int indexOf(const T& theElement) const;
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;
};


template<class T>
void CircularListWithHeader<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalParameterValue(s.str());
    }
}

template<class T>
CircularListWithHeader<T>::CircularListWithHeader() {
    headerNode = new ChainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}

template<class T>
int CircularListWithHeader<T>::size() const {
    return listSize;
}

template<class T>
int CircularListWithHeader<T>::indexOf(const T &theElement) const {
    headerNode->element = theElement;
    ChainNode<T>* currentNode = headerNode->next;

    int idx = 0;
    while (currentNode->element != theElement) {
        currentNode = currentNode->next;
        idx++;
    }
    if (currentNode == headerNode) return -1;
    else return idx;
}

template<class T>
void CircularListWithHeader<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalParameterValue(s.str());
    }

    ChainNode<T>* p = headerNode;
    for (int i = 0; i < theIndex; ++i) { p = p->next; }
    p->next = new ChainNode<T>(theElement, p->next);

    listSize++;
}

template<class T>
void CircularListWithHeader<T>::output(ostream &out) const {
    for (ChainNode<T>* current = headerNode->next; current != headerNode; current = current->next)
        out << current->element << " ";
}

template<class T>
ostream & operator<<(ostream &out, const CircularListWithHeader<T>& x) {
    x.output(out);
    return out;
}

#endif //ALGORITHMS_IN_CPP_CIRCULARLISTWITHHEADER_H
