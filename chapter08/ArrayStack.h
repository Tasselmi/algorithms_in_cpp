//
// Created by Tasselmi liang on 2020/6/21.
//

#ifndef ALGORITHMS_IN_CPP_ARRAYSTACK_H
#define ALGORITHMS_IN_CPP_ARRAYSTACK_H

#include <sstream>
#include "../exception/myExceptions.h"
#include "Stack.h"
#include "../chapter05/changeLength1D.h"
using namespace std;

template<class T>
class ArrayStack : public Stack<T>
{
private:
    int stackTop;
    int arrayLength;
    T* stack;

public:
    explicit ArrayStack(int initialCapacity = 10);
    ~ArrayStack();
    bool empty() const override;
    int size() override;
    T &top() override;
    void pop() override;
    void push(const T &theElement) override;
};

template<class T>
ArrayStack<T>::ArrayStack(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "initial capacity = " << initialCapacity << " must be > 0 ";
        throw IllegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    stack = new T[initialCapacity];
    stackTop = -1;
}

template<class T>
ArrayStack<T>::~ArrayStack() {
    delete [] stack;
}

template<class T>
bool ArrayStack<T>::empty() const {
    return stackTop == -1;
}

template<class T>
int ArrayStack<T>::size() {
    return stackTop + 1;
}

template<class T>
T &ArrayStack<T>::top() {
    if (stackTop == -1) throw StackEmpty();
    else return stack[stackTop];
}

template<class T>
void ArrayStack<T>::pop() {
    if (stackTop == -1) throw StackEmpty();
    else stack[stackTop--].~T();
}

template<class T>
void ArrayStack<T>::push(const T &theElement) {
    if (stackTop == arrayLength - 1) {  // stack is full
        changeLength1D(stack, arrayLength, arrayLength * 2);
        arrayLength *= 2;
    } else
        stack[++stackTop] = theElement;
}

#endif //ALGORITHMS_IN_CPP_ARRAYSTACK_H
