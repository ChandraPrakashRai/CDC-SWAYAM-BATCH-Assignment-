// a_star_grid.cpp
// A* Search on a 2D grid (4-directional) with Manhattan heuristic.
// Input:
//  R C
//  R lines: characters S (start), G (goal), . (free), # (obstacle)
// Output:
//  If reachable: prints path length and the path coordinates (row col) from S -> G (inclusive).
//  Else prints "No path found"
//
// Compile: g++ -std=c++17 a_star_grid.cpp -O2 -o a_star

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
struct Node {
    int r, c;
    int g; // cost so far
    int f; // g + h
    bool operator<(const Node &other) const {
        // for priority_queue which is max-heap by default,
        // we want smallest f to have highest priority
        if (f != other.f) return f > other.f;
        return g < other.g; // tie-breaker: prefer larger g? we prefer smaller g -> > flips; but keep consistent
    }
};

// Manhattan heuristic (admissible for 4-neighborhood with unit cost)
inline int manhattan(const pii &a, const pii &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    if (!(cin >> R >> C)) return 0;
    vector<string> grid(R);
    string line;
    getline(cin, line); // consume endline

    pii start{-1,-1}, goal{-1,-1};
    for (int i = 0; i < R; ++i) {
        getline(cin, grid[i]);
        // allow input lines shorter/longer by trimming/padding
        if ((int)grid[i].size() < C) {
            // pad with spaces if needed (unlikely), or assume no
            grid[i] += string(C - grid[i].size(), ' ');
        }
        for (int j = 0; j < C && j < (int)grid[i].size(); ++j) {
            char ch = grid[i][j];
            if (ch == 'S') start = {i,j};
            else if (ch == 'G') goal = {i,j};
        }
    }

    if (start.first == -1 || goal.first == -1) {
        cout << "Start or goal not provided (use 'S' and 'G')\n";
        return 0;
    }

    // 4 directions: up, down, left, right
    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};

    // open set = priority queue of Node with smallest f first
    priority_queue<Node> open;
    // gscore: cost from start to node; initialize to INF
    const int INF = 1e9;
    vector<vector<int>> gscore(R, vector<int>(C, INF));
    // parent pointers to reconstruct path
    vector<vector<pii>> parent(R, vector<pii>(C, {-1,-1}));
    // closed set / visited
    vector<vector<char>> closed(R, vector<char>(C, 0));

    gscore[start.first][start.second] = 0;
    int h0 = manhattan(start, goal);
    open.push(Node{start.first, start.second, 0, h0});
    parent[start.first][start.second] = {-1,-1};

    bool found = false;
    while (!open.empty()) {
        Node cur = open.top(); open.pop();
        int r = cur.r, c = cur.c;
        if (closed[r][c]) continue; // we may have pushed stale entries
        closed[r][c] = 1;

        if (r == goal.first && c == goal.second) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            char ch = grid[nr][nc];
            if (ch == '#') continue; // obstacle

            int tentative_g = gscore[r][c] + 1; // every edge cost = 1
            if (tentative_g < gscore[nr][nc]) {
                gscore[nr][n]()
