// 03_koko_eating_bananas.cpp
// Minimum eating speed K to finish piles within H hours (binary search on answer)
#include <bits/stdc++.h>
using namespace std;
long long hours_needed(const vector<int>& piles, long long k){
    long long hours=0;
    for(long long p: piles) hours += (p + k - 1) / k;
    return hours;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long H;
    if(!(cin>>n>>H)) return 0;
    vector<int> piles(n);
    for(int i=0;i<n;++i) cin>>piles[i];
    long long lo=1, hi=*max_element(piles.begin(), piles.end()), ans=hi;
    while(lo<=hi){
        long long mid = lo + (hi-lo)/2;
        if(hours_needed(piles, mid) <= H){
            ans = mid; hi = mid-1;
        } else lo = mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}
