//
// Created by Tasselmi liang on 2020/8/18.
//

#ifndef ALGORITHMS_IN_CPP_HASHCHAINS_H
#define ALGORITHMS_IN_CPP_HASHCHAINS_H

#include <iostream>
#include "hash.h"  // mapping functions from K to nonnegative integer
#include "Dictionary.h"
#include "SortedChain.h"

//using namespace std;
using std::cout;
using std::endl;

template<class K, class E>
class HashChains : public Dictionary<K,E>
{
public:
    explicit HashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // allocate and initialize hash table array
        table = new SortedChain<K,E> [divisor];
    }

    ~HashChains(){delete [] table;}

    bool empty() const {return dSize == 0;}
    int size() const {return dSize;}

    pair<const K, E>* find(const K& theKey) const
    {return table[hash(theKey) % divisor].find(theKey);}

    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int) hash(thePair.first) % divisor;
        int homeSize = table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if (table[homeBucket].size() > homeSize)
            dSize++;
    }

    void erase(const K& theKey)
    {table[hash(theKey) % divisor].erase(theKey);}

    void output(ostream& out) const
    {
        for (int i = 0; i < divisor; i++)
            if (table[i].size() == 0)
                cout << "NULL" << endl;
            else
                cout << table[i] << endl;
    }


protected:
    SortedChain<K, E>* table;  // hash table
    hash<K> hash;              // maps type K to nonnegative integer
    int dSize;                 // number of elements in list
    int divisor;               // hash function divisor
};


// overload <<
template <class K, class E>
ostream& operator<<(ostream& out, const HashChains<K,E>& x)
{x.output(out); return out;}

#endif //ALGORITHMS_IN_CPP_HASHCHAINS_H
