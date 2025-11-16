// Coin Change (minimum coins) - Unbounded knapsack / DP
// Input: amount n, m (number of coin types), then m coin values.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int amount;
    if(!(cin>>amount)) return 0;
    int m; cin>>m;
    vector<int> coins(m);
    for(int i=0;i<m;i++) cin>>coins[i];
    const int INF = 1e9;
    vector<int> dp(amount+1, INF);
    dp[0]=0;
    for(int c: coins){
        for(int x=c;x<=amount;++x) dp[x]=min(dp[x], dp[x-c]+1);
    }
    if(dp[amount]>=INF) cout<<-1<<"\n"; else cout<<dp[amount]<<"\n";
    return 0;
}
