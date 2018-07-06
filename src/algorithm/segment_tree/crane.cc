#include "algorithm/segment_tree/crane.h"
#include <cmath>
#include <vector>

namespace pccb {
inline int nodeToLeft(const int nodeIndex) 
{
  return 2 * nodeIndex + 1;
}

inline int nodeToRight(const int nodeIndex)
{
  return 2 * nodeIndex + 2;
}

void init_segment_tree(
    const int craneLengths[],
    double nodeX[],
    double nodeY[],
    double nodeAngles[],
    const int nodeIndex,
    const int left,
    const int right)
{
  nodeX[nodeIndex] = 0.0;
  nodeAngles[nodeIndex] = 0.0;
  if (right - left == 1) {
    // leaf
    nodeY[nodeIndex] = craneLengths[left];
  } else {
    int newLeft = nodeToLeft(nodeIndex);
    int newRight = nodeToRight(nodeIndex);
    init_segment_tree(
        craneLengths, nodeX, nodeY, nodeAngles, newLeft, left, (left + right) / 2);
    init_segment_tree(
        craneLengths, nodeX, nodeY, nodeAngles, newRight, (left + right) / 2, right);
    nodeY[nodeIndex] = nodeY[newLeft] + nodeY[newRight];
  }
}

// angle at point are changed to angle
/**
 * @brief 
 *
 * @param point
 * @param angle
 * @param nodeIndex
 * @param left left corresponding to nodeIndex
 * @param right right corresponding to nodeIndex
 */
void change_segment_tree(
    double nodeX[],
    double nodeY[],
    double nodeAngles[],
    const int point, 
    const double angle,
    const int nodeIndex,
    const int left,
    const int right)
{
  if (point <= left) {
    return;
  } else if (point < right) {
    const int newLeft = nodeToLeft(nodeIndex);
    const int newRight = nodeToRight(nodeIndex);

    const int mid = (left + right) / 2;
    change_segment_tree(nodeX, nodeY, nodeAngles, point, angle, newLeft, left, mid);
    change_segment_tree(nodeX, nodeY, nodeAngles, point, angle, newRight, mid, right);

    if (point <= mid) {
      nodeAngles[nodeIndex] += angle;
    }
    const double sin = std::sin(nodeAngles[nodeIndex]);
    const double cos = std::cos(nodeAngles[nodeIndex]);
    nodeX[nodeIndex] = nodeX[newLeft] + (cos * nodeX[newRight] - sin * nodeY[newRight]);
    nodeY[nodeIndex] = nodeY[newLeft] + (sin * nodeX[newRight] - cos * nodeY[newRight]);
  }
}

std::vector<std::pair<double, double>> crane(
    const int numCranes,
    const int numCommands,
    const int craneLengths[],
    const int points[],
    const double angles[]) 
{
  double nodeX[numCranes];
  double nodeY[numCranes];
  double nodeAngles[numCranes];
  double originalAngles[numCranes];
  init_segment_tree(craneLengths, nodeX, nodeY, nodeAngles, 0, 0, numCranes);

  for (int i = 1; i < numCranes; ++i) {
    originalAngles[i] = M_PI;
  }

  // for each commands
  typedef std::pair<double, double> Point;
  std::vector<Point> vecs;
  for (int i = 0; i < numCommands; ++i) {
    const int point = points[i];
    const double angle = angles[i] / 360.0 * 2 * M_PI;

    change_segment_tree(
        nodeX, nodeY, nodeAngles, point, angle - originalAngles[point], 0, 0, numCranes);
    originalAngles[point] = angle;

    vecs.emplace_back(Point(nodeX[0], nodeY[0]));
  }
  return vecs;
}
} // namespace pccb
