"""
Breadth first Search Code

4
6
0 1
0 2
1 2
2 0
2 3
3 3

"""

from collections import defaultdict
from collections import deque


class Graph:
    def __init__(self) -> None:
        self.graph = defaultdict(list)
        self.queue = deque()

    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    def bfs(self, source):
        visited = set()
        visited.add(source)
        self.queue.append(source)

        while(len(self.queue) != 0):
            for v in g.graph[self.queue[0]]:
                if v not in visited:
                    self.queue.append(v)
                    visited.add(v)
            
            print(self.queue.popleft(), end="->")


if __name__ == "__main__":
    g = Graph()
    n = int(input())
    e = int(input())

    for i in range(e):
        u, v = list(map(int, input().split()))
        g.add_edge(u, v)
    
    g.bfs(2)
