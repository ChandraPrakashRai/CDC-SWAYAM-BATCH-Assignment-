// 06_search_rotated_sorted_array_ii.cpp
// Search target in rotated sorted array WITH duplicates. Returns true/false.
#include <bits/stdc++.h>
using namespace std;
bool search_rotated_dup(vector<int>& a, int target){
    int l=0, r=(int)a.size()-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==target) return true;
        if(a[l]==a[m] && a[m]==a[r]){ l++; r--; }
        else if(a[l] <= a[m]){
            if(a[l] <= target && target < a[m]) r = m-1;
            else l = m+1;
        } else {
            if(a[m] < target && target <= a[r]) l = m+1;
            else r = m-1;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    int target; cin>>target;
    cout<<(search_rotated_dup(a,target) ? "1\n" : "0\n");
    return 0;
}
