
from concurrent.futures import ThreadPoolExecutor

# Input Graph
graph = {}

n = int(input("Enter number of nodes: "))

for i in range(n):

    node = int(input("Enter node: "))

    neighbors = list(map(int,
                    input("Enter neighbors: ").split()))

    graph[node] = neighbors

visited = set()

# DFS Function
def dfs(node):

    if node not in visited:

        print(node, end=" ")

        visited.add(node)

        with ThreadPoolExecutor() as executor:
            executor.map(dfs, graph[node])

# Start Node
start = int(input("Enter starting node: "))

print("\nDFS Traversal:")
dfs(start)
