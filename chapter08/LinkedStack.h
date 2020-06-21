//
// Created by Tasselmi liang on 2020/6/21.
//

#ifndef ALGORITHMS_IN_CPP_LINKEDSTACK_H
#define ALGORITHMS_IN_CPP_LINKEDSTACK_H

#include "Stack.h"
#include "../chapter06/ChainNode.h"
#include "../exception/myExceptions.h"

template<class T>
class LinkedStack : public Stack<T>
{
private:
    ChainNode<T>* stackTop;
    int stackSize;

public:
    explicit LinkedStack(int initialCapacity = 10);
    ~LinkedStack();
    bool empty() const override;
    int size() override;
    T &top() override;
    void pop() override;
    void push(const T &theElement) override;
};

template<class T>
LinkedStack<T>::LinkedStack(int initialCapacity) {
    stackTop = nullptr;
    stackSize = 0;
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    while (stackTop != nullptr) {
        ChainNode<T>* nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template<class T>
bool LinkedStack<T>::empty() const {
    return stackSize == 0;
}

template<class T>
int LinkedStack<T>::size() {
    return stackSize;
}

template<class T>
T &LinkedStack<T>::top() {
    if (stackSize == 0) throw StackEmpty();
    return stackTop->element;
}

template<class T>
void LinkedStack<T>::pop() {
    if (stackSize == 0) throw StackEmpty();

    ChainNode<T>* nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize--;
}

template<class T>
void LinkedStack<T>::push(const T &theElement) {
    stackTop = new ChainNode<T>(theElement, stackTop);
    stackSize++;
}


#endif //ALGORITHMS_IN_CPP_LINKEDSTACK_H
