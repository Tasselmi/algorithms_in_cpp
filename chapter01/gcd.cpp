//
// Created by Tasselmi liang on 2020/5/24.
// page29 practice 23
// greatest common divisor
//
#include <iostream>
using namespace std;

//欧几里得算法，二数取模
unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

//更相减损术，源自《九章算术》
unsigned int gcd2(unsigned int a, unsigned int b)
{
    unsigned int big, small;
    if (a > b) { big = a; small = b; }
    else { big = b; small = a; }
    if (big == 0 || small == 0 || big == small) return big;
    else return gcd2(big - small, small);
}

//最优算法，利用位运算和更相减损术
unsigned int gcd3(unsigned int a, unsigned int b)
{
    if (a == b || a == 0 || b == 0) return a > b ? a : b;
    else if ((a & 1) == 0 && (b & 1) == 0) return gcd3(a >> 1, b >> 1) << 1;
    else if ((a & 1) == 0 && (b & 1) != 0) return gcd3(a >> 1, b);
    else if ((a & 1) != 0 && (b & 1) == 0) return gcd3(a, b >> 1);
    else
    {
        cout << "a: " << a << ";  b: " << b << endl;
        unsigned int big = a > b ? a : b;
        unsigned int small = a > b ? b : a;
        return gcd3(big - small, small);
    }
}

//int main()
//{
//    cout << gcd(0, 10) << endl;
//    cout << gcd(20, 30) << endl;
//    cout << gcd(112, 42) << endl;
//
//    cout << gcd2(0, 10) << endl;
//    cout << gcd2(20, 30) << endl;
//    cout << gcd2(112, 42) << endl;
//
//    cout << gcd3(0, 10) << endl;
//    cout << gcd3(20, 30) << endl;
//    cout << gcd3(112, 42) << endl;
//    cout << gcd3(30000, 70000) << endl;
//}