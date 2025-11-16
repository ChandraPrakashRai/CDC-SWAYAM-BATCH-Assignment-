// unique_paths.cpp
// Input: m n (rows, cols)
// Output: number of unique paths from (0,0) to (m-1,n-1) moving right/down
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; if(!(cin>>m>>n)) return 0;
    vector<vector<ll>> dp(m, vector<ll>(n,0));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        if(i==0 && j==0) dp[i][j]=1;
        else dp[i][j] = ( (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0) );
    }
    cout<<dp[m-1][n-1]<<"\n";
    return 0;
}
