// Problem: CountVowelConsonant
// Description: Count vowels and consonants
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ string s="hello"; int v=0,c=0; for(char ch:s) if(isalpha(ch)){ char l=tolower(ch); if(string("aeiou").find(l)!=string::npos) v++; else c++; } cout<<v<<" "<<c; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ string s="hello"; int v=0,c=0; for(char ch:s) if(isalpha(ch)){ char l=tolower(ch); if(l=='a'||l=='e'||l=='i'||l=='o'||l=='u') v++; else c++; } cout<<v<<" "<<c; }
