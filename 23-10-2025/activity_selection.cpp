// Activity Selection (interval scheduling maximization)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end(), [](auto &x, auto &y){ return x.second < y.second; });
    int cnt=0, last_end = -1e9;
    for(auto &p: a){
        if(p.first >= last_end){
            cnt++;
            last_end = p.second;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
