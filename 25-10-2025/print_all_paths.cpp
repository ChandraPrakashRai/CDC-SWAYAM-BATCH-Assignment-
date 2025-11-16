// Print all paths from source to destination (backtracking)
#include <bits/stdc++.h>
using namespace std;
void dfs(int u, int t, vector<vector<int>>& g, vector<int>& path, vector<int>& vis){
    if(u==t){
        for(size_t i=0;i<path.size();++i){
            if(i) cout<<" ";
            cout<<path[i];
        }
        cout<<"\n";
        return;
    }
    for(int v: g[u]){
        if(!vis[v]){
            vis[v]=1; path.push_back(v);
            dfs(v,t,g,path,vis);
            path.pop_back(); vis[v]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    int s,t; cin>>s>>t;
    vector<int> vis(n,0); vis[s]=1; vector<int> path; path.push_back(s);
    dfs(s,t,g,path,vis);
    return 0;
}
