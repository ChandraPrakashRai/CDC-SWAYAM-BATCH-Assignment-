// Problem: RunningSum1D
// Description: Running sum
// Brute-force complexity: O(n)
// Optimized complexity: O(n^2)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,2,3,4}; for(size_t i=1;i<a.size();++i) a[i]+=a[i-1]; for(int x:a) cout<<x<<" "; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,2,3,4}; vector<int> r(a.size()); for(size_t i=0;i<a.size();++i){ int s=0; for(size_t j=0;j<=i;++j) s+=a[j]; r[i]=s;} for(int x:r) cout<<x<<" "; }
