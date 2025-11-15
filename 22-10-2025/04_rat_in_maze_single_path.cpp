// Rat in a maze - print one path (0 = blocked, 1 = open)
// Input: n (size) then n*n grid (row-major)
// Output: sequence of coordinates (r c) from (0,0) to (n-1,n-1) if path exists
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int,int>> path;
vector<vector<int>> vis;
bool dfs(int r,int c){
    if(r<0||c<0||r>=n||c>=n) return false;
    if(!a[r][c] || vis[r][c]) return false;
    path.emplace_back(r,c);
    vis[r][c]=1;
    if(r==n-1 && c==n-1) return true;
    const int dr[4]={1,0,0,-1}, dc[4]={0,1,-1,0};
    for(int k=0;k<4;k++){
        if(dfs(r+dr[k], c+dc[k])) return true;
    }
    path.pop_back();
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n)) return 0;
    a.assign(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    vis.assign(n, vector<int>(n,0));
    if(dfs(0,0)){
        for(auto &p:path) cout<<p.first<<" "<<p.second<<"\n";
    } else cout<<"NO PATH\n";
    return 0;
}
