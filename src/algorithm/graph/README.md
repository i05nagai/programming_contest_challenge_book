

## Graph expressions
* Adjacency lists
    * space complexity: O(|V| + |E|)
    * implementation

```cpp
std::vector<Edge> G[V];
struct Edge {
  int to;
  int cost;
};
```

```cpp
struct Vertex {
  std::vector<Vertex*> edge;
};
Vertex G[V];
```

* Adjacency matrix
    * space complexity: O(|V| + |V|)
    * a lot of memory
    * if undirected graph, matrix is symmetric
    * it can compute whether an edge between two vertice exist or not in constant time,
    * it cannot express multiple edges if the graph has weighted edges



### Kruskal
* Find Minimum Spanning Tree
* $O(|E| \log |V|)$,

