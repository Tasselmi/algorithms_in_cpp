//
// Created by Tasselmi liang on 2020/5/24.
//
#include <iostream>
using namespace std;

//递归解法
int factorial(int n)
{
    if (n <= 1) return 1;
    else return n * factorial(n-1);
}

//非递归解法
int factorial_(int n)
{
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

//int main()
//{
//    int m = factorial(10);
//    cout << m << endl;
//
//    int m2 = factorial_(10);
//    cout << m2 << endl;
//}