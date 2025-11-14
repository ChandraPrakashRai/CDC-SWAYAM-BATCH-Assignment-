
#include <bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;cin>>t;
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
 if(mp.count(t-a[i])){cout<<mp[t-a[i]]<<" "<<i;return 0;}
 mp[a[i]]=i;
}
cout<<"-1 -1";
}
