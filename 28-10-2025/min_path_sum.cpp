// min_path_sum.cpp
// Input: m n then m rows of n ints
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; if(!(cin>>m>>n)) return 0;
    vector<vector<ll>> g(m, vector<ll>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    vector<vector<ll>> dp(m, vector<ll>(n, 0));
    dp[0][0]=g[0][0];
    for(int i=1;i<m;i++) dp[i][0] = dp[i-1][0] + g[i][0];
    for(int j=1;j<n;j++) dp[0][j] = dp[0][j-1] + g[0][j];
    for(int i=1;i<m;i++) for(int j=1;j<n;j++)
        dp[i][j] = g[i][j] + min(dp[i-1][j], dp[i][j-1]);
    cout<<dp[m-1][n-1]<<"\n";
    return 0;
}
