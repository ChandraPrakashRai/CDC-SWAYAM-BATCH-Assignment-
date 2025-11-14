
#include <bits/stdc++.h>
using namespace std;
int main(){string s,t;cin>>s>>t;int bulls=0,cows=0;
vector<int>cs(10),ct(10);
for(int i=0;i<s.size();i++){
 if(s[i]==t[i]) bulls++;
 else {cs[s[i]-'0']++; ct[t[i]-'0']++;}
}
for(int i=0;i<10;i++) cows+=min(cs[i],ct[i]);
cout<<bulls<<" "<<cows;}
