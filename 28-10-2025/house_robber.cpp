// house_robber.cpp
// Input: n then n house values
// Output: max amount can rob (no adjacent houses)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==0){ cout<<0<<"\n"; return 0; }
    if(n==1){ cout<<a[0]<<"\n"; return 0; }
    ll prev2 = a[0], prev1 = max(a[0], a[1]);
    for(int i=2;i<n;i++){
        ll cur = max(prev1, prev2 + a[i]);
        prev2 = prev1; prev1 = cur;
    }
    cout<<prev1<<"\n";
    return 0;
}
