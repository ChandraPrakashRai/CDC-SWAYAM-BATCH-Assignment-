// Problem: InsertionSort
// Description: Insertion sort
// Brute-force complexity: O(n^2)
// Optimized complexity: O(n^2)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a){ int n=a.size(); for(int i=1;i<n;++i){ int key=a[i], j=i-1; while(j>=0 && a[j]>key){ a[j+1]=a[j]; j--; } a[j+1]=key; } } int main(){ vector<int>a={12,11,13,5,6}; insertionSort(a); for(int x:a) cout<<x<<" "; }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int main(){ vector<int>a={12,11,13,5,6}; sort(a.begin(), a.end()); for(int x:a) cout<<x<<" "; }
