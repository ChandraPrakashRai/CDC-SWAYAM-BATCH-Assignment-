// Problem: Print numbers 1..n using recursion (increasing)
// Time: O(n), Space: O(n) recursion.

#include <bits/stdc++.h>
using namespace std;

void printInc(int n){
    if(n==0) return;
    printInc(n-1);
    cout<<n<<" ";
}

int main(){
    printInc(10); cout<<"\n";
    return 0;
}
