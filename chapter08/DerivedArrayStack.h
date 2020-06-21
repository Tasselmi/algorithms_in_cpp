//
// Created by Tasselmi liang on 2020/6/21.
//

#ifndef ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H
#define ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H

#include "../chapter05/ArrayList.h"
#include "../exception/myExceptions.h"
#include "Stack.h"

template<class T>
class DerivedArrayStack : private ArrayList<T>, public Stack<T>
{
public:
    explicit DerivedArrayStack(int initialCapacity = 10) : ArrayList<T>(initialCapacity) { }

    bool empty() const override {
        return ArrayList<T>::empty();
    }

    int size() override {
        return ArrayList<T>::size();
    }

    T &top() override {
//        if (ArrayList<T>::empty())
//            throw StackEmpty();
//        return this->get(size() - 1);
        try {
            return this->get(size() - 1);
        } catch (IllegalIndex&) {
            throw StackEmpty();
        }
    }

    void pop() override {
//        if (ArrayList<T>::empty())
//            throw StackEmpty();
//        this->erase(size() - 1);
        try {
            this->erase(size() - 1);
        } catch (IllegalIndex&) {
            throw StackEmpty();
        }
    }

    void push(const T &theElement) override {
        this->insert(size(), theElement);
    }
};



#endif //ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H
