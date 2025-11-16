// perfect_squares.cpp
// Approach: dp[i] = min over j: dp[i - j*j] + 1
// Input: n
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> dp(n+1, INT_MAX/2);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
