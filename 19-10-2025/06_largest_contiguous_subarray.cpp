
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
int ans=1;
for(int i=0;i<n;i++){ int mn=a[i],mx=a[i]; unordered_set<int>s; s.insert(a[i]);
 for(int j=i+1;j<n;j++){ if(s.count(a[j])) break; s.insert(a[j]);
  mn=min(mn,a[j]); mx=max(mx,a[j]);
  if(mx-mn==j-i) ans=max(ans,j-i+1);
 }
}
cout<<ans;}
