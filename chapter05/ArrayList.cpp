////
//// Created by Tasselmi liang on 2020/6/15.
////
//
//#include "ArrayList.h"
//#include "Iterator.h"
//#include "../chapter08/ArrayStack.h"
//#include "../chapter08/stackApplication.h"
//#include <ostream>
//#include <algorithm>
//#include <numeric>
//using namespace std;
//
//int main()
//{
//    auto arr = ArrayList<int>(10);
//    ArrayList<char> c(100);
//    ArrayList<long long> ll;
//
//    arr.insert(0, 10);
//    arr.insert(0, 20);
//    cout << arr << endl;
//
//    auto be = arr.begin();
//    auto en = arr.end();
//    cout << accumulate(be, en, 0) << endl;
//
//    cout << "---------------" << endl;
//
//    int* a = new int [5];
//    a[0] = 1;
//    a[1] = 2;
//    a[2] = 3;
//    a[3] = 4;
//    a[4] = 5;
//    int size = 4;
//    cout << "elem: " << a[--size] << endl;
//    cout << size << endl;
//    cout << "elem: " << a[size--] << endl;
//    cout << size << endl;
//
//    cout << "---------------" << endl;
//
//    int x[3] = {0, 1, 2};
//    for (int* y = x; y != x + 3; y++) {
//        cout << *y << " ";
//    }
//    cout << endl;
//
//    cout << "-------ArrayStack--------" << endl;
//
//    auto as = ArrayStack<int>(100);
//    as.push(10);
//    as.push(20);
//    cout << as.size() << " " << as.top() << endl;
//
//    cout << "--------parenthesisMatching-------" << endl;
//
//    return 0;
//}
