
#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> mp;
    int q;cin>>q;
    while(q--){
        string op;cin>>op;
        if(op=="put"){string k;int v;cin>>k>>v;mp[k]=v;}
        else if(op=="get"){string k;cin>>k;cout<<(mp.count(k)?mp[k]:-1)<<" ";}
        else if(op=="containsKey"){string k;cin>>k;cout<<(mp.count(k)?1:0)<<" ";}
        else if(op=="keySet"){
            for(auto &p:mp) cout<<p.first<<" ";
        }
    }
}
