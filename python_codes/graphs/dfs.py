"""
This is Depth first search code

1 -> 2
!  / !
~ ~  ~
4 <- 3

4
5
1 2
1 4
2 4
3 4
2 3
"""

from collections import defaultdict


class Graph:
    def __init__(self) -> None:
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs_utils(self, u, visited):
        if u in visited:
            return
        print(u)
        visited.add(u)
        for v in self.graph[u]:
            self.dfs_utils(v, visited)

    def dfs(self, source):
        visited = set()
        self.dfs_utils(source, visited)


if __name__ == "__main__":
    g = Graph()
    n = int(input())
    e = int(input())
    for i in range(e):
        u, v = list(map(int, input().split()))
        g.add_edge(u, v)
    
    print(g.graph)
    g.dfs(1)
