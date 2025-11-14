
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
unordered_set<int>s(a.begin(),a.end());int ans=0;
for(int x:a){ if(!s.count(x-1)){ int y=x,c=0; while(s.count(y)){c++;y++;} ans=max(ans,c);} }
cout<<ans;}
