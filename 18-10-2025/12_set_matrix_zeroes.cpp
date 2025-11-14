
#include <bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>a(n,vector<int>(m));
for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
vector<int>r(n),c(m);
for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]==0)r[i]=c[j]=1;
for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(r[i]||c[j])a[i][j]=0;
for(auto &x:a){for(int v:x)cout<<v<<" ";cout<<"
";}
}
