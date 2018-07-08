#include "algorithm/segment_tree/crane.h"
#include <cmath>
#include <vector>

namespace pccb {

  struct Node {
    double x;
    double y;
    double angle;
  };

  // refere left node
inline int leftNode(const int nodeIndex) 
{
  return 2 * nodeIndex + 1;
}

  // refere right node
inline int rightNode(const int nodeIndex)
{
  return 2 * nodeIndex + 2;
}

// [left, right)
void init_segment_tree(
    const int craneLengths[],
    Node nodes[],
    const int nodeIndex,
    const int left,
    const int right)
{
  // initial coordinate of i-th segment is (0, craneLength[i])
  // and angle is 0
  nodes[nodeIndex].x = 0.0;
  nodes[nodeIndex].angle = 0.0;
  if (right - left == 1) {
    // leaf
    nodes[nodeIndex].y = craneLengths[left];
  } else {
    const int newLeft = leftNode(nodeIndex);
    const int newRight = rightNode(nodeIndex);
    init_segment_tree(
        craneLengths, nodes, newLeft, left, (left + right) / 2);
    init_segment_tree(
        craneLengths, nodes, newRight, (left + right) / 2, right);
    nodes[nodeIndex].y = nodes[newLeft].y + nodes[newRight].y;
  }
}

/**
 * @brief the order to change the angle
 *    between the point-th and the point + 1-th segment to angle degrees
 *    the angle is measured counterclockwise from the point-th to the point + 1-th segment.
 *
 * @param point
 * @param angle
 * @param nodeIndex
 * @param left left corresponding to nodeIndex
 * @param right right corresponding to nodeIndex
 */
void change_segment_tree(
    Node nodes[],
    const int point,
    const double angle,
    const int nodeIndex,
    const int left,
    const int right)
{
  if (point <= left) {
    return;
    // rotateid point in [left, right)
  } else if (point < right) {
    const int newLeft = leftNode(nodeIndex);
    const int newRight = rightNode(nodeIndex);

    const int mid = (left + right) / 2;
    change_segment_tree(nodes, point, angle, newLeft, left, mid);
    change_segment_tree(nodes, point, angle, newRight, mid, right);

    if (point <= mid) {
      nodes[nodeIndex].angle += angle;
    }
    // multiply rotation matrix
    const double sin = std::sin(nodes[nodeIndex].angle);
    const double cos = std::cos(nodes[nodeIndex].angle);
    nodes[nodeIndex].x = nodes[newLeft].x + (cos * nodes[newRight].x - sin * nodes[newRight].y);
    nodes[nodeIndex].y = nodes[newLeft].y + (sin * nodes[newRight].x + cos * nodes[newRight].y);
  }
}

std::vector<std::pair<double, double>> SolveCrane(
    const int numCranes,
    const int numCommands,
    const int craneLengths[],
    const int points[],
    const int angles[])
{
  // nodes[i]: 
  Node nodes[(2 << 15) - 1];
  double originalAngles[numCranes];
  init_segment_tree(craneLengths, nodes, 0, 0, numCranes);

  for (int i = 1; i < numCranes; ++i) {
    // 180 degree
    originalAngles[i] = M_PI;
  }

  // for each commands
  typedef std::pair<double, double> Point;
  std::vector<Point> vecs;
  for (int i = 0; i < numCommands; ++i) {
    const int point = points[i];
    const double angle = angles[i] / 360.0 * 2 * M_PI;

    change_segment_tree(
        nodes,
        point,
        angle - originalAngles[point],
        0,
        0,
        numCranes);
    originalAngles[point] = angle;

    vecs.emplace_back(Point(nodes[0].x, nodes[0].y));
  }
  return vecs;
}
} // namespace pccb
