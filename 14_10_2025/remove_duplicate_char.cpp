// Problem: Remove duplicate characters from a string (preserve first occurrence)
// Brief: Return string with first occurrence preserved.
// Time: O(n), Space: O(k).

#include <bits/stdc++.h>
using namespace std;

string remove_duplicates(const string &s){
    vector<bool> seen(256,false);
    string res;
    for(char c:s) if(!seen[(unsigned char)c]){ res.push_back(c); seen[(unsigned char)c]=true; }
    return res;
}

int main(){
    cout<<remove_duplicates("abacb")<<"\n";
    return 0;
}
