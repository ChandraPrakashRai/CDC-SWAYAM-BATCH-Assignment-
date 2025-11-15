// Print all subsets (power set) of an array (handles duplicates by position)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int total = 1<<n;
    for(int mask=0; mask<total; ++mask){
        vector<int> subset;
        for(int i=0;i<n;i++) if(mask & (1<<i)) subset.push_back(a[i]);
        // print subset
        cout<<"[";
        for(size_t i=0;i<subset.size();++i){
            if(i) cout<<' ';
            cout<<subset[i];
        }
        cout<<"]\n";
    }
    return 0;
}
