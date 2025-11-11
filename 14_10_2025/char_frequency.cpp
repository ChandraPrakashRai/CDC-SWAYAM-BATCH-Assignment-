// Problem: Calculate frequency of a character in a string
// Brief: Count occurrences of each character or a given character.
// Time: O(n), Space: O(1) or O(k) where k=alphabet size.

#include <bits/stdc++.h>
using namespace std;

int freq_of_char(const string &s, char target){
    int cnt=0;
    for(char c:s) if(c==target) cnt++;
    return cnt;
}

int main(){
    string s="hello world";
    cout<<freq_of_char(s,'l')<<"\n";
    return 0;
}
