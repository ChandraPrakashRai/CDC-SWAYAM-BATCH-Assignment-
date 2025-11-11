// Problem: RemoveDuplicatesSorted
// Description: Remove duplicates in sorted array
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,1,2}; set<int> s(a.begin(), a.end()); for(int x:s) cout<<x<<" "; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,1,2}; int i=0; for(int j=1;j<a.size();++j) if(a[j]!=a[i]) a[++i]=a[j]; for(int k=0;k<=i;++k) cout<<a[k]<<" "; }
