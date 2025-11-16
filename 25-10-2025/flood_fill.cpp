// Flood Fill (change color using DFS)
#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs(int i,int j, vector<vector<int>>& grid, int orig, int color){
    if(i<0||j<0||i>=n||j>=m) return;
    if(grid[i][j]!=orig) return;
    grid[i][j]=color;
    dfs(i+1,j,grid,orig,color); dfs(i-1,j,grid,orig,color);
    dfs(i,j+1,grid,orig,color); dfs(i,j-1,grid,orig,color);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>m)) return 0;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>grid[i][j];
    int sr, sc, color; cin>>sr>>sc>>color;
    int orig = grid[sr][sc];
    if(orig!=color) dfs(sr,sc,grid,orig,color);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<grid[i][j]<<(j+1==m?"":" ");
        cout<<"\n";
    }
    return 0;
}
