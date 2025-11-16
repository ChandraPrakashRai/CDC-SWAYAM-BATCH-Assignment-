// unique_paths_2.cpp
// Input: m n then m rows of n values (0 or 1). 1 = obstacle
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; if(!(cin>>m>>n)) return 0;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
    vector<vector<ll>> dp(m, vector<ll>(n,0));
    if(grid[0][0]==0) dp[0][0]=1;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        if(grid[i][j]==1) { dp[i][j]=0; continue; }
        if(i==0 && j==0) continue;
        dp[i][j] = ( (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0) );
    }
    cout<<dp[m-1][n-1]<<"\n";
    return 0;
}
