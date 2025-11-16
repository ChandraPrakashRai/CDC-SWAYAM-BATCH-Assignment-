// min_cost_climbing_stairs.cpp
// Approach: dynamic programming
// Input: n then n costs (cost[0..n-1])
// Output: min cost to reach top (past n-1)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<ll> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];
    if(n==0){ cout<<0<<"\n"; return 0; }
    if(n==1){ cout<<cost[0]<<"\n"; return 0; }
    vector<ll> dp(n+1, 0); // dp[i] cost to reach step i
    dp[0]=0; dp[1]=cost[0];
    for(int i=2;i<=n;i++){
        ll c = (i-1 < n ? cost[i-1] : 0);
        dp[i] = min(dp[i-1] + c, dp[i-2] + ( (i-2< n) ? cost[i-2] : 0));
    }
    cout<<dp[n]<<"\n";
    return 0;
}
