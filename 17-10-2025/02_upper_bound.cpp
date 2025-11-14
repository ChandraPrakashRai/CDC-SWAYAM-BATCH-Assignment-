// 02_upper_bound.cpp
// Implements std::upper_bound (first index with value > target) on sorted vector
#include <bits/stdc++.h>
using namespace std;
int upper_bound_idx(const vector<int>& a, int target){
    int l=0, r=(int)a.size();
    while(l<r){
        int m = l + (r-l)/2;
        if(a[m] <= target) l = m+1;
        else r = m;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    int target; cin>>target;
    cout<<upper_bound_idx(a,target)<<"\n";
    return 0;
}
