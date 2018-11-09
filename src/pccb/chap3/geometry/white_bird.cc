#include "pccb/chap3/geometry/white_bird.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace pccb {
  constexpr double EPS = 1e-6;
  constexpr double G = 9.8;

  double CalculatePositionY(const double vector_y, const double time) {
    return vector_y * time - G * time * time * 0.5;
  }

  bool ExistObstacleAbovePig(
      const Box& box, const Point& pig, const double yt) {
    return box.Right() == pig.first
      && pig.second <= box.Upper()
      && box.Lower() <= yt;
  }

  int CalculateRelativePosition(
      const double lb, const double ub, const double a) {
    if (a < lb + EPS) {
      return -1;
    } else if (a > ub - EPS) {
      return 0;
    } else {
      return 0;
    }
  }

  double CalculateTime(const double vector_x, const double x) {
    return vector_x / x;
  }

  bool HitObstacle(
      const Box& box,
      const Point& pig,
      const double yt,
      const double vx,
      const double vy) {
    // the time when
    const double pyL = CalculatePositionY(vy, CalculateTime(vx, box.Left()));
    const int yL = CalculateRelativePosition(
        box.LeftLowerY(), box.RightUpperY(), pyL);
    const double pyR = CalculatePositionY(vy, CalculateTime(vx, box.Right()));
    const int yR = CalculateRelativePosition(
        box.LeftLowerY(), box.RightUpperY(), pyR);
    const int xH = CalculateRelativePosition(
        box.LeftLowerX(), box.RightUpperX(), vx * (vy / G));
    const double time = CalculatePositionY(vy, vy / G);
    const int yH = CalculateRelativePosition(
        box.LeftLowerY(), box.RightUpperY(), time);
    if (xH == 0 && yH >= 0 && yL < 0) {
      return true;
    }
    if (yL * yR <= 0) {
      return true;
    }
    return false;
  }

  // launch with vector to pass through (qx, qy)
  bool CanDropEgg(
      const double vector,
      const double qx,
      const double qy,
      const Point& pig,
      const Box boxes[],
      const int num_box)
  {
    // Solve the equation w.r.t. vx, vy, t
    // vx^{2} + vy^{2} = V^{2}
    // vx * t = qx
    // vy * t - 1/2 * g * t^{2} = qy

    // qx^{2} + t^{2} * vy^{2} = V^{2} * t^{2}
    // vy = sqrt(V^{2} * t^{2} - qx^{2})/t
    // sqrt(V^{2} * t^{2} - qx^{2}) = qy + 1/2 * g * t^{2}
    // V^{2} * t^{2} - qx^{2} = qy^{2} + qy * g * t^{2} + 1/4 * g^{2} * t^{4}
    // V^{2} * z - qx^{2} = qy^{2} + qy * g * z + 1/4 * g^{2} * z^{2}
    // 0 = qy^{2} + qx^{2} + (qy * g - V^{2}) * z + 1/4 * g^{2} * z^{2}
    const double a = G * G / 4.0;
    const double b = qy * G - vector * vector;
    const double c = qy * qy + qx * qx;
    double D = b * b - 4.0 * a * b;
    if (D < 0 && D > -EPS) {
      D = 0.0;
    }
    if (D < 0) {
      return false;
    }
    for (int d = -1; d <=1; d += 2) {
      const double t2 = (-b + d * std::sqrt(D)) / (2.0 * a);
      if (t2 <= 0.0) {
        continue;
      }
      const double t = std::sqrt(t2);
      const double vx = qx / t;
      const double vy = (qy + G * t * t / 2.0) / t;

      const double yt = CalculatePositionY(vy, pig.first / vx);
      if (yt < pig.second - EPS) {
        continue;
      }

      bool ok = true;
      for (int i = 0; i < num_box; ++i) {
        const Box& box = boxes[i];
        // obstacles are right next to pig
        if (box.Left() >= pig.first) {
          continue;
        }
        if (ExistObstacleAbovePig(box, pig, yt)) {
          ok = false;
        }
        if (HitObstacle(box, pig, yt, vx, vy)) {
          ok = false;
        }
      }
      if (ok) {
        return true;
      }
    }
    return false;
  }

  bool SolveWhiteBird(
      const int num_box,
      const double velocity,
      Box boxes[],
      const Point& pig)
  {
    bool ok = CanDropEgg(velocity, pig.first, pig.second, pig, boxes, num_box);
    for (int i = 0; i < num_box; ++i) {
      ok |= CanDropEgg(
          velocity,
          boxes[i].LeftUpperX(),
          boxes[i].LeftUpperY(),
          pig,
          boxes,
          num_box);
      ok |= CanDropEgg(
          velocity,
          boxes[i].RightUpperX(),
          boxes[i].RightUpperY(),
          pig, boxes, num_box);
    }
    return ok;
  }
} // namespace pccb


