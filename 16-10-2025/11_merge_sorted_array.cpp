// 11_merge_sorted_array.cpp
// Problem: Merge two sorted arrays where first has enough space at end (LeetCode merge).
//
// Brute-force idea:
//   Copy and sort -> O((m+n)log(m+n))
//
// Optimized approach:
//   Merge from end using three pointers to avoid extra space.
//
// Complexity: O(m+n) time, O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

void mergeSorted(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, k=m+n-1;
    while(j>=0) {
        if(i>=0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    mergeSorted(nums1,3,nums2,3);
    for(int x: nums1) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
