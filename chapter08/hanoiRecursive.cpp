//
// Created by Tasselmi liang on 2020/6/21.
//

#include <iostream>
using namespace std;

void towerOfHanoi(int n, int x, int y, int z)
{
    if (n > 0) {
        towerOfHanoi(n - 1, x, z, y);
        cout << "move top disk from tower " << x << " to top of tower " << y << endl;
        towerOfHanoi(n - 1, z, y, x);
    }
}

//int main()
//{
//    towerOfHanoi(3, 1, 2, 3);
//}