//
// Created by Tasselmi liang on 2020/6/21.
//

#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

//括号匹配
void printMatchedPairs(string expr)
{
    ArrayStack<int> s;
    int length = int(expr.size());

    for (int i = 0; i < length; ++i) {
        if (expr.at(i) == '(') s.push(i);
        else if (expr.at(i) == ')') {
            try {
                cout << s.top() << ' ' << i << endl;
                s.pop();
            } catch (StackEmpty&) {
                cout << "no match for right parenthesis" << " at " << i << endl;
            }
        }
    }

    while (!s.empty()) {
        cout << "no match for left parenthesis at " << s.top() << endl;
        s.pop();
    }
}

//int main()
//{
//    printMatchedPairs("(a * (b + c) + 1)");
//    return 0;
//}