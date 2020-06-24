//
// Created by Tasselmi liang on 2020/6/24.
//

#ifndef ALGORITHMS_IN_CPP_QUEUE_H
#define ALGORITHMS_IN_CPP_QUEUE_H

template<typename T>
class Queue
{
public:
    virtual ~Queue() { };
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& front() = 0;
    virtual T& back() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0;
};

#endif //ALGORITHMS_IN_CPP_QUEUE_H
