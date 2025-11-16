// BFS and DFS traversal from a source node
#include <bits/stdc++.h>
using namespace std;
void bfs(int s, vector<vector<int>>& g){
    int n=g.size();
    vector<int> vis(n,0);
    queue<int> q; q.push(s); vis[s]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v: g[u]) if(!vis[v]){ vis[v]=1; q.push(v); }
    }
    cout<<"\n";
}
void dfs_util(int u, vector<int>& vis, vector<vector<int>>& g){
    vis[u]=1; cout<<u<<" ";
    for(int v: g[u]) if(!vis[v]) dfs_util(v, vis, g);
}
void dfs(int s, vector<vector<int>>& g){
    int n=g.size();
    vector<int> vis(n,0);
    dfs_util(s, vis, g);
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    int src; cin>>src;
    bfs(src, g);
    dfs(src, g);
    return 0;
}
