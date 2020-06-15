//
// Created by Tasselmi liang on 2020/6/15.
//

#ifndef ALGORITHMS_IN_CPP_ARRAYLIST_H
#define ALGORITHMS_IN_CPP_ARRAYLIST_H

#include <ostream>
#include <sstream>
#include <algorithm>
#include "LinearList.h"
#include "../exception/myExceptions.h"
#include "changeLength1D.h"
using namespace std;

template <typename T>
class ArrayList : public LinearList<T>
{
protected:
    void checkIndex(int theIndex) const ;
    T* element;
    int arrayLength;
    int listSize;

public:
    explicit ArrayList(int initialCapacity = 10);
    ArrayList(const ArrayList<T>& theList);
    ~ArrayList();

    bool empty() const override;
    int size() const override;
    T &get(int theIndex) const override;
    int indexOf(const T &theElement) const override;
    void erase(int theIndex) override;
    void insert(int theIndex, const T &theElement) override;
    void output(ostream &out) const override;

    int capacity() const;
};

template<typename T>
void ArrayList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex <<  " size = " << listSize;
        throw IllegalParameterValue(s.str());
    }
}

template<typename T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &theList) {
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete [] element;
}

template<typename T>
bool ArrayList<T>::empty() const {
    return listSize == 0;
}

template<typename T>
int ArrayList<T>::size() const {
    return listSize;
}

template<typename T>
T &ArrayList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

template<typename T>
int ArrayList<T>::indexOf(const T &theElement) const {
    //指针算术
    int idx = int(find(element, element + listSize, theElement) - element);
    if (idx == listSize)
        return -1;
    else return idx;
}

template<typename T>
void ArrayList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    //覆盖掉第 theIndex 个元素的内存
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    //释放掉最后一个元素
    element[--listSize].~T();
}

template<typename T>
void ArrayList<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex <<  " size = " << listSize;
        throw IllegalParameterValue(s.str());
    }

    if (listSize == arrayLength)
    {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}

template<typename T>
void ArrayList<T>::output(ostream& out) const {
    copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}

template<typename T>
int ArrayList<T>::capacity() const {
    return arrayLength;
}

template<typename T>
ostream & operator<<(ostream& out, const ArrayList<T>& x)
{
    x.output(out);
    return out;
}

#endif //ALGORITHMS_IN_CPP_ARRAYLIST_H
