
from collections import deque
from concurrent.futures import ThreadPoolExecutor

# Input Graph
graph = {}

n = int(input("Enter number of nodes: "))

for i in range(n):

    node = int(input("Enter node: "))

    neighbors = list(map(int,
                    input("Enter neighbors: ").split()))

    graph[node] = neighbors

# BFS Function
def bfs(start):

    visited = set()
    queue = deque([start])

    visited.add(start)

    while queue:

        node = queue.popleft()

        print(node, end=" ")

        def process(neighbor):

            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

        with ThreadPoolExecutor() as executor:
            executor.map(process, graph[node])

# DFS Function
visited_dfs = set()

def dfs(node):

    if node not in visited_dfs:

        print(node, end=" ")

        visited_dfs.add(node)

        with ThreadPoolExecutor() as executor:
            executor.map(dfs, graph[node])

# Start Node
start = int(input("Enter starting node: "))

print("\nBFS Traversal:")
bfs(start)

print("\nDFS Traversal:")
dfs(start)