// 09_sort_0_1_2.cpp
// Problem: Sort an array containing only 0,1,2 (Dutch National Flag).
//
// Brute-force idea:
//   Count zeros, ones, twos then overwrite -> two-pass counting O(n).
//
// Optimized approach:
//   Three-way partitioning (low, mid, high pointers) single-pass O(n), in-place.
//
// Complexity: O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

void sort012_count(vector<int>& a) {
    int c0=0,c1=0,c2=0;
    for(int x:a) { if(x==0) c0++; else if(x==1) c1++; else c2++; }
    int i=0;
    while(c0--) a[i++]=0;
    while(c1--) a[i++]=1;
    while(c2--) a[i++]=2;
}

void sort012_dnf(vector<int>& a) {
    int low=0, mid=0, high=a.size()-1;
    while(mid<=high){
        if(a[mid]==0) swap(a[low++], a[mid++]);
        else if(a[mid]==1) mid++;
        else swap(a[mid], a[high--]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {2,0,2,1,1,0};
    sort012_dnf(a);
    for(int x:a) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
