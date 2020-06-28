//
// Created by Tasselmi liang on 2020/6/28.
//

#ifndef ALGORITHMS_IN_CPP_LINKEDQUEUE_H
#define ALGORITHMS_IN_CPP_LINKEDQUEUE_H

#include "Queue.h"
#include "../chapter06/ChainNode.h"
#include "../exception/myExceptions.h"
#include <sstream>

template<typename T>
class LinkedQueue : public Queue<T>
{
private:
    ChainNode<T>* queueFront;
    ChainNode<T>* queueBack;
    int queueSize;

public:
    explicit LinkedQueue(int initialCapacity = 10);
    ~LinkedQueue();
    bool empty() const override;
    int size() const override;
    T &front() override;
    T &back() override;
    void pop() override;
    void push(const T &theElement) override;
};

template<typename T>
LinkedQueue<T>::LinkedQueue(int initialCapacity) {
    queueFront = nullptr;
    queueSize = 0;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (queueFront != nullptr) {
        auto nextNode = queueFront->next;
        delete queueFront;
        queueFront = nextNode;
    }
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return queueSize == 0;
}

template<typename T>
int LinkedQueue<T>::size() const {
    return queueSize;
}

template<typename T>
T &LinkedQueue<T>::front() {
    if (queueSize == 0) throw QueueEmpty();
    return queueFront->element;
}

template<typename T>
T &LinkedQueue<T>::back() {
    if (queueSize == 0) throw QueueEmpty();
    return queueBack->element;
}

template<typename T>
void LinkedQueue<T>::pop() {
    if (queueFront == nullptr) throw QueueEmpty();
    auto nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
    queueSize--;
}

template<typename T>
void LinkedQueue<T>::push(const T &theElement) {
    auto newNode = new ChainNode<T>(theElement, nullptr);
    if (queueSize == 0)
        queueFront = newNode;
    else
        queueBack->next = newNode;

    queueBack = newNode;
    queueSize++;
}

#endif //ALGORITHMS_IN_CPP_LINKEDQUEUE_H
