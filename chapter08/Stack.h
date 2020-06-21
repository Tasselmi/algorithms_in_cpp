//
// Created by Tasselmi liang on 2020/6/21.
//

#ifndef ALGORITHMS_IN_CPP_STACK_H
#define ALGORITHMS_IN_CPP_STACK_H

template<class T>
class Stack
{
public:
    virtual ~Stack() = default;
    virtual bool empty() const = 0;
    virtual int size() = 0;
    virtual T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0;
};

#endif //ALGORITHMS_IN_CPP_STACK_H
