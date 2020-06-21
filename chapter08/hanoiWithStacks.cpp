//
// Created by Tasselmi liang on 2020/6/21.
//

#include "ArrayStack.h"

ArrayStack<int> tower[4];

void moveAndShow(int n, int x, int y, int z)
{
    if (n > 0) {
        moveAndShow(n - 1, x, z, y);
        int d = tower[x].top();
        tower[x].pop();
        tower[y].push(d);
        cout << "move disk " << d << " from tower " << x << " to top of tower " << y << endl;
        moveAndShow(n - 1, z, y, x);
    }
}

void towersOfHanoi(int n)
{
    for (int i = n; i > 0; i--) {
        tower[1].push(i);
    }

    moveAndShow(n, 1, 2, 3);
}

//int main()
//{
//    towersOfHanoi(1);
//    return 0;
//}