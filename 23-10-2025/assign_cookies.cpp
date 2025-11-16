// Assign Cookies (LeetCode 455) - greedy
// Input: first line g (number of children), then g integers (greed factors).
// Next line s (number of cookies), then s integers (sizes).
// Output: maximum number of content children.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int g;
    if(!(cin>>g)) return 0;
    vector<int> greed(g);
    for(int i=0;i<g;++i) cin>>greed[i];
    int s; cin>>s;
    vector<int> size(s);
    for(int i=0;i<s;++i) cin>>size[i];
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());
    int i=0,j=0,ans=0;
    while(i<g && j<s){
        if(size[j] >= greed[i]) { ++ans; ++i; ++j;}
        else ++j;
    }
    cout<<ans<<"\n";
    return 0;
}
