// Find all unique subsets from array with possible duplicate elements
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    vector<int> cur;
    function<void(int)> dfs = [&](int idx){
        res.push_back(cur);
        for(int i=idx;i<n;i++){
            if(i>idx && a[i]==a[i-1]) continue;
            cur.push_back(a[i]);
            dfs(i+1);
            cur.pop_back();
        }
    };
    dfs(0);
    for(auto &v:res){
        cout<<"[";
        for(size_t i=0;i<v.size();++i){
            if(i) cout<<' ';
            cout<<v[i];
        }
        cout<<"]\n";
    }
    return 0;
}
