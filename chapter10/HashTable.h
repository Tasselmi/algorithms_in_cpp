//
// Created by Tasselmi liang on 2020/8/9.
//

#ifndef ALGORITHMS_IN_CPP_HASHTABLE_H
#define ALGORITHMS_IN_CPP_HASHTABLE_H

#include <iostream>
#include "hash.h"
#include "../exception/myExceptions.h"

using std::pair;
using std::ostream;

template<class K, class E>
class HashTable {
    protected:
        int search(const K& theKey) const ;
        pair<const K, E>** table;
        hash<K> hash;
        int dSize;
        int divisor;

    public:
        HashTable(int theDivisor = 11);
        ~HashTable();
        bool empty() const ;
        int size() const;
        pair<const K, E>* find(const K& theKey) const ;
        void insert(const pair<const K, E>& thePair);
        void output(std::ostream& out) const ;
};

template<class K, class E>
int HashTable<K, E>::search(const K &theKey) const {
    int i = (int) hash(theKey) % divisor;
    int j = i;

    do {
        if (table[j] == nullptr || table[j]->first == theKey) {
            return j;
        }
        j = (j + 1) % divisor;
    } while (j != i);

    return j;
}

template<class K, class E>
HashTable<K, E>::HashTable(int theDivisor) {
    divisor = theDivisor;
    dSize = 0;

    table = new pair<const K, E>* [divisor]; //指针数组
    for (int i = 0; i < divisor; ++i) {
        table[i] = nullptr;
    }
}

template<class K, class E>
HashTable<K, E>::~HashTable() {
    delete [] table;
}

template<class K, class E>
bool HashTable<K, E>::empty() const {
    return dSize == 0;
}

template<class K, class E>
int HashTable<K, E>::size() const {
    return dSize;
}

template<class K, class E>
pair<const K, E> *HashTable<K, E>::find(const K &theKey) const {
    int b = search(theKey);

    if (table[b] == nullptr || table[b]->first != theKey) {
        return nullptr;
    } else
        return table[b];
}

template<class K, class E>
void HashTable<K, E>::insert(const pair<const K, E>& thePair) {
    int b = search(thePair.first);

    if (table[b] == nullptr) {
        table[b] = new pair<const K, E>(thePair);
        dSize++;
    } else {
        if (table[b]->first == thePair.first) {
            table[b]->second = thePair.second; //后插入的覆盖先插入的
        } else {
            throw HashTableFull(); //没有空位置，也没有key相等的位置
        }
    }
}

template<class K, class E>
void HashTable<K, E>::output(std::ostream &out) const {
    for (int i = 0; i < divisor; i++) {
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else
            cout << table[i]->first << " " << table[i]->second << endl;
    }
}

template <class K, class E>
ostream& operator<<(ostream& out, const HashTable<K, E>& x) {
    x.output(out);
    return out;
}

#endif //ALGORITHMS_IN_CPP_HASHTABLE_H
