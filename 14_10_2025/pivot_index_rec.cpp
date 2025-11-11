// Problem: Find pivot index using recursion (left sum == right sum)
// Brief: Implementation uses total sum and recursion to track left sum.
// Time: O(n), Space: O(n) recursion.

#include <bits/stdc++.h>
using namespace std;

int total_sum(const vector<int>& a, int idx=0){
    if(idx >= (int)a.size()) return 0;
    return a[idx] + total_sum(a, idx+1);
}

int find_pivot(const vector<int>& a, int idx, int left, int total){
    if(idx >= (int)a.size()) return -1;
    int right = total - a[idx] - left;
    if(left == right) return idx;
    return find_pivot(a, idx+1, left + a[idx], total);
}

int pivotIndex(const vector<int>& a){
    int total = total_sum(a);
    return find_pivot(a, 0, 0, total);
}

int main(){
    cout<<pivotIndex({1,7,3,6,5,6})<<"\n";
    return 0;
}
