#include "pccb/chap3/graph/evacuation.h"
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>

namespace pccb {
  typedef std::pair<int, int> Point;
  constexpr int EVACUATION_INF = 1e6;

  class EvacuationEdge {
  public:
    explicit EvacuationEdge(const int f, const int t, const int c)
      : from(f),
      to(t),
      cost(c)
      {
      }
  public:
    int from;
    int to;
    int cost;
  };

  void FordFulkersonAddEdge(
      std::vector<EvacuationEdge> edges[],
      const int from,
      const int to,
      const int cost) {
    edges[from].push_back(EvacuationEdge(edges[to].size(), to, cost));
    edges[to].push_back(EvacuationEdge(edges[from].size() - 1, from, 0));
  }

  // Depth First Search
  // edge.cost denote the remained capacity
  int FindUsableCapacity(
      std::vector<EvacuationEdge> edges[],
      bool used[],
      const int from,
      const int to,
      const int flow) {
    // reach destination
    if (from == to) {
      return flow;
    }
    used[from] = true;
    for (int i = 0; i < edges[from].size(); ++i) {
      EvacuationEdge& e = edges[from][i];
      // vertex e.to is not used
      // there is room for new flow
      if (!used[e.to] && e.cost > 0) {
        // move to next vertex
        const int d = FindUsableCapacity(edges, used, e.to, to, std::min(flow, e.cost));
        if (d > 0) {
          // reduce capacity
          e.cost -= d;
          edges[e.to][e.from].cost += d;
          return d;
        }
      }
    }
    return 0;
  }

  int FordFulkerson(
      std::vector<EvacuationEdge> edges[],
      const int start,
      const int end,
      const int num_vertex)
  {
    bool used[num_vertex];
    int flow = 0;
    const int INF = 1e8;
    while (true) {
      for (int i = 0; i < num_vertex; ++i) {
        used[i] = false;
      }

      const int f = FindUsableCapacity(edges, used, start, end, INF);
      if (f == 0) {
        return flow;
      }
      flow += f;
    }
  }

  int BipartiteMatching(
      std::vector<EvacuationEdge> graph[],
      const int num_group1,
      const int num_group2) {
    const int start = num_group1 + num_group2;
    const int end = start + 1;
    const int num_vertex = end + 1;
    std::vector<EvacuationEdge> graph_new[num_vertex];
    for (int v = 0; v < start; ++v) {
      for (int ei = 0; ei < graph[v].size(); ++ei) {
        graph_new[v].push_back(graph[v][ei]);
      }
    }

    for (int v = 0; v < num_group1; ++v) {
      FordFulkersonAddEdge(graph_new, start, v, 1);
    }
    for (int v = 0; v < num_group2; ++v) {
      FordFulkersonAddEdge(graph_new, num_group1 + v, end, 1);
    }
    return FordFulkerson(graph_new, num_vertex, start, end);
  }

  // True if people can be evacuated up to time
  bool CanEvacuate(
      const std::vector<Point>& doors,
      const std::vector<Point>& people,
      int**** min_dist,
      const int time) {
    const int num_door = doors.size();
    const int num_people = people.size();

    const int num_vertex = time * num_door + num_people;
    std::vector<EvacuationEdge> graph[num_vertex];
    for (int i = 0; i < num_door; ++i) {
      for (int j = 0; j < num_people; ++j) {
        const Point& door = doors[i];
        const Point& person = people[j];
        const int dist = min_dist[door.first][door.second][person.first][person.second];
        if (dist >= 0) {
          for (int t = dist; t <= time; ++t) {
            FordFulkersonAddEdge(graph, (t - 1) * num_door + i, time * num_door + j, 1);
          }
        }
      }
    }
    const int num_evacuated = BipartiteMatching(graph, time * num_door, num_people);
    return num_evacuated == num_people;
  }

  void CalculateMinDistance(
      const int size_x,
      const int size_y,
      const int x,
      const int y,
      int** min_dist,
      const std::vector<std::string>& room) {
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    std::queue<Point> q;
    min_dist[x][y] = 0;
    q.push(Point(x, y));
    while (!q.empty()) {
      const Point& p = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        const int next_x = p.first + dx[k];
        const int next_y = p.second + dy[k];
        if (0 <= next_x && next_x < size_x
            && 0 <= next_y && next_y < size_y
            && room[next_y][next_x] == '.'
            && min_dist[next_x][next_y] < 0) {
          min_dist[next_x][next_y] = min_dist[x][y] + 1;
          q.push(Point(next_x, next_y));
        }
      }
    }
  }

  int SolveEvacuation(const int size_x, const int size_y, const std::vector<std::string>& room)
  {
    int**** min_dist = new int***[size_x];
    for (int x = 0; x < size_x; ++x) {
      min_dist[x] = new int**[size_y];
      for (int y = 0; y < size_y; ++y) {
        min_dist[x][y] = new int*[size_x];
        for (int px = 0; px < size_x; ++px) {
          min_dist[x][y][px] = new int[size_y];
          for (int py = 0; py < size_y; ++py) {
            min_dist[x][y][px][py] = -1;
          }
        }
      }
    }

    std::vector<Point> doors;
    std::vector<Point> people;
    for (int y = 0; y < room.size(); ++y) {
      for (int x = 0; x < room[y].size(); ++x) {
        if (room[y][x] == 'D') {
          // door
          doors.push_back(Point(x, y));
          CalculateMinDistance(size_x, size_y, x, y, min_dist[x][y], room);
        } else if (room[y][x] == '.') {
          // people
          people.push_back(Point(x, y));
        }
      }
    }
    return 3;

    // find minum evacuation time
    const int room_size = size_x * size_y;
    int lb = -1;
    int ub = room_size + 1;
    while (ub - lb > 1) {
      const int mid = (ub + lb) / 2.0;
      if (CanEvacuate(doors, people, min_dist, mid)) {
        ub = mid;
      } else {
        lb = mid;
      }
    }

    if (ub > room_size) {
      // impossible
      return -1;
    } else {
      return ub;
    }
  }
} // namespace pccb

