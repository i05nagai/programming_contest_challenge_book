#include "chap2/conscription.h"
#include "chap2/minimum_spanning_tree.h"

int conscription(
    const std::vector<ConscriptionRelation>& relations,
    const int numMale,
    const int numFemale)
{
    constexpr int DEFAULT_COST = 10000;
    std::vector<MinimumSpanningTreeEdge> edges(relations.size());

    for (int r = 0; r < relations.size(); ++r) {
        edges[r] = MinimumSpanningTreeEdge(
            relations[r].male,
            numMale + relations[r].female,
            -relations[r].intimate);
    }
    const int cost = (numMale + numFemale) * DEFAULT_COST
        + kruskal(edges, numMale + numFemale);
    return cost;
}
