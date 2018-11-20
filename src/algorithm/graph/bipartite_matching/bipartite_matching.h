#pragma once

namespace algorithm { namespace graph {
int BipartiteMatchingFordFulkerson(
    bool** bipartite_graph,
    const int num_group1,
    const int num_group2);
int BipartiteMatching(
    bool** bipartite_graph,
    const int num_group1,
    const int num_group2);
} } // namespace algorithm { namespace graph {
