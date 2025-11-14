
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
int xo=0; for(int i=0;i<=n;i++) xo^=i;
for(int x:a) xo^=x; cout<<xo;}
