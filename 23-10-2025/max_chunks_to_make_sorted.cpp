// Max Chunks To Make Sorted (LeetCode 769) - distinct 0..n-1
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mx = -1, cnt=0;
    for(int i=0;i<n;i++){
        mx = max(mx, a[i]);
        if(mx == i) cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
