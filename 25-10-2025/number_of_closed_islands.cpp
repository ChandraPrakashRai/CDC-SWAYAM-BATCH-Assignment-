// Number of Closed Islands (LeetCode) - grid of 0 (land) and 1 (water); closed island = 0 region not touching border
#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs_mark(int i,int j, vector<vector<int>>& g){
    if(i<0||j<0||i>=n||j>=m) return;
    if(g[i][j]!=0) return;
    g[i][j]=2;
    dfs_mark(i+1,j,g); dfs_mark(i-1,j,g); dfs_mark(i,j+1,g); dfs_mark(i,j-1,g);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j];
    // remove lands connected to border
    for(int i=0;i<n;i++){
        if(g[i][0]==0) dfs_mark(i,0,g);
        if(g[i][m-1]==0) dfs_mark(i,m-1,g);
    }
    for(int j=0;j<m;j++){
        if(g[0][j]==0) dfs_mark(0,j,g);
        if(g[n-1][j]==0) dfs_mark(n-1,j,g);
    }
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]==0){ cnt++; dfs_mark(i,j,g); }
    cout<<cnt<<"\n";
    return 0;
}
