//
// Created by Apple on 2020/6/22.
//

#include "ArrayStack.h"
#include <iostream>
using namespace std;

/**
 * 开关盒是否可以按照设计进行布线
 * @param net 将针脚编号按照从小到大排列后的 【组标】 数列
 * @param n 针脚个数
 * @return 是否可布线
 */
bool checkBox(const int net[], int n)
{
    auto *s = new ArrayStack<int>(n);

    for (int i = 0; i < n; ++i) {
        if (!s->empty()) {
            if (net[i] == net[s->top()]) { //当前待处理的组标与栈顶组标相等时才能匹配；
                s->pop();
            }
            else s->push(i);
        } else {
            s->push(i);
        }
    }

    if (s->empty()) {
        cout << "switch box is routable" << endl;
        return true;
    } else {
        cout << "switch box is not routable" << endl;
        return false;
    }
}

//int main()
//{
//    //组标数列，两两一组 {1, 2, 3, 4, 5, 6, 7, 8} --> (1, 4) (2, 3) (5, 6) (7, 8)
//    int net[] = {1, 2, 2, 1, 3, 3, 4, 4};
//    checkBox(net, 8);
//
//    //组标数列 {1, 2, 3, 4, 5, 6, 7, 8} --> (1, 8) (2, 5) (3, 6) (4, 7)
//    int net2[] = {1, 2, 3, 4, 2, 3, 4, 1};
//    checkBox(net2, 8);
//
//    //组标数列 {1, 2, 3, 4} --> (1, 3) (2, 4)
//    int net4[] = {1, 2, 1, 2};
//    checkBox(net4, 4);
//    return 0;
//}
