//
// Created by Tasselmi liang on 2020/6/16.
//

#ifndef ALGORITHMS_IN_CPP_VECTORLIST_H
#define ALGORITHMS_IN_CPP_VECTORLIST_H

#include "LinearList.h"
#include <vector>
#include <sstream>
using namespace std;

template <typename T>
class VectorList : public LinearList<T>
{
protected:
    void checkIndex(int theIndex) const;
    vector<T>* element;

public:
    explicit VectorList(int initialCapacity = 10);
    VectorList(const VectorList<T>& theList);
    ~VectorList();

    bool empty() const override;
    int size() const override;
    T &get(int theIndex) const override;
    int indexOf(const T &theElement) const override;
    void erase(int theIndex) override;
    void insert(int theIndex, const T &theElement) override;
    void output(ostream &out) const override;

    int capacity() const;

    typedef typename vector<T>::iterator iter;
    iter begin() { return element->begin(); }
    iter end() { element->end(); }
};

template<typename T>
void VectorList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= size()) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalParameterValue(s.str());
    }
}

template<typename T>
VectorList<T>::VectorList(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }
    element = new vector<T>;
    element->reserve(initialCapacity);
}

template<typename T>
VectorList<T>::VectorList(const VectorList<T> &theList) {
    element = new vector<T>(*theList.element); //指针解引用
}

template<typename T>
VectorList<T>::~VectorList() {
    delete element;
}

template<typename T>
bool VectorList<T>::empty() const {
    return element->empty();
}

template<typename T>
int VectorList<T>::size() const {
    return int(element->size());
}

template<typename T>
T &VectorList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return (*element)[theIndex];
}

template<typename T>
int VectorList<T>::indexOf(const T &theElement) const {
    int idx = int(find(element->begin(), element->end(), theElement) - element->begin());
    if (idx == size()) return -1;
    else return idx;
}

template<typename T>
void VectorList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    element->erase(begin() + theIndex);
}

template<typename T>
void VectorList<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > size()) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalParameterValue(s.str());
    }
    element->insert(element->begin() + theIndex, theElement);
}

template<typename T>
void VectorList<T>::output(ostream &out) const {
    copy(element->begin(), element->end(), ostream_iterator<T>(cout, " "));
}

template <typename T>
ostream& operator<<(ostream& out, const VectorList<T>& x) {
    x.output(out);
    return out;
}

template<typename T>
int VectorList<T>::capacity() const {
    return int(element->capacity());
}

#endif //ALGORITHMS_IN_CPP_VECTORLIST_H
