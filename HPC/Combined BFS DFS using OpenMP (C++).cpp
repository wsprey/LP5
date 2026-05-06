#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// BFS Function
void bfs(int start) {

    vector<bool> bfsVisited(graph.size(), false);

    queue<int> q;

    q.push(start);
    bfsVisited[start] = true;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        #pragma omp parallel for
        for(int i = 0; i < graph[node].size(); i++) {

            int neighbor = graph[node][i];

            if(!bfsVisited[neighbor]) {

                bfsVisited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// DFS Function
void dfs(int node) {

    visited[node] = true;

    cout << node << " ";

    #pragma omp parallel for
    for(int i = 0; i < graph[node].size(); i++) {

        int neighbor = graph[node][i];

        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {

    int n, e;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    graph.resize(n);
    visited.resize(n, false);

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;

    cout << "Enter starting node: ";
    cin >> start;

    cout << "\nBFS Traversal: ";
    bfs(start);

    cout << "\nDFS Traversal: ";
    dfs(start);

    return 0;
}