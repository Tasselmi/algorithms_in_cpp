//
// Created by Tasselmi liang on 2020/6/29.
//
#include "SortedChain.h"

int main()
{
    using pis = pair<int, string>;
    SortedChain<int, string> sc;
    sc.insert(pis(1, "liang"));
    sc.insert(pis(100, "fan"));
    sc.insert(pis(10, "ni"));

    sc.output(cout);
    cout << "\n" << sc.size();
}