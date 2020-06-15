//
// Created by Tasselmi liang on 2020/6/15.
//

#include "../exception/myExceptions.h"
#include <cmath>
using std::min;

template <typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
    if (newLength < 0)
        throw IllegalParameterValue("new length must be >= 0");
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete [] a;
    a = temp;
}