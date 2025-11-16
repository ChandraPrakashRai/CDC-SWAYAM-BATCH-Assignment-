// jump_game.cpp
// Input: n then n integers representing max jump length at each position
// Output: true or false
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int reach = 0;
    for(int i=0;i<n;i++){
        if(i>reach){ cout<<"false\n"; return 0; }
        reach = max(reach, i + a[i]);
    }
    cout<<"true\n";
    return 0;
}
