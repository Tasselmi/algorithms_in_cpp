//
// Created by Apple on 2020/6/23.
//

#include "ArrayStack.h"
#include <utility>
#include <array>

int main()
{
    const int n = 22; //22个元素
    const int r = 11; //11个数对

    using pint = std::pair<int, int>;
    array<pint, r> pairs; //11个数对
    pairs[0] = pint(1, 5);
    pairs[1] = pint(1, 6);
    pairs[2] = pint(3, 7);
    pairs[3] = pint(4, 8);
    pairs[4] = pint(5, 2);
    pairs[5] = pint(6, 5);
    pairs[6] = pint(4, 9);
    pairs[7] = pint(9, 7);
    pairs[8] = pint(7, 8);
    pairs[9] = pint(3, 4);
    pairs[10] = pint(6, 2);

    int theMax = 0;  //所有元素的最大值
    auto list = new ArrayStack<int>[n + 1]; //下标为0的 ArrayStack 不使用，从1开始使用
    for (auto x : pairs) {
        int s = x.first, t = x.second;
        std::cout << s << ", " << t << endl;
        list[s].push(t);
        list[t].push(s);

        if (s > theMax) { theMax = s; }
        if (t > theMax) { theMax = t; }
    }
    std::cout << "theMax: " << theMax << endl;
    std::cout << "\n------------------\n";

    for (int k = 1; k <= theMax; ++k) {
        std::cout << k << "th stack: ";
        while (!list[k].empty()) {
            std::cout << list[k].top() << " ";
            list[k].pop();
        }
        std::cout << endl;
    }
    std::cout << "\n------------------\n";

    //前面为了打印每个栈，将栈遍历清空了，因此需要重新插入1次
    for (auto x : pairs) {
        int s = x.first, t = x.second;
        list[s].push(t);
        list[t].push(s);
    }

    //unprocessedList存储的是尚未被检索到的栈的编号
    ArrayStack<int> unprocessedList;
    // out的作用其实是一个标志位的作用，有输出过的不再重复输出
    array<bool, n + 1> out = {true, false}; //这个地方也可以不初始化
    for (auto &x : out) { x = false; } //引用类型可以修改源值

    for (int i = 1; i <= theMax; ++i) {
        if (!out[i]) {
            std::cout << i << " ";
            out[i] = true;
            unprocessedList.push(i);

            while (!unprocessedList.empty()) { //第一层，每个编号为1th~9th的栈被处理到
                int j = unprocessedList.top();
                unprocessedList.pop();
                while (!list[j].empty()) { //第二层，循环穷尽栈内每个元素
                    int q = list[j].top();
                    list[j].pop();
                    if (!out[q]) {
                        std::cout << q << " ";
                        out[q] = true;
                        //q是栈内的元素（已被处理），但是第q个栈还没处理到，所以需要添加到栈编号中去
                        //虽然最外层的 i++ 循环中也能确保第 i th 个栈被处理到，但是这里是寻找等价类
                        //因此所有的相关元素必须在一次i循环体中处理完毕，否则元素就错误的划分到另外的等价类中去了
                        unprocessedList.push(q);
                    }
                }
            }

            std::cout << endl;
        }
    }

    return 0;
}