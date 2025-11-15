// Combination Sum II (each candidate may be used once). Input: m then m numbers then target
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    if(!(cin>>m)) return 0;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    int target; cin>>target;
    sort(a.begin(), a.end());
    vector<int> cur;
    vector<vector<int>> ans;
    function<void(int,int)> dfs = [&](int idx,int sum){
        if(sum==target){ ans.push_back(cur); return; }
        if(sum>target) return;
        for(int i=idx;i<m;i++){
            if(i>idx && a[i]==a[i-1]) continue;
            cur.push_back(a[i]);
            dfs(i+1, sum + a[i]);
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
