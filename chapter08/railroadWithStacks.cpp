//
// Created by Tasselmi liang on 2020/6/21.
//

#include "ArrayStack.h"
#include <iostream>
using namespace std;

ArrayStack<int>* track; // 轨道数组，每个元素为车厢缓冲栈
int numberOfCars; //车辆总数
int numberOfTracks; //缓冲轨道数
int smallestCar; //编号最小的车
int itsTrack; //有最小编号的车厢停靠的那个缓冲轨道

void outputFromHoldingTrack();
bool putInHoldingTrack(int c);

bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
{
    numberOfCars = theNumberOfCars;
    numberOfTracks = theNumberOfTracks;

    track = new ArrayStack<int>[numberOfTracks + 1];
    int nextCarToOutput = 1;
    smallestCar = numberOfCars + 1;

    for (int i = 1; i <= numberOfCars; ++i) {
        if (inputOrder[i] == nextCarToOutput) {
            cout << "move car " << inputOrder[i] << " from input track to output track" << endl;
            nextCarToOutput++;

            while (smallestCar == nextCarToOutput) {
                outputFromHoldingTrack();
                nextCarToOutput++;
            }
        } else {
            if (!putInHoldingTrack(inputOrder[i]))
                return false;
        }
    }

    return true;
}

void outputFromHoldingTrack()
{
    track[itsTrack].pop();
    cout << "move car " << smallestCar << " from holding track" << itsTrack << " to output track" << endl;

    smallestCar = numberOfCars + 2;
    for (int i = 1; i <= numberOfTracks; ++i) {
        if (!track[i].empty() && track[i].top() < smallestCar) {
            smallestCar = track[i].top();
            itsTrack = i;
        }
    }
}

bool putInHoldingTrack(int c)
{
    //track的实际编号是1，2，3，此处令 bestTrack = 0 为初始状态
    //bestTop 记录的是各条轨道中比插入值大的 [顶点中的最小值]
    int bestTrack = 0, bestTop = numberOfCars + 1;

    for (int i = 1; i <= numberOfTracks; ++i) {
        cout << "\n" << "c: " << c << "; i: " << i;
        if (!track[i].empty()) {
            int topCar = track[i].top();
            cout << "; topCar: " << topCar << "; bestTop: " << bestTop;

            //topCar > c是基本条件，因为每条轨道里面的车厢必须都按照从小到大排列（头部小尾部大）
            //topCar < bestTop，必须比bestTop小，插入顶点最小的轨道
            if (topCar > c && topCar < bestTop) {
                bestTop = topCar;
                bestTrack = i;
                cout << "; bestTop-if: " << bestTop << "; bestTrack: " << bestTrack;
            }
        } else if (bestTrack == 0) { //如果 bestTrack 还处于初始状态，那么当前遍历到的首个track即可
            bestTrack = i;
            cout << "; bestTrack: " << bestTrack;
        }
    }
    cout << "\n";
    if (bestTrack == 0) return false;

    track[bestTrack].push(c);
    cout << "Move car " << c << " from input track " << "to holding track " << bestTrack << endl;

    if (c < smallestCar) {
        smallestCar = c;
        itsTrack = bestTrack;
    }

    return true;
}

//int main()
//{
//    int p[] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
//    cout << "Input permutation is 369247185" << endl;
//    railroad(p, 9, 3);
//    return 0;
//}