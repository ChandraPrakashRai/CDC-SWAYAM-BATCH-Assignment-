// Combination Sum (unlimited use). Given n numbers and target, print all unique combinations
// Input: m (count) then m numbers, then target
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    if(!(cin>>m)) return 0;
    vector<int> candidates(m);
    for(int i=0;i<m;i++) cin>>candidates[i];
    int target; cin>>target;
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    vector<vector<int>> ans;
    function<void(int,int)> dfs = [&](int idx,int sum){
        if(sum==target){ ans.push_back(cur); return; }
        if(sum>target) return;
        for(int i=idx;i<m;i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            dfs(i, sum + candidates[i]); // not i+1 because unlimited use
            cur.pop_back();
        }
    };
    dfs(0,0);
    for(auto &v: ans){
        for(size_t i=0;i<v.size();++i){
            if(i) cout<<" ";
            cout<<v[i];
        }
        cout<<"\n";
    }
    if(ans.empty()) cout<<"NO COMBINATION\n";
    return 0;
}
