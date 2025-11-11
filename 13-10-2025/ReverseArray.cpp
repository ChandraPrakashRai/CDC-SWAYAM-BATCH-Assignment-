// Problem: ReverseArray
// Description: Reverse an array
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,2,3,4,5}; vector<int> b(a.rbegin(), a.rend()); for(int x:b) cout<<x<<" "; return 0; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& a){ int l=0,r=a.size()-1; while(l<r) swap(a[l++], a[r--]); } int main(){ vector<int>a={1,2,3,4,5}; reverseArray(a); for(int x:a) cout<<x<<" "; }
