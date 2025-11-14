
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
unordered_map<int,int>mp; int sum=0,ans=0; mp[0]=-1;
for(int i=0;i<n;i++){ sum+=a[i]; if(mp.count(sum)) ans=max(ans,i-mp[sum]); else mp[sum]=i;}
cout<<ans;}
