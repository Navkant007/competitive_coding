"""
Sortest path using Breadth First Search

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
    def __init__(self, n) -> None:
        self.graph = defaultdict(list)
        self.prev = [None] * n 
        self.queue = deque()

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def bfs(self, source):
        visited = set()
        self.queue.append(source)
        visited.add(source)

        while(len(self.queue) != 0):
            for v in self.graph[self.queue[0]]:
                if v not in visited:
                    self.queue.append(v)
                    self.prev[v] = self.queue[0]
                    visited.add(v)
            
            self.queue.popleft()

    def reconstuct_path(self, source, destination):
        path = []

        while(destination != None):
            path.append(destination)
            destination = self.prev[destination]

        path.reverse()
        if path[0] != source:
            print("No path exist!")
            return

        for i in path:
            print(i, end="->")

    def shortest_path(self, source, destination):
        self.bfs(source)
        self.reconstuct_path(source, destination)



if __name__ == "__main__":
    n = int(input())
    e = int(input())
    g = Graph(n)
    for i in range(e):
        u, v = list(map(int, input().split()))
        g.add_edge(u, v)

    s = int(input("Source -> "))
    d = int(input("Destination -> "))

    g.shortest_path(s, d)
