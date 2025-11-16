/*
 * SHORTEST PATH ALGORITHM - DIJKSTRA'S ALGORITHM
 * Date: 26/10/2025
 * Topic: Graph - Shortest Path
 * 
 * Problem: Find shortest path from source to all vertices in weighted graph
 * Link: https://cp-algorithms.com/graph/dijkstra.html
 * 
 * APPROACH 1: Using Priority Queue (Min Heap)
 * - Use min heap to get vertex with minimum distance
 * - Update distances of adjacent vertices
 * - Time Complexity: O((V + E) log V)
 * - Space Complexity: O(V)
 * 
 * APPROACH 2: Simple Array (for dense graphs)
 * - Find minimum distance vertex by scanning array
 * - Time Complexity: O(V^2)
 * - Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Structure to represent edge
struct Edge {
    int to, weight;
};

// APPROACH 1: Using Priority Queue (Optimized)
vector<int> dijkstraOptimized(int V, vector<vector<Edge>>& graph, int src) {
    // Distance array, initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Min heap: pair(distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Skip if already processed with shorter path
        if (d > dist[u]) continue;
        
        // Update distances of adjacent vertices
        for (auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// APPROACH 2: Simple Array Method
vector<int> dijkstraSimple(int V, vector<vector<int>>& adjMatrix, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        // Find vertex with minimum distance
        int minDist = INT_MAX, u = -1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        // Update distances
        for (int v = 0; v < V; v++) {
            if (!visited[v] && adjMatrix[u][v] != 0 && 
                dist[u] != INT_MAX && 
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }
    
    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    // Using adjacency list for optimized version
    vector<vector<Edge>> graph(V);
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // For undirected graph, add reverse edge
        // graph[v].push_back({u, w});
    }
    
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    
    // Find shortest paths using optimized approach
    vector<int> distances = dijkstraOptimized(V, graph, src);
    
    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (distances[i] == INT_MAX)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << distances[i] << "\n";
    }
    
    return 0;
}

/*
EXAMPLE TEST CASE:
Input:
5 7
0 1 4
0 2 1
1 3 1
2 1 2
2 3 5
3 4 3
1 4 2

Output:
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: 3
Vertex 2: 1
Vertex 3: 4
Vertex 4: 5

TIME COMPLEXITY: O((V + E) log V) with priority queue
SPACE COMPLEXITY: O(V + E)
*/