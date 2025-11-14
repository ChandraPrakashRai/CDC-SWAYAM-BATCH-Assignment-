
#include <bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>mp;
for(char c:s)mp[c]++;char ans=0;int mx=0;
for(auto&p:mp)if(p.second>mx){mx=p.second;ans=p.first;}
cout<<ans;}
