// Problem: Power using recursion (a^b)
// Brief: Compute a^b recursively (integer exponent).
// Time: O(b) naive, O(log b) using fast exponentiation.

#include <bits/stdc++.h>
using namespace std;

long long pow_naive(long long a,int b){
    if(b==0) return 1;
    return a * pow_naive(a,b-1);
}

long long pow_fast(long long a,int b){
    if(b==0) return 1;
    long long half = pow_fast(a,b/2);
    if(b%2==0) return half*half;
    else return half*half*a;
}

int main(){
    cout<<pow_fast(2,20)<<"\n";
    return 0;
}
