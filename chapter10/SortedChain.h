//
// Created by Tasselmi liang on 2020/6/28.
// implements dictionary using linked-list
//

#ifndef ALGORITHMS_IN_CPP_SORTEDCHAIN_H
#define ALGORITHMS_IN_CPP_SORTEDCHAIN_H

#include "iostream"
#include "Dictionary.h"
#include "PairNode.h"
#include <iostream>
//using namespace std;
using std::ostream;

template<typename K, typename V>
class SortedChain : public Dictionary<K, V>
{
protected:
    PairNode<K, V>* firstNode;
    int dSize;

public:
    SortedChain();
    ~SortedChain();
    bool empty() const override;
    int size() const override;
    pair<const K, V> *find(const K &theKey) const override;
    void erase(const K &theKey) override;
    void insert(const pair<const K, V> &thePair) override;
    void output(ostream& out) const;
};

template<typename K, typename V>
SortedChain<K, V>::SortedChain() {
    firstNode = nullptr;
    dSize = 0;
}

template<typename K, typename V>
SortedChain<K, V>::~SortedChain() {
    while (firstNode != nullptr) {
        auto nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<typename K, typename V>
bool SortedChain<K, V>::empty() const {
    return dSize == 0;
}

template<typename K, typename V>
int SortedChain<K, V>::size() const {
    return dSize;
}

template<typename K, typename V>
pair<const K, V> *SortedChain<K, V>::find(const K &theKey) const {
    PairNode<K, V> * currentNode = firstNode;

    while (firstNode != nullptr && currentNode->element.first != theKey)
        currentNode = currentNode->next;

    if (currentNode != nullptr && currentNode->element.first == theKey)
        return &currentNode->element;

    return nullptr;
}

template<typename K, typename V>
void SortedChain<K, V>::erase(const K &theKey) {
    PairNode<K, V> *p = firstNode, *tp = nullptr;

    while  (p != nullptr && p->element.first < theKey) {
        tp = p;
        p = p->next;
    }

    if (p != nullptr && p->element.first == theKey) {
        if (tp == nullptr) firstNode = p->next;
        else tp->next = p->next;
    }

    delete p;
    dSize--;
}

template<typename K, typename V>
void SortedChain<K, V>::insert(const pair<const K, V> &thePair) {
    PairNode<K, V> *p = firstNode, *tp = nullptr;

    while  (p != nullptr && p->element.first < thePair.first) {
        tp = p;
        p = p->next;
    }

    if (p != nullptr && p->element.first == thePair.first) {
        p->element.second = thePair.second; //key相等，直接替换value
        return;
    }

    auto * newNode = new PairNode<K, V>(thePair, p);
    if (tp == nullptr) firstNode = newNode;
    else tp->next = newNode;

    dSize++;
}

template<class K, class V>
void SortedChain<K, V>::output(ostream& out) const
{// Insert the chain elements into the stream out.
    for (PairNode<K, V>* currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next)
        out << currentNode->element.first << " "
            << currentNode->element.second << "  ";
}

// overload <<
template <class K, class E>
ostream& operator<<(ostream& out, const SortedChain<K,E>& x) {
    x.output(out);
    return out;
 }

#endif //ALGORITHMS_IN_CPP_SORTEDCHAIN_H
