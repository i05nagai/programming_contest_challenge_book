
class Edge:

    def __init__(self, inv, outv):
        self.inv = inv
        self.outv = outv

    def __str__(self):
        return f"{self.inv}, {self.outv}"


def visit(graph, visited, L, u):
    if visited[u]:
        return
    visited[u] = True
    for edge in graph[u]:
        visit(graph, visited, L, edge.outv)
    L.insert(0, u)


def assign(ingraph, u, root, G):
    if u not in G:
        G[u] = root
        for e in ingraph[u]:
            assign(ingraph, e.inv, root, G)


def kosaruju(graph, ingraph):
    L = []
    visited = [False for v in graph]
    for v in reversed(range(len(graph))):
        visit(graph, visited, L, v)

    # L is a sequence of vertexes starting with root
    G = {}
    for u in L:
        assign(ingraph, u, u, G)
    return G


def solve(edges):
    vs = set(e[0] for e in edges)
    vs = vs.union(set(e[1] for e in edges))
    graph = [[] for v in vs]
    ingraph = [[] for v in vs]
    for e in edges:
        edge = Edge(e[0], e[1])
        graph[e[0]].append(edge)
        ingraph[e[1]].append(edge)

    G = kosaruju(graph, ingraph)
    return G


def main():
    edges = [
        (0, 1),
        (1, 2),
        (2, 0),
        (0, 3),
        (3, 4),
    ]
    G = solve(edges)
    print(G)

    edges = [
        (0, 1),
        (1, 2),
        (2, 0),

        (1, 5),
        (5, 6),
        (6, 1),

        (0, 3),
        (3, 4),
    ]
    G = solve(edges)
    print(G)


if __name__ == '__main__':
    main()
