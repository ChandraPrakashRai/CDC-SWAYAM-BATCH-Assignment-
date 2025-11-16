// Check if path exists between source and destination in undirected graph (BFS)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    int s,t; cin>>s>>t;
    vector<int> vis(n,0); queue<int>q; q.push(s); vis[s]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(u==t){ cout<<"true\n"; return 0; }
        for(int v: g[u]) if(!vis[v]){ vis[v]=1; q.push(v); }
    }
    cout<<"false\n";
    return 0;
}
