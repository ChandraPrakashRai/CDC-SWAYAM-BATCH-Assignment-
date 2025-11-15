// Rat in a maze - print all paths from (0,0) to (n-1,n-1)
// Moves allowed: Down, Right, Up, Left (will print paths as sequences of coordinates)
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int,int>> cur;
vector<vector<int>> vis;
vector<vector<pair<int,int>>> all;
void dfs(int r,int c){
    if(r<0||c<0||r>=n||c>=n) return;
    if(!a[r][c] || vis[r][c]) return;
    cur.emplace_back(r,c);
    vis[r][c]=1;
    if(r==n-1 && c==n-1){
        all.push_back(cur);
    } else {
        const int dr[4]={1,0,0,-1}, dc[4]={0,1,-1,0};
        for(int k=0;k<4;k++) dfs(r+dr[k], c+dc[k]);
    }
    vis[r][c]=0;
    cur.pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n)) return 0;
    a.assign(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    vis.assign(n, vector<int>(n,0));
    dfs(0,0);
    if(all.empty()){ cout<<"NO PATHS\n"; return 0; }
    for(size_t i=0;i<all.size();++i){
        for(auto &p: all[i]) cout<<p.first<<","<<p.second<<" ";
        cout<<"\n";
    }
    return 0;
}
