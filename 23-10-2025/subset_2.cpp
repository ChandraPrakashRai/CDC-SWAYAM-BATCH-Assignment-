// Subsets II (handle duplicates) - backtracking
// Given a list of integers that may contain duplicates, return all possible subsets (no duplicate subsets).
#include <bits/stdc++.h>
using namespace std;
void dfs(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = idx; i < (int)nums.size(); ++i) {
        if (i > idx && nums[i] == nums[i-1]) continue; // skip duplicates
        cur.push_back(nums[i]);
        dfs(i+1, nums, cur, res);
        cur.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> nums(n);
    for(int i=0;i<n;++i) cin>>nums[i];
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    dfs(0, nums, cur, res);
    for(auto &v: res){
        for(size_t i=0;i<v.size();++i){
            if(i) cout<<" ";
            cout<<v[i];
        }
        cout<<"\n";
    }
    return 0;
}
