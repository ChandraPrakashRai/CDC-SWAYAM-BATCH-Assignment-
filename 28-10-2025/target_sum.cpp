// target_sum.cpp
// Transform to subset-sum: count ways to get sum (pos - neg = S) => pos = (sum + S)/2
// Input: n, array of n non-negative ints, then S
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    long long total = 0;
    for(int i=0;i<n;i++){ cin>>a[i]; total += a[i]; }
    int S; cin>>S;
    if( (total + S) % 2 != 0 || abs(S) > total ){ cout<<0<<"\n"; return 0; }
    int target = (total + S)/2;
    vector<ll> dp(target+1, 0);
    dp[0] = 1;
    for(int x: a){
        for(int j=target; j>=x; --j) dp[j] += dp[j-x];
    }
    cout<<dp[target]<<"\n";
    return 0;
}
