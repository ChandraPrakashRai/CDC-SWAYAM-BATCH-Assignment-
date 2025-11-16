// Number of Provinces (connected components from adjacency matrix)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>adj[i][j];
    vector<int> vis(n,0);
    int provinces=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            provinces++;
            queue<int>q; q.push(i); vis[i]=1;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v=0; v<n; v++) if(adj[u][v] && !vis[v]){ vis[v]=1; q.push(v); }
            }
        }
    }
    cout<<provinces<<"\n";
    return 0;
}
