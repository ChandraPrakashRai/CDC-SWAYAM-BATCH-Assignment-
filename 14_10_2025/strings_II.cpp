// Problem: String II problems - frequency, max occurring char, remove duplicates, word count
// Each solved below separately.

#include <bits/stdc++.h>
using namespace std;

// 1. Frequency of characters
unordered_map<char,int> char_frequency(const string& s){
    unordered_map<char,int> freq;
    for(char c:s) if(isalpha(c)) freq[c]++;
    return freq;
}

// 2. Max occurring character
char max_occur_char(const string& s){
    auto freq = char_frequency(s);
    char ans=0; int mx=0;
    for(auto &p:freq) if(p.second>mx) mx=p.second, ans=p.first;
    return ans;
}

// 3. Remove duplicate characters
string remove_duplicate_chars(const string& s){
    string res; unordered_set<char> seen;
    for(char c:s) if(!seen.count(c)){ res+=c; seen.insert(c); }
    return res;
}

// 4. Count words
int count_words(const string& s){
    stringstream ss(s); string word; int cnt=0;
    while(ss>>word) cnt++;
    return cnt;
}

int main(){
    string s="hello world hello cpp";
    cout<<"Max char: "<<max_occur_char(s)<<"\n";
    cout<<"Unique: "<<remove_duplicate_chars(s)<<"\n";
    cout<<"Words: "<<count_words(s)<<"\n";
    return 0;
}
