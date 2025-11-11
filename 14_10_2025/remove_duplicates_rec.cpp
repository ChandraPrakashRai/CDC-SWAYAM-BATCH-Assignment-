// Problem: Remove duplicate characters using recursion (preserve first occurrence)
// Time: O(n^2) naive due to string find in recursion, Space: O(n).

#include <bits/stdc++.h>
using namespace std;

string removeDupRec(const string &s, int i=0, string seen=""){
    if(i >= (int)s.size()) return "";
    char c = s[i];
    if(seen.find(c) != string::npos) return removeDupRec(s, i+1, seen);
    return string(1,c) + removeDupRec(s, i+1, seen + c);
}

int main(){
    cout<<removeDupRec("abacb")<<"\n";
    return 0;
}
