// Graph Representation: read n, m edges then build adjacency matrix and adjacency list
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<vector<int>> adjList(n);
    vector<vector<int>> adjMat(n, vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        // assuming 0-based. If 1-based, subtract 1.
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    // print adjacency list
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int v: adjList[i]) cout<<" "<<v;
        cout<<"\n";
    }
    // print adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjMat[i][j]<<(j+1==n? "":" ");
        }
        cout<<"\n";
    }
    return 0;
}
