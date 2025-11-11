// Problem: RemoveNonAlpha
// Description: Remove non-alpha chars
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ string s="a1b2c!"; string t=""; for(char ch:s) if(isalpha(ch)) t+=ch; cout<<t; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ string s="a1b2c!"; int idx=0; for(int i=0;i<s.size();++i) if(isalpha(s[i])) s[idx++]=s[i]; s.resize(idx); cout<<s; }
