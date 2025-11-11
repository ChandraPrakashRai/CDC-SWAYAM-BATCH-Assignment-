// Problem: Count digits of a non-negative integer using recursion
// Time: O(log_10 n), Space: O(log n) recursion.

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
    if(n==0) return 0;
    return 1 + countDigits(n/10);
}

int main(){
    cout<<countDigits(123456)<<"\n";
    return 0;
}
