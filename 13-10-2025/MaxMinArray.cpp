// Problem: MaxMinArray
// Description: Find max and min
// Brute-force complexity: O(n)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={3,1,7,2}; cout<<*max_element(a.begin(),a.end())<<" "<<*min_element(a.begin(),a.end()); }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={3,1,7,2}; int mx=a[0], mn=a[0]; for(int x:a){ mx=max(mx,x); mn=min(mn,x);} cout<<mx<<" "<<mn; }
