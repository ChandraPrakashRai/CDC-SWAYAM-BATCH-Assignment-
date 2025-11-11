// Problem: Fibonacci (recursive and memoized)
// Time: O(2^n) naive, O(n) with memoization.

#include <bits/stdc++.h>
using namespace std;

int fib_rec(int n){
    if(n<=1) return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_memo(int n, vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib_memo(n-1, dp) + fib_memo(n-2, dp);
}

int main(){
    int n=30;
    vector<int> dp(n+1, -1);
    cout<<fib_memo(30, dp)<<"\n";
    return 0;
}
