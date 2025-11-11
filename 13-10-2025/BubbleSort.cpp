// Problem: BubbleSort
// Description: Bubble sort
// Brute-force complexity: O(n^2)
// Optimized complexity: O(n) best
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int>& a){ int n=a.size(); for(int i=0;i<n-1;++i) for(int j=0;j<n-i-1;++j) if(a[j]>a[j+1]) swap(a[j],a[j+1]); } int main(){ vector<int>a={5,1,4,2,8}; bubble(a); for(int x:a) cout<<x<<" "; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

void bubbleOpt(vector<int>& a){ int n=a.size(); for(int i=0;i<n-1;++i){ bool swapped=false; for(int j=0;j<n-i-1;++j) if(a[j]>a[j+1]){ swap(a[j],a[j+1]); swapped=true; } if(!swapped) break; } } int main(){ vector<int>a={5,1,4,2,8}; bubbleOpt(a); for(int x:a) cout<<x<<" "; }
