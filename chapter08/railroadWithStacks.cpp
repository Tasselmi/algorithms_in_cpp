//
// Created by Tasselmi liang on 2020/6/21.
//

#include "ArrayStack.h"
#include <iostream>
using namespace std;

ArrayStack<int>* track; // 轨道数组
int numberOfCars;
int numberOfTracks; //缓冲轨道数
int smallestCar;
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
    int bestTrack = 0, bestTop = numberOfCars + 1;

    for (int i = 1; i <= numberOfTracks; ++i) {
        cout << "\n" << "c: " << c << "; i: " << i;
        if (!track[i].empty()) {
            int topCar = track[i].top();
            cout << "; topCar: " << topCar << "; bestTop: " << bestTop;
            if (c < topCar && topCar < bestTop) {
                bestTop = topCar;
                bestTrack = i;
            }
        } else if (bestTrack == 0) {
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

int main()
{
    int p[] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
    cout << "Input permutation is 369247185" << endl;
    railroad(p, 9, 3);
    return 0;
}