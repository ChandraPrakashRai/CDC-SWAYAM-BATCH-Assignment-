// fibonacci_memo_tab.cpp
// Approach: both memoization (top-down) and tabulation (bottom-up) shown.
// Input: n
// Output: fibonacci(n) (0-indexed) using 64-bit
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fib_memo(int n, vector<ll>& dp){
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib_memo(n-1, dp) + fib_memo(n-2, dp);
}

ll fib_tab(int n){
    if(n<=1) return n;
    vector<ll> dp(n+1);
    dp[0]=0; dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    // choose one: memo or tab
    vector<ll> dp(n+1, -1);
    cout << fib_memo(n, dp) << "\n";
    // cout << fib_tab(n) << "\n";
    return 0;
}
