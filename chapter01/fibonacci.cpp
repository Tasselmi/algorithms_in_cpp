//
// Created by Tasselmi liang on 2020/5/24.
// page28 practice 20
// the n-th fibonacci number, the 1st is 1
//
#include <iostream>
using namespace std;

unsigned long long fibonacci(int n)
{
    if (n <= 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

//better solution
unsigned long long fibonacci_(int n)
{
    unsigned long long first = 1, second = 1, third = 1;
    for (int i = 3; i <= n; ++i)
    {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

//int main()
//{
//    cout << fibonacci(1) << endl;
//    cout << fibonacci(2) << endl;
//    cout << fibonacci(3) << endl;
//    cout << fibonacci(4) << endl;
//    cout << fibonacci(5) << endl;
//    cout << fibonacci(6) << endl;
//    cout << fibonacci(7) << endl;
//    cout << fibonacci(8) << endl;
//    cout << fibonacci(9) << endl;
//    cout << fibonacci(10) << endl;
//    //递归的方式数据大的时候算不动，没有scala那样尾部递归优化
//    //cout << fibonacci(1000) << endl;
//
//    cout << fibonacci_(1) << endl;
//    cout << fibonacci_(2) << endl;
//    cout << fibonacci_(3) << endl;
//    cout << fibonacci_(4) << endl;
//    cout << fibonacci_(5) << endl;
//    cout << fibonacci_(6) << endl;
//    cout << fibonacci_(7) << endl;
//    cout << fibonacci_(8) << endl;
//    cout << fibonacci_(9) << endl;
//    cout << fibonacci_(10) << endl;
//    cout << fibonacci_(1000) << endl;
//    cout << fibonacci_(10000) << endl;
//}