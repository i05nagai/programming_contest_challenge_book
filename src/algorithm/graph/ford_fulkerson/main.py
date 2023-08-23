
def dfs(graph, used, fr, goal, flow):
    if fr == goal:
        return flow
    used[fr] = True
    for edge in graph[fr]:
        if used[edge.to] or edge.cap == 0:
            continue
        d = dfs(graph, used, edge.to, goal, min(flow, edge.cap))
        if d > 0:
            edge.cap -= d
            graph[edge.to][edge.rev_index].cap += d
            return d
    return 0


class Edge:
    
    def __init__(self, to, cap, rev_index):
        self.to = to
        self.cap = cap
        self.rev_index = rev_index

    def __str__(self):
        return f"{self.to}, {self.cap}, {self.rev_index}"


def add_edge(graph, fr, to, cap):
    graph[fr].append(Edge(to, cap, len(graph[to])))
    graph[to].append(Edge(fr, 0, len(graph[fr]) - 1))


def solve(edges, fr, to):
    vs = set(e[1] for e in edges)
    vs = vs.union(set(e[0] for e in edges))
    graph = [[] for i in range(len(vs))]
    for e in edges:
        add_edge(graph, e[0], e[1], e[2])
    flow = 0
    while True:
        used = [False] * len(vs)
        f = dfs(graph, used, fr, to, 10 ** 8)
        if f == 0:
            return flow
        flow += f


def main():
    # from, to, cap
    edges = [
        (0, 1, 10),
        (0, 2, 2),
        (1, 2, 6),
        (1, 3, 6),
        (2, 4, 5),
        (3, 2, 3),
        (3, 4, 8),
    ]
    actual = solve(edges, 0, 4)
    expected = 11
    assert expected == actual, (expected, actual)


if __name__ == '__main__':
    main()
