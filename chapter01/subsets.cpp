//
// Created by Tasselmi liang on 2020/5/24.
// page29 practice 25
// subsets of collections
//

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void subsets(T arr[], int flags[], int begin, int size)
{
    cout << "---------------------------" << endl;
    cout << "begin: " << begin << "; size: " << size << endl;
    if (begin == size)
    {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            if (flags[i] == 1) cout << arr[i];
        }
        cout << "]" << endl;
        return;
    }

    flags[begin] = 0;
    cout << "flags: ";
    copy(flags, flags+size, ostream_iterator<int>(cout, ""));
    cout << endl;

    cout << "subsets-a invoke: " << begin + 1 << "|" << size << endl;
    subsets(arr, flags, begin+1, size);
    cout << "subsets-a return with begin: " << begin << endl;

    flags[begin] = 1;
    cout << "flags: ";
    copy(flags, flags+size, ostream_iterator<int>(cout, ""));
    cout << endl;

    cout << "subsets-b invoke : " << begin + 1 << "|" << size << endl;
    subsets(arr, flags, begin+1, size);
    cout << "subsets-b return with begin: " << begin << endl;
}


//int main()
//{
//    int mrk[4] = {9, 9, 9, 9};
//    char c[] = {'a', 'b', 'c', 'd'};
//    subsets(c, mrk, 0, 4);
//}


//使用滑动窗口是错误的，因为滑动窗口是有序的，但是这里子集不一定有序，会漏掉一些情况
//template <typename T>
//void subsets(T arr[], int len)
//{
//    cout << "[]" << endl;
//
//    int windowSize, begin;
//    for (windowSize = 1; windowSize <= len; windowSize++)
//    {
//        for (begin = 0; begin <= len - windowSize; begin++)
//        {
//            cout << "[";
//            copy(arr+begin, arr+begin+windowSize, ostream_iterator<T>(cout, ""));
//            cout << "]";
//            cout << endl;
//
//            if (begin >= 1 && begin + windowSize < len)
//            {
//                cout << "[";
//                copy(arr, arr+begin, ostream_iterator<T>(cout, ""));
//                copy(arr+begin+windowSize, arr+len, ostream_iterator<T>(cout, ""));
//                cout << "]";
//                cout << endl;
//            }
//        }
//    }
//}
