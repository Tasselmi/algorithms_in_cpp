//
// Created by Tasselmi liang on 2020/4/19.
//

#ifndef ALGORITHMS_IN_CPP_DICTIONARY_H
#define ALGORITHMS_IN_CPP_DICTIONARY_H

#include <utility>
using std::pair;

template <typename K, typename V>
class Dictionary
{
public:
    virtual ~Dictionary() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual pair<const K, V>* find(const K&) const = 0;
    virtual void erase(const K&) = 0;
    virtual void insert(const pair<const K, V>&) = 0;
};

#endif //ALGORITHMS_IN_CPP_DICTIONARY_H
