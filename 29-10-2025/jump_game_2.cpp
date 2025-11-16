// jump_game_2.cpp
// Input: n then n integers (max jump lengths). Output minimal jumps to reach last index.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<=1){ cout<<0<<"\n"; return 0; }
    int jumps = 0, curEnd = 0, furthest = 0;
    for(int i=0;i<n-1;i++){
        furthest = max(furthest, i + a[i]);
        if(i == curEnd){
            jumps++;
            curEnd = furthest;
        }
    }
    cout<<jumps<<"\n";
    return 0;
}
