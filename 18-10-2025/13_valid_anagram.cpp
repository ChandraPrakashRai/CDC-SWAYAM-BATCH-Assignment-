
#include <bits/stdc++.h>
using namespace std;
int main(){string s,t;cin>>s>>t;if(s.size()!=t.size()){cout<<0;return 0;}
vector<int>f(26);for(char c:s)f[c-'a']++;for(char c:t)f[c-'a']--;
for(int x:f) if(x){cout<<0;return 0;} cout<<1;}
