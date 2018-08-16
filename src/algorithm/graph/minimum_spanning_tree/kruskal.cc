#include <algorithm>
#include <cstdlib>
#include "algorithm/graph/minimum_spanning_tree/kruskal.h"

namespace algorithm {
namespace graph {

  bool compare(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
  }

  class UnionFindTree {
  public:
    explicit UnionFindTree(const int size)
    : size_(size){
      parents_ = (int*)std::malloc(size * sizeof(int));
      ranks_ = (int*)std::malloc(size * sizeof(int));
      for (int i = 0; i < size; ++i) {
        parents_[i] = i;
        ranks_[i] = 0;
      }
    }

    ~UnionFindTree() {
      free(parents_);
      free(ranks_);
    }

    int Find(const int x) const {
      if (parents_[x] == x) {
        return x;
      } else {
        parents_[x] = this->Find(parents_[x]);
        return parents_[x];
      }
    }

    void Unite(const int x, const int y) {
      const int group_x = this->Find(x);
      const int group_y = this->Find(y);

      // already united
      if (group_x == group_y) {
        return;
      }

      // unite to higher one
      if (ranks_[group_x] < ranks_[group_y]) {
        parents_[group_x] = group_y;
      } else {
        parents_[group_y] = group_x;
        if (ranks_[group_x] == ranks_[group_y]) {
          ranks_[group_x]++;
        }
      }
    }

    bool IsSame(const int x, const int y) {
      return this->Find(x) == this->Find(y);
    }

    int size_;
    // parents_[x] is a parent of node x
    // parents_[parents_[x]] is a parent of a parent of x
    int *parents_;
    int *ranks_;
  };

  int kruskal(
      Edge edges[],
      const int num_edge,
      const int num_vertex) {
    std::sort(edges, edges + num_edge, compare);

    UnionFindTree union_find_tree(num_vertex);
    int result = 0;
    for (int i = 0; i < num_edge; ++i) {
      const Edge& e = edges[i];
      if (!union_find_tree.IsSame(e.u, e.v)) {
        union_find_tree.Unite(e.u, e.v);
        result += e.cost;
      }
    }
    return result;
  }
} // namespace graph
} // namespace algorithm


