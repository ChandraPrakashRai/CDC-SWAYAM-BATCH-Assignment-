
#include <bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>a(n),b(m);
for(int&i:a)cin>>i;for(int&i:b)cin>>i;
unordered_set<int>s(a.begin(),a.end());
unordered_set<int>ans;
for(int x:b) if(s.count(x)) ans.insert(x);
for(int x:ans) cout<<x<<" ";
}
