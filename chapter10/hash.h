//
// Created by Tasselmi liang on 2020/8/9.
//

#ifndef ALGORITHMS_IN_CPP_HASH_H
#define ALGORITHMS_IN_CPP_HASH_H

#include <iostream>
#include <string>

template<typename K> class hash;

template<>
class hash<std::string> {
public:
    size_t operator()(const std::string theKey) const {
        unsigned long hashValue = 0;
        int length = (int) theKey.length();
        for (int i = 0; i < length; ++i) {
            hashValue = 5 * hashValue + theKey.at(i);
        }

        return size_t(hashValue);
    }
};

template<>
class hash<int> {
public:
    size_t operator()(const int theKey) const {
        return size_t(theKey);
    }
};

template<>
class hash<long> {
public:
    size_t operator()(const long theKey) const {
        return size_t(theKey);
    }
};


#endif //ALGORITHMS_IN_CPP_HASH_H
