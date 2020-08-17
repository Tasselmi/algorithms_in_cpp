//
// Created by Tasselmi liang on 2020/8/18.
// https://segmentfault.com/a/1190000011425787

#include <fstream>
#include <iostream>
#include "HashChains.h"

using std::pair;
using std::ifstream;
using std::ofstream;
using pairType = pair<const long, int>;

const uint16_t
    DIVISOR = 4099,
    MAX_CODES = 4096,
    BYTE_SIZE = 8,
    EXCESS = 4,
    ALPHA = 256,
    MASK1 = 255,
    MASK2 = 15;

int leftOver;
bool bitsLeftOver = false;
ifstream in;
ofstream out;

void setFile(int argc, char * argv[]) {

}

void output(long code);

void compress() {
    HashChains<long, int> h(DIVISOR);
    for (int i = 0; i < ALPHA; ++i) {
        h.insert(pairType(i, i));
    }
    int codesUsed = ALPHA;

    int c = in.get();
    if (c != EOF) {
        long pcode = c;

        while ((c = in.get()) != EOF) {
            long theKey = (pcode << BYTE_SIZE) + c;
            pairType* thePair = h.find(theKey);
            if (thePair == nullptr) {
                output(pcode);
                if (codesUsed < MAX_CODES) {
                    h.insert(pairType((pcode << BYTE_SIZE) | c, codesUsed++)); //按位或
                }
                pcode = c;
            } else {
                pcode = thePair->second;
            }
        }

        output(pcode);
        if (bitsLeftOver) {
            out.put(leftOver << EXCESS);
        }
    }

    out.close();
    in.close();
}

int main() {
    return 0;
}
