// Connected Components and Cycle Detection (undirected)
#include <bits/stdc++.h>
using namespace std;
void dfs_cc(int u, vector<int>& vis, vector<vector<int>>& g, vector<int>& comp){
    vis[u]=1; comp.push_back(u);
    for(int v: g[u]) if(!vis[v]) dfs_cc(v, vis, g, comp);
}
bool dfs_cycle(int u, int p, vector<int>& vis, vector<vector<int>>& g){
    vis[u]=1;
    for(int v: g[u]){
        if(!vis[v]){
            if(dfs_cycle(v, u, vis, g)) return true;
        } else if(v!=p) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    // connected components
    vector<int> vis(n,0);
    vector<vector<int>> comps;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int> comp;
            dfs_cc(i, vis, g, comp);
            comps.push_back(comp);
        }
    }
    cout<<comps.size()<<"\n";
    for(auto &c: comps){
        for(int x: c) cout<<x<<" ";
        cout<<"\n";
    }
    // cycle detection
    fill(vis.begin(), vis.end(), 0);
    bool hasCycle=false;
    for(int i=0;i<n;i++) if(!vis[i]) if(dfs_cycle(i, -1, vis, g)) hasCycle=true;
    cout<<(hasCycle? "Cycle Found":"No Cycle")<<"\n";
    return 0;
}
