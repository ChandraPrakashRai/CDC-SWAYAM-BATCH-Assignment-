// Problem: Print maximum occurring character in a string
// Brief: Find character with highest frequency.
// Time: O(n), Space: O(1) or O(k).

#include <bits/stdc++.h>
using namespace std;

char max_occuring_char(const string &s){
    vector<int> cnt(256,0);
    for(char c:s) cnt[(unsigned char)c]++;
    int mx=0; char ans=0;
    for(int i=0;i<256;i++) if(cnt[i]>mx){ mx=cnt[i]; ans=char(i); }
    return ans;
}

int main(){
    cout<<max_occuring_char("hello world")<<"\n";
    return 0;
}
