#include "chap2/saruman_army.h"
#include <algorithm>

int saruman_army(const int numPoint, const int radius, int points[])
{
    std::sort(points, points + numPoint);
    
    int i = 0;
    int answer = 0;
    while (i < numPoint) {
        // from uncover point to center
        const int uncoverPoint = points[i++];
        while (i < numPoint && points[i] <= uncoverPoint + radius) {
            i++;
        }

        // from center to farthest covered point
        const int point = points[i - 1];
        while (i < numPoint && points[i] <= point + radius) {
            i++;
        }

        answer++;
    }
    return answer;
}
