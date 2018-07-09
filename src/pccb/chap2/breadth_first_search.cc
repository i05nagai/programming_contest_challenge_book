#include "pccb/chap2/breadth_first_search.h"
#include <queue>

int breadth_first_search(
    char maze[][100],
    const int numRow, const int numCol,
    const int startRow, const int startCol,
    const int goalRow, const int goalCol)
{
    //typedef
    typedef std::pair<int, int> Point;

    // constant values
    const int INF = 10000000;
    const int moveRow[4] = {-1, 0, 1, 0};
    const int moveCol[4] = {0, 1, 0, -1};

    // initialize
    std::queue<Point> que;
    int distance[numRow][numCol];
    for (std::size_t row = 0; row < numRow; ++row) {
        for (std::size_t col = 0; col < numCol; ++col) {
            distance[row][col] = INF;
        }
    }

    // set start point
    que.push(Point(startRow, startCol));
    distance[startRow][startCol] = 0;
            
    while (que.size() >= 1) {
        const Point point = que.front();
        que.pop();
        const int row = point.first;
        const int col = point.second;

        // is goal?
        if (row == goalRow
            && col == goalCol) {
            break;
        }
        // move 4 directions
        for (int i = 0; i < 4; ++i) {
            const int nextRow = row + moveRow[i];
            const int nextCol = col + moveCol[i];

            // is in Range?
            // can is not wall
            // and is not measured?
            if ((nextRow < numRow && nextRow >= 0)
                && (nextCol < numCol && nextCol >= 0)
                && maze[nextRow][nextCol] != '#'
                && distance[nextRow][nextCol] == INF)
            {
                distance[nextRow][nextCol] = distance[row][col] + 1;
                que.push(Point(nextRow, nextCol));
            }
        }
    }

    return distance[goalRow][goalCol];
}

