// Problem: Factorial using recursion
// Brief: Compute n! recursively.
// Time: O(n), Space: O(n) recursion stack.

#include <bits/stdc++.h>
using namespace std;

long long fact(int n){
    if(n<=1) return 1;
    return n * fact(n-1);
}

int main(){
    cout<<fact(10)<<"\n";
    return 0;
}
