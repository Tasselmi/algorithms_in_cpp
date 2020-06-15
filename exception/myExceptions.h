//
// Created by Tasselmi liang on 2020/6/15.
//

#ifndef ALGORITHMS_IN_CPP_MYEXCEPTIONS_H
#define ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

#include <string>
#include <iostream>
#include <utility>
#include <exception>
using namespace std;

class IllegalParameterValue : public exception
{
public:
    explicit IllegalParameterValue(string theMessage = "Illegal parameter value") { message = std::move(theMessage); }
    void outputMessage() { cout << message << endl; }

private:
    string message;
};

#endif //ALGORITHMS_IN_CPP_MYEXCEPTIONS_H
