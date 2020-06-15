//
// Created by Tasselmi liang on 2020/5/25.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
using namespace std;

int product(int a[], int n)
{
    return accumulate(a, a+n, 1, multiplies<>());
}

//int main()
//{
//    int arr[] = {1, 3, 5};
//    cout << product(arr, 3) << endl;
//}