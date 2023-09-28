from collections import defaultdict

class Graph:
    def __init__(self) -> None:
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):
        visited.add(v)
        print(f"{v}", end=" ----> ")

        for u in self.graph[v]:
            if u not in visited:
                self.DFSUtil(u, visited)
    
    def DFS(self, v):
        visited = set()
        self.DFSUtil(v, visited)


if __name__ == "__main__":
    g = Graph()
    n = int(input())
    for i in range(n):
        a, b = list(map(int, input().split()))
        g.add_edge(a, b)
    print(g.graph)
    g.DFS(2)