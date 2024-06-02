#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS in the residual graph to find an augmenting path
int bfs(int source, int target, int n, vector<int>& parent, vector<vector<int>>& graph) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});
    
    while (!q.empty()) {
        int u = q.front().first;
        int cap = q.front().second;
        q.pop();
        
        for (int v = 0; v < n; v++) {
            if (u != v && graph[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                int new_cap = min(cap, graph[u][v]);
                if (v == target) {
                    return new_cap;
                }
                q.push({v, new_cap});
            }
        }
    }
    return 0;
}

// Function to implement the Ford-Fulkerson algorithm using BFS for finding max flow
int Ford_Fulkerson(int source, int target, int n, vector<vector<int>>& graph) {
    vector<int> parent(n);
    int max_flow = 0, min_cap;

    while ((min_cap = bfs(source, target, n, parent, graph)) > 0) {
        max_flow += min_cap;
        int v = target;
        
        while (v != source) {
            int u = parent[v];
            graph[u][v] -= min_cap;
            graph[v][u] += min_cap;
            v = u;
        }
    }
    return max_flow;
}

// Function to add edges to the graph
void addEdge(vector<vector<int>>& graph, int u, int v, int w) {
    graph[u][v] = w;
}

int main() {
    int V = 6;  // Number of vertices
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    addEdge(graph, 0, 1, 16);
    addEdge(graph, 0, 2, 13);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 1, 4);
    addEdge(graph, 1, 3, 12);
    addEdge(graph, 2, 4, 14);
    addEdge(graph, 3, 2, 9);
    addEdge(graph, 4, 3, 7);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 3, 5, 20);
    
    cout << "Maximum Flow from Source 0 to Sink 5 using Ford-Fulkerson: " 
         << Ford_Fulkerson(0, 5, V, graph) << endl;
    return 0;
}
