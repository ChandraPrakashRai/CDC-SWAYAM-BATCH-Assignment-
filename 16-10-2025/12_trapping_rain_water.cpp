// 12_trapping_rain_water.cpp
// Problem: Trapping Rain Water - given heights, compute total trapped water.
//
// Brute-force idea:
//   For each index, compute left max and right max by scanning -> O(n^2).
//
// Optimized approach:
//   Precompute leftMax and rightMax arrays -> O(n) time, O(n) space.
//   Or two-pointer approach: keep left,right pointers and update water using min of leftMax/rightMax -> O(1) extra space.
//
// Complexity: O(n) time, O(1) extra space (two-pointer) or O(n) space for precompute.

#include <bits/stdc++.h>
using namespace std;

int trapBrute(const vector<int>& h) {
    int n=h.size(), ans=0;
    for(int i=0;i<n;i++){
        int l=0,r=0;
        for(int j=0;j<=i;j++) l = max(l,h[j]);
        for(int j=i;j<n;j++) r = max(r,h[j]);
        ans += min(l,r)-h[i];
    }
    return ans;
}

int trapTwoPointer(const vector<int>& h) {
    int l=0, r=h.size()-1;
    int leftMax=0, rightMax=0;
    int ans=0;
    while(l<r){
        if(h[l] < h[r]) {
            if(h[l] >= leftMax) leftMax = h[l];
            else ans += leftMax - h[l];
            l++;
        } else {
            if(h[r] >= rightMax) rightMax = h[r];
            else ans += rightMax - h[r];
            r--;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapTwoPointer(h) << "\n"; // 6
    return 0;
}
