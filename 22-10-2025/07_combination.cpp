// Generate combinations: given n and k, list all combinations (1..n choose k)
// Input: n k
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    if(!(cin>>n>>k)) return 0;
    vector<int> cur;
    function<void(int)> dfs = [&](int start){
        if((int)cur.size()==k){
            for(size_t i=0;i<cur.size();++i){
                if(i) cout<<" ";
                cout<<cur[i];
            }
            cout<<"\n";
            return;
        }
        for(int v=start; v<=n; ++v){
            cur.push_back(v);
            dfs(v+1);
            cur.pop_back();
        }
    };
    dfs(1);
    return 0;
}
