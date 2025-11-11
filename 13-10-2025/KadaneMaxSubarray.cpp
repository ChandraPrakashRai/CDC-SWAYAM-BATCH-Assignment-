// Problem: KadaneMaxSubarray
// Description: Kadane's algorithm
// Brute-force complexity: O(n^2)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int maxSub(vector<int>& a){ int n=a.size(), best=INT_MIN; for(int i=0;i<n;++i){ int s=0; for(int j=i;j<n;++j){ s+=a[j]; best=max(best,s); } } return best; } int main(){ vector<int>a={-2,1,-3,4,-1,2,1,-5,4}; cout<<maxSub(a); }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int maxSub(vector<int>& a){ int cur=0, best=INT_MIN; for(int x:a){ cur = max(x, cur+x); best = max(best, cur); } return best; } int main(){ vector<int>a={-2,1,-3,4,-1,2,1,-5,4}; cout<<maxSub(a); }
