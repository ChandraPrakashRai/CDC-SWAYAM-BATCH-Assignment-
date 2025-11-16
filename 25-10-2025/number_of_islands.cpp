// Number of Islands (grid DFS)
#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs(int i,int j, vector<string>& grid){
    if(i<0||j<0||i>=n||j>=m) return;
    if(grid[i][j]!='1') return;
    grid[i][j]='0';
    dfs(i+1,j,grid); dfs(i-1,j,grid); dfs(i,j+1,grid); dfs(i,j-1,grid);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>m)) return 0;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]=='1'){ cnt++; dfs(i,j,grid); }
    cout<<cnt<<"\n";
    return 0;
}
