
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
unordered_map<int,int>mp; long long sum=0,ans=0; mp[0]=1;
for(int x:a){ sum+=x; if(mp.count(sum)) ans+=mp[sum]; mp[sum]++; }
cout<<ans;}
