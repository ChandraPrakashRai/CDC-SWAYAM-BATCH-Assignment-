// Array Partition (LeetCode 561) - maximize sum of min pairs
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(), a.end());
    long long sum=0;
    for(int i=0;i<n;i+=2) sum += a[i];
    cout<<sum<<"\n";
    return 0;
}
