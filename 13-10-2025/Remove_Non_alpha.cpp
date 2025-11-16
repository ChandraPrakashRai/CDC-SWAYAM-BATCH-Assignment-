#include <bits/stdc++.h>
using namespace std;
// Remove all except alphabets
int main(){
    string s="ab#1c@D!";
    string t="";
    for(char ch:s) if(isalpha(ch)) t+=ch;
    cout<<t;
}
