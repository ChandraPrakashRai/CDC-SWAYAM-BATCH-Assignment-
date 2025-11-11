// Problem: Print decreasing then increasing (or increasing then decreasing)
// Brief: Example: print n..1..n using recursion.
// Time: O(n), Space: O(n).

#include <bits/stdc++.h>
using namespace std;

void printDecInc(int n){
    if(n==0) return;
    cout<<n<<" ";
    printDecInc(n-1);
    cout<<n<<" ";
}

int main(){
    printDecInc(5); cout<<"\n";
    return 0;
}
