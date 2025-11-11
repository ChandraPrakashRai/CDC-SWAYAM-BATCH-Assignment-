// Problem: Print numbers n..1 using recursion (decreasing)
// Time: O(n), Space: O(n) recursion.

#include <bits/stdc++.h>
using namespace std;

void printDec(int n){
    if(n==0) return;
    cout<<n<<" ";
    printDec(n-1);
}

int main(){
    printDec(10); cout<<"\n";
    return 0;
}
