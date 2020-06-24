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


class IllegalIndex
{
public:
    IllegalIndex(string theMessage = "Illegal index") { message = theMessage; }
    void outputMessage() { cout << message << endl; }
private:
    string message;
};


class IllegalParameterValue : public exception
{
public:
    explicit IllegalParameterValue(string theMessage = "Illegal parameter value") { message = std::move(theMessage); }
    void outputMessage() { cout << message << endl; }

private:
    string message;
};


class StackEmpty : public exception
{
private:
    string message;

public:
    StackEmpty(string msg = "Invalid operation on empty stack") {
        message = msg;
    }
    void outputMessage() {
        cout << message << endl;
    }
};


class QueueEmpty : public exception
{
public:
    QueueEmpty(string theMessage =
    "Invalid operation on empty queue")
    {message = theMessage;}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};


#endif //ALGORITHMS_IN_CPP_MYEXCEPTIONS_H
