// 10_container_with_most_water.cpp
// Problem: Container With Most Water - given heights, find max area formed by two lines.
//
// Brute-force idea:
//   Check all pairs (i,j) compute area -> O(n^2).
//
// Optimized approach:
//   Two-pointer: start l=0,r=n-1; compute area, move the pointer at smaller height inward.
//   O(n) time.
//
// Complexity: O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

int maxAreaBrute(const vector<int>& h) {
    int n=h.size(), ans=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans=max(ans, min(h[i],h[j])*(j-i));
    return ans;
}

int maxArea(const vector<int>& h) {
    int l=0, r=h.size()-1;
    int ans=0;
    while(l<r) {
        ans = max(ans, min(h[l],h[r])*(r-l));
        if(h[l] < h[r]) l++; else r--;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(h)<<"\n"; // 49
    return 0;
}
