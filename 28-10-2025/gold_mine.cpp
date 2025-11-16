// gold_mine.cpp
// Approach: dp[i][j] = gold[i][j] + max(dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1])
// Input: r c then r*c numbers
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c; if(!(cin>>r>>c)) return 0;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    vector<vector<int>> dp(r, vector<int>(c,0));
    for(int j=c-1;j>=0;j--){
        for(int i=0;i<r;i++){
            int right = (j+1<c) ? dp[i][j+1] : 0;
            int right_up = (i-1>=0 && j+1<c) ? dp[i-1][j+1] : 0;
            int right_down = (i+1<r && j+1<c) ? dp[i+1][j+1] : 0;
            dp[i][j] = g[i][j] + max({right, right_up, right_down});
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++) ans = max(ans, dp[i][0]);
    cout<<ans<<"\n";
    return 0;
}
