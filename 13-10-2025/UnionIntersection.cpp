// Problem: UnionIntersection
// Description: Union and intersection
// Brute-force complexity: O(n+m)
// Optimized complexity: O(n+m)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,2,4}, b={2,3,4}; set<int> s(a.begin(), a.end()); s.insert(b.begin(), b.end()); for(int x:s) cout<<x<<" "; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={1,2,4}, b={2,3,4}; int i=0,j=0; vector<int> uni, inter; while(i<a.size() && j<b.size()){ if(a[i]==b[j]){ inter.push_back(a[i]); uni.push_back(a[i]); i++; j++; } else if(a[i]<b[j]) uni.push_back(a[i++]); else uni.push_back(b[j++]); } while(i<a.size()) uni.push_back(a[i++]); while(j<b.size()) uni.push_back(b[j++]); for(int x:uni) cout<<x<<" "; cout<<"\n"; for(int x:inter) cout<<x<<" "; }
