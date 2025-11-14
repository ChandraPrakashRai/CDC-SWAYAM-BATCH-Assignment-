// 07_aggressive_cows.cpp
// Aggressive cows: maximize minimal distance between cows placed in stalls
#include <bits/stdc++.h>
using namespace std;
bool canPlace(const vector<int>& stalls, int cows, int minDist){
    int count=1, last=stalls[0];
    for(size_t i=1;i<stalls.size();++i){
        if(stalls[i]-last >= minDist){ count++; last = stalls[i]; if(count==cows) return true; }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,c; if(!(cin>>n>>c)) return 0;
    vector<int> stalls(n);
    for(int i=0;i<n;++i) cin>>stalls[i];
    sort(stalls.begin(), stalls.end());
    int lo=1, hi = stalls.back()-stalls.front(), ans=0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(canPlace(stalls,c,mid)){ ans = mid; lo = mid+1; }
        else hi = mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}
