#include "warshall_floyd.h"

namespace algorithm { namespace graph {
void warshall_floyd(
    std::vector<std::vector<int>>& dist, const int numVertex)
{
    for (int i = 0; i < numVertex; ++i) {
        for (int from = 0; from < numVertex; ++from) {
            for (int to = 0; to < numVertex; ++to) {
                dist[from][to] = std::min(
                    dist[from][to], dist[from][i] + dist[i][to]) ;
            }
        }
    }
}
} } // namespace algorithm { namespace graph {
