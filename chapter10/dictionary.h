//
// Created by Tasselmi liang on 2020/4/19.
//

#ifndef ALGORITHMS_IN_CPP_DICTIONARY_H
#define ALGORITHMS_IN_CPP_DICTIONARY_H

#include <utility>
using std::pair;

template <typename K, typename E>
class dictionary
{
public:
    virtual ~dictionary() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual pair<const K, E>* find(const K&) const = 0;
    virtual void erase(const K&) = 0;
    virtual void insert(const pair<const K, E>&) = 0;
};

#endif //ALGORITHMS_IN_CPP_DICTIONARY_H
