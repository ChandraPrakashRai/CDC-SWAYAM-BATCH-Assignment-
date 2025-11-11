// 07_two_sum.cpp
// Problem: Two Sum - return indices of two numbers that add up to target.
//
// Brute-force idea:
//   Check every pair (i,j) -> O(n^2).
//
// Optimized approach:
//   Use hashmap value -> index. For each nums[i], check if target-nums[i] exists.
//   O(n) time, O(n) space.
//
// Complexity: O(n) time, O(n) space.

#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoSumBrute(const vector<int>& a, int target) {
    int n=a.size();
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]+a[j]==target) return {i,j};
    return {-1,-1};
}

pair<int,int> twoSum(const vector<int>& a, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<(int)a.size();++i){
        int need = target - a[i];
        if(mp.count(need)) return {mp[need], i};
        mp[a[i]] = i;
    }
    return {-1,-1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {2,7,11,15};
    auto p = twoSum(a,9);
    cout<<p.first<<" "<<p.second<<"\n"; // 0 1
    return 0;
}
