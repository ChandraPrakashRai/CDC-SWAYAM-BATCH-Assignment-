// 01_lower_bound.cpp
// Implements std::lower_bound (first index with value >= target) on sorted vector
#include <bits/stdc++.h>
using namespace std;
int lower_bound_idx(const vector<int>& a, int target){
    int l=0, r=(int)a.size(); // [l, r)
    while(l<r){
        int m = l + (r-l)/2;
        if(a[m] < target) l = m+1;
        else r = m;
    }
    return l; // may be a.size() if not found
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    int target; cin>>target;
    cout<<lower_bound_idx(a,target)<<"\n";
    return 0;
}
