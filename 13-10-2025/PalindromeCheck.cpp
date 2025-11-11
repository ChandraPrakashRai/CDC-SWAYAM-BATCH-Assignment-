// Problem: PalindromeCheck
// Description: Palindrome check
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

bool isPal(string s){ string t=""; for(char c:s) if(isalpha(c)) t+=tolower(c); string r=t; reverse(r.begin(), r.end()); return t==r; } int main(){ cout<<isPal("A man, a plan, a canal: Panama"); }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

bool isPal(string s){ int i=0,j=s.size()-1; while(i<j){ while(i<j && !isalpha(s[i])) i++; while(i<j && !isalpha(s[j])) j--; if(tolower(s[i])!=tolower(s[j])) return false; i++; j--; } return true; } int main(){ cout<<isPal("A man, a plan, a canal: Panama"); }
