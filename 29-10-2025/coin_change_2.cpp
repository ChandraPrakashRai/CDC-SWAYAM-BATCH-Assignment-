// coin_change_2.cpp
// Count the number of ways to make amount using coins (combinations, unlimited coins)
// Input: amount, m, coin values
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int amount; if(!(cin>>amount)) return 0;
    int m; cin>>m;
    vector<int> coins(m);
    for(int i=0;i<m;i++) cin>>coins[i];
    vector<ll> dp(amount+1, 0);
    dp[0]=1;
    for(int c: coins){
        for(int x=c; x<=amount; ++x) dp[x] += dp[x-c];
    }
    cout<<dp[amount]<<"\n";
    return 0;
}
