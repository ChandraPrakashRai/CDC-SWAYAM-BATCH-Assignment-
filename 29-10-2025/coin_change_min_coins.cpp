// coin_change_min_coins.cpp
// Input: amount k, then m (number of coin types), then m coin values
// Output: minimum number of coins to form amount or -1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int amount; if(!(cin>>amount)) return 0;
    int m; cin>>m;
    vector<int> coins(m);
    for(int i=0;i<m;i++) cin>>coins[i];
    vector<ll> dp(amount+1, INF);
    dp[0]=0;
    for(int c: coins){
        for(int x=c; x<=amount; ++x) dp[x] = min(dp[x], dp[x-c] + 1);
    }
    if(dp[amount] >= INF) cout<<-1<<"\n"; else cout<<dp[amount]<<"\n";
    return 0;
}
