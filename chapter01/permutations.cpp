//
// Created by Tasselmi liang on 2020/5/24.
//
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void permutations(T arr[], int k, int m)
{
    cout << "k: " << k << "; m: " << m << endl;
    if (k == m)
    {
        copy(arr, arr+m+1, ostream_iterator<T>(cout, ""));
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; ++i)
        {
            //cout << "k: " << k << "; i: " << i << "; m: " << m << endl;
            cout << "i: " << i << endl;
            swap(arr[k], arr[i]);
            permutations(arr, k+1, m);
            swap(arr[k], arr[i]);
        }
    }
}

template <class T>
void permutationsSTL(T arr[], int k, int n)
{
    do {
        copy(arr, arr+n+1, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(arr, arr+n+1));
}
//
//int main()
//{
//    char a[] = {'1', '2', '3', '4'};
//
////    cout << "The permutations of 1 are" << endl;
////    permutations(a, 0, 0);
////
////    cout << "The permutations of 12 are" << endl;
////    permutations(a, 0, 1);
////
////    cout << "The permutations of 123 are" << endl;
////    permutations(a, 0, 2);
////
////    cout << "The permutations of 1234 are" << endl;
////    permutations(a, 0, 3);
//
//    permutationsSTL(a, 0, 2);
//    return 0;
//}