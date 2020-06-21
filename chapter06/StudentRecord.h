//
// Created by Tasselmi liang on 2020/6/20.
//

#ifndef ALGORITHMS_IN_CPP_STUDENTRECORD_H
#define ALGORITHMS_IN_CPP_STUDENTRECORD_H

#include <string>
#include <iostream>
using namespace std;

struct StudentRecord
{
    int score;
    string * name;
    int operator!=(const StudentRecord& x) const { return this->score != x.score; }
    explicit operator int() const { return score; }
};

ostream& operator<<(ostream& out, const StudentRecord& x) {
    out << x.score << ' ' << *(x.name) << endl;
    return out;
}

#endif //ALGORITHMS_IN_CPP_STUDENTRECORD_H
