//
// Created by Tasselmi liang on 2020/6/24.
//

#ifndef ALGORITHMS_IN_CPP_ARRAYQUEUE_H
#define ALGORITHMS_IN_CPP_ARRAYQUEUE_H

#include <sstream>
#include "../exception/myExceptions.h"
#include "Queue.h"
using namespace std;

template<typename T>
class ArrayQueue : public Queue<T>
{
private:
    int theFront;
    int theBack;
    int arrayLength;
    T *queue;

public:
    ArrayQueue(int initialCapacity = 10);
    ~ArrayQueue();
    bool empty() const override;
    int size() const override;
    T &front() override;
    T &back() override;
    void pop() override;
    void push(const T &theElement) override;
};

template<typename T>
ArrayQueue<T>::ArrayQueue(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "initial capacity = " << initialCapacity << " must be > 0 ";
        throw IllegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    queue = new T[arrayLength]; //new是在堆上分配内存，一定要手动释放
    theFront = 0;
    theBack = 0;
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete [] queue;
}

template<typename T>
bool ArrayQueue<T>::empty() const {
    return theFront == theBack;
}

template<typename T>
int ArrayQueue<T>::size() const {
    return (theBack - theFront + arrayLength) % arrayLength;
}

template<typename T>
T &ArrayQueue<T>::front() {
    if (theFront == theBack)
        throw QueueEmpty();
    return queue[(theFront + 1) % arrayLength];
}

template<typename T>
T &ArrayQueue<T>::back() {
    if (theFront == theBack)
        throw QueueEmpty();
    return queue[theBack];
}

template<typename T>
void ArrayQueue<T>::pop() {
    if (theFront == theBack)
        throw QueueEmpty();
    //theFront本身是一个空占位，因此移动到下一位即可
    //首个数据项实际存储的就是在下一位，因此直接把移动后的位置上的数据进行析构
    theFront = (theFront + 1) % arrayLength;
    queue[theFront].~T();
}

template<typename T>
void ArrayQueue<T>::push(const T &theElement) {
    if ((theBack + 1) % arrayLength == theFront) {

    }
}

#endif //ALGORITHMS_IN_CPP_ARRAYQUEUE_H
