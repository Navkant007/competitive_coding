"""
Connected components using Depth first search

6
4
2 6
6 5
3 4
2 5

"""

from collections import defaultdict


class Graph:
    def __init__(self) -> None:
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs_utils(self, u, visited):
        visited.add(u)

        for v in self.graph[u]:
            if v not in visited:
                self.dfs_utils(v, visited)

    def dfs(self, source, visited):
        self.dfs_utils(source, visited)


if __name__ == "__main__":
    g = Graph()
    n = int(input())
    e = int(input())
    for i in range(e):
        u, v = list(map(int, input().split()))
        g.add_edge(u, v)

    visited = set()
    connected_components = 0
    for i in range(1, n+1):
        if i not in visited:
            g.dfs(i, visited)
            connected_components += 1
    
    print(f"Number of Connected components - {connected_components}")

    
    