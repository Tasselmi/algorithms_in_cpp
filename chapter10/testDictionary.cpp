//
// Created by Tasselmi liang on 2020/6/29.
//
#include "SortedChain.h"
#include <iostream>
#include "roaring.hh"
#include "roaring.c"
#include <boost/lambda/lambda.hpp>

int main()
{
    using pis = pair<int, string>;
    SortedChain<int, string> sc;
    sc.insert(pis(1, "liang"));
    sc.insert(pis(100, "fan"));
    sc.insert(pis(10, "ni"));

    sc.output(cout);
    cout << "\n" << sc.size() << endl;

    Roaring r1;
    for (uint32_t i = 100; i < 1000; i++) {
        r1.add(i);
    }
    std::cout << "cardinality = " << r1.cardinality() << std::endl;

    Roaring64Map r2;
    for (uint64_t i = 18000000000000000100ull; i < 18000000000000001000ull; i++) {
        r2.add(i);
    }
    std::cout << "cardinality = " << r2.cardinality() << std::endl;

    cout << "size in bytes: " << r2.getSizeInBytes() << endl;

    return 0;
}