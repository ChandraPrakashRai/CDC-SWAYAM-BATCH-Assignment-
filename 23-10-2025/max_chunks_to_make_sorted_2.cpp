// Max Chunks To Make Sorted II (handles duplicates)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n), b;
    for(int i=0;i<n;i++) cin>>a[i];
    b = a;
    sort(b.begin(), b.end());
    long long leftSum=0, rightSum=0;
    unordered_map<long long,int> cnt;
    int res=0;
    for(int i=0;i<n;i++){
        leftSum += a[i];
        rightSum += b[i];
        if(leftSum==rightSum) res++;
    }
    cout<<res<<"\n";
    return 0;
}
