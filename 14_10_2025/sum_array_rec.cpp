// Problem: Sum of array using recursion
// Time: O(n), Space: O(n) recursion.

#include <bits/stdc++.h>
using namespace std;

int sumArray(const vector<int>& a, int idx=0){
    if(idx >= (int)a.size()) return 0;
    return a[idx] + sumArray(a, idx+1);
}

int main(){
    cout<<sumArray({1,2,3,4,5})<<"\n";
    return 0;
}
