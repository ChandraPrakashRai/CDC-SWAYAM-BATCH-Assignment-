// Minimum Platforms required for trains
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> arr(n), dep(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>dep[i];
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i=0,j=0,plat=0,res=0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){ plat++; res=max(res,plat); i++; }
        else { plat--; j++; }
    }
    cout<<res<<"\n";
    return 0;
}
