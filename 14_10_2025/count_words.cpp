// Problem: Count number of words in a string
// Brief: Words are separated by whitespace; handle multiple spaces.
// Time: O(n), Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int count_words(const string &s){
    stringstream ss(s);
    string w; int cnt=0;
    while(ss>>w) cnt++;
    return cnt;
}

int main(){
    cout<<count_words("  this is   a test ")<<"\n";
    return 0;
}
