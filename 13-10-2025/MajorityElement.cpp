// Problem: MajorityElement
// Description: Moore's voting
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={3,2,3}; unordered_map<int,int> m; for(int x:a) if(++m[x]>a.size()/2) cout<<x; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int majority(vector<int>& a){ int count=0, cand=0; for(int x:a){ if(count==0) cand=x; count += (x==cand)?1:-1; } int cnt=0; for(int x:a) if(x==cand) cnt++; return cnt>a.size()/2?cand:-1; } int main(){ vector<int>a={3,2,3}; cout<<majority(a); }
