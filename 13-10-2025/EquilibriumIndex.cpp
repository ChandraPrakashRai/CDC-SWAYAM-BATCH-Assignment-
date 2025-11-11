// Problem: EquilibriumIndex
// Description: Find equilibrium index
// Brute-force complexity: O(n^2)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,3,5,2,2}; for(int i=0;i<a.size();++i){ int L=0,R=0; for(int j=0;j<i;++j) L+=a[j]; for(int j=i+1;j<a.size();++j) R+=a[j]; if(L==R) cout<<i; } }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,3,5,2,2}; int total=0; for(int x:a) total+=x; int left=0; for(int i=0;i<a.size();++i){ if(left==total-left-a[i]) cout<<i; left+=a[i]; } }
