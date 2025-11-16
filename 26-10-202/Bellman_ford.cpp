// bellman_ford.cpp
// Bellman-Ford algorithm: detects negative cycles reachable from src.
// Input: n m
// m lines: u v w
// src

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);
struct Edge { int u, v; ll w; };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    int src; cin >> src;
    vector<ll> dist(n, INF);
    dist[src] = 0;
    // Relax V-1 times
    for (int iter = 0; iter < n-1; ++iter) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] == INF) continue;
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    // Detect negative cycle
    bool neg = false;
    for (auto &e : edges) {
        if (dist[e.u] == INF) continue;
        if (dist[e.v] > dist[e.u] + e.w) { neg = true; break; }
    }
    if (neg) {
        cout << "NEGATIVE CYCLE\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) cout << "INF";
            else cout << dist[i];
            if (i+1<n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
