// Problem: Tower of Hanoi (print moves)
// Brief: Classic recursive solution printing moves.
// Time: O(2^n), Space: O(n) recursion.

#include <bits/stdc++.h>
using namespace std;

void tower(int n, char from, char to, char aux){
    if(n==0) return;
    tower(n-1, from, aux, to);
    cout<<"Move "<<n<<" from "<<from<<" to "<<to<<"\n";
    tower(n-1, aux, to, from);
}

int main(){
    tower(3,'A','C','B');
    return 0;
}
