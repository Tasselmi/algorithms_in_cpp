//
// Created by Tasselmi liang on 2020/6/23.
//

#include <new>
#include "ArrayStack.h"
using namespace std;

struct position
{
    int row;
    int col;
    explicit operator int() const { return row; }
    position(int x, int y) { row = x; col = y; }
    position() = default;
};

//create a two dimensional array
template<typename T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
    try {
        x = new T* [numberOfRows];
        for (int i = 0; i < numberOfRows; ++i) {
            x[i] = new int [numberOfColumns];
        }
        return true;
    } catch (bad_alloc&) {
        return false;
    }
}

int **maze, size;
ArrayStack<position> * path;

void inputMaze()
{
    cout << "enter maze size" << endl;
    cin >> size;
    make2dArray(maze, size + 2, size + 2);
    cout << "Enter maze in row major order" << endl;

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size ; ++j) {
            cin >> maze[i][j];
        }
    }
}

bool findPath()
{
    path = new ArrayStack<position>;

    position offset[4]; //存储顺时针方向移动时每个方向的行和列偏移量
    offset[0].row = 0; offset[0].col = 1; //右
    offset[1].row = 1; offset[1].col = 0; //下
    offset[2].row = 0; offset[2].col = -1; //左
    offset[3].row = -1; offset[3].col = 0; //上

    //外围的障碍墙
    for (int i = 0; i <= size + 1; ++i) {
        maze[0][i] = maze[size + 1][i] = 1; //第一行和最后一行
        maze[i][0] = maze[i][size + 1] = 1; //第一列和最后一列
    }

    position here(1, 1);
    maze[1][1] = 1;
    int option = 0;
    int lastOption = 3;

    while (here.row != size || here.col != size) {
        int r, c;

        while (option <= lastOption) {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) break; //如果找到了下一步的位置，那么停止继续查找
            option++;
        }

        if (option <= lastOption) {
            path->push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 1;
            option = 0;
        } else {
            if (path->empty()) return false;
            position previous = path->top();
            path->pop();
            // next.col - here.col = +1 或 -1
            // 行相等说明之前的一步是左右移动的（前一步option=0或2），那么从其后一步继续移动即可，也即option=1或3
            if (previous.row == here.row) option = 2 + previous.col - here.col;
            //列相等说明之前的一步是上下移动的（前一步option=1或3），那么从其后一步继续移动即可，也即option=2或4
            //option=2 可以继续进行，如果 option=4 那么 option>lastOption，会进入本else分支继续退栈
            else option = 3 + previous.row - here.row;
            here = previous;
        }
    }

    return true;
}

void outputPath()
{// Output path to exit.
    cout << "The path is" << endl;
    position here;
    while (!path->empty())
    {
        here = path->top();
        path->pop();
        cout << here.row << ' ' << here.col << endl;
    }
}

//int main()
//{
//    inputMaze();
//    if (findPath())
//        outputPath();
//    else
//        cout << "No path" << endl;
//}