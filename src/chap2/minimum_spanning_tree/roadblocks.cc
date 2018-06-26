#include "chap2/minimum_spanning_tree/roadblocks.h"
#include <queue>

int roadblocks(
    const std::vector<std::vector<RoadblocksEdge>>& graph,
    const int numJunction,
    const int numRoad)
{
    // first is distance
    // second is vertex number
    typedef std::pair<int, int> Vertex;
    // vertex will be updated
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex> > queue;

    constexpr int INF = 1000000;
    //shortest distance
    int dist1[numJunction];
    //second shortest distance
    int dist2[numJunction];
    //initialize
    std::fill(dist1, dist1 + numJunction, INF);
    std::fill(dist2, dist2 + numJunction, INF);

    dist1[0] = 0;
    queue.push(Vertex(0, 0));
    while (!queue.empty()) {
        const Vertex vertex = queue.top();
        queue.pop();
        const int distance = vertex.first;
        const int vertexNum = vertex.second;
        
        // update all edge
        for (int e = 0; e < graph[vertexNum].size(); ++e) {
            const RoadblocksEdge& edge = graph[vertexNum][e];
            int newDistance = distance + edge.cost;
            const int to = edge.to;
            // we already have shorter path
            if (dist2[to] < newDistance) {
                continue;
            }
            // find shortest distance
            if (dist1[to] > newDistance) {
                //newDistance is now 
                std::swap(dist1[to], newDistance);
                //add to update list because distance is updated
                queue.push(Vertex(dist1[to], to));
            }
            // find second shortest distance
            if (dist1[to] < newDistance && newDistance < dist2[to]) {
                dist2[to] = newDistance;
                //add to update list because distance is updated
                queue.push(Vertex(newDistance, to));
            }
        }
    }

    return dist2[numJunction - 1];
}

// BAD
int _roadblocks(
    const std::vector<RoadblocksEdge> graph[],
    const int numJunction,
    const int numRoad)
{
    // first is distance
    // second is vertex number
    typedef std::pair<int, int> Vertex;
    // vertex will be updated
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex> > queue;

    constexpr int INF = 1000000;
    //shortest distance
    int dist1[numRoad];
    //second shortest distance
    int dist2[numRoad];
    //initialize
    std::fill(dist1, dist1 + numRoad, INF);
    std::fill(dist2, dist2 + numRoad, INF);

    dist1[0] = 0;
    queue.push(Vertex(0, 0));
    while (!queue.empty()) {
        const Vertex vertex = queue.top();
        queue.pop();
        const int distance = vertex.first;
        const int vertexNum =  vertex.second;
        
        // update all edge
        for (int e = 0; e < graph[vertexNum].size(); ++e) {
            const RoadblocksEdge edge = graph[vertexNum][e];
            const int newDistance = distance + edge.cost;
            const int to = edge.to;
            // we already have shorter path
            if (dist2[vertexNum] < newDistance) {
                continue;
            }
            // find shortest distance
            if (dist1[to] > newDistance) {
                //the distance will be second shortest distance
                dist2[to] = dist1[to];
                //update shortest distance
                dist1[to] = newDistance;
                //add to update list because distance is updated
                queue.push(Vertex(newDistance, to));
            }
            // find second shortest distance
            if (dist1[to] < newDistance && newDistance < dist2[to]) {
                dist2[to] = newDistance;
                //add to update list because distance is updated
                queue.push(Vertex(newDistance, to));
            }
        }
    }

    return dist2[numRoad - 1];
}
