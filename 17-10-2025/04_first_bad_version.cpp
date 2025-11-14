// 04_first_bad_version.cpp
// Given API isBadVersion(version). Here we simulate by reading n then list of versions (0/1).
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> bad(n+1);
    for(int i=1;i<=n;i++) cin>>bad[i];
    int l=1, r=n, ans=n+1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(bad[m]){
            ans = m;
            r = m-1;
        } else l = m+1;
    }
    if(ans==n+1) cout<<"-1\n"; else cout<<ans<<"\n";
    return 0;
}
