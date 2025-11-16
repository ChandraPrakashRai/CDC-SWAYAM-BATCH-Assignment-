"#include <bits/stdc++.h>
using namespace std;
// Maximum product subarray
int main(){
    vector<int>a={2,3,-2,4};
    int mx=a[0], mn=a[0], ans=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]<0) swap(mx,mn);
        mx=max(a[i], mx*a[i]);
        mn=min(a[i], mn*a[i]);
        ans=max(ans,mx);
    }
    cout<<ans;
}
