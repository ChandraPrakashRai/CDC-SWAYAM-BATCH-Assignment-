#include <bits/stdc++.h>
using namespace std;
// Count vowels and consonants
int main(){
    string s="HelloWorld";
    int v=0,c=0;
    string vow="aeiouAEIOU";
    for(char ch:s){
        if(isalpha(ch)){
            if(vow.find(ch)!=string::npos) v++;
            else c++;
        }
    }
    cout<<v<<" "<<c;
}
