// 05_search_rotated_sorted_array.cpp
// Search target in rotated sorted array without duplicates. Return index or -1.
#include <bits/stdc++.h>
using namespace std;
int search_rotated(const vector<int>& a, int target){
    int n=a.size();
    int l=0,r=n-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==target) return m;
        if(a[l] <= a[m]){ // left sorted
            if(a[l] <= target && target < a[m]) r = m-1;
            else l = m+1;
        } else { // right sorted
            if(a[m] < target && target <= a[r]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    int target; cin>>target;
    cout<<search_rotated(a,target)<<"\n";
    return 0;
}
