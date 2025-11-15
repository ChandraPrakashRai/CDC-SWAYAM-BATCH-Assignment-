// Generate all permutations of a string (lexicographic order)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin>>s)) return 0;
    sort(s.begin(), s.end());
    do{
        cout<<s<<"\n";
    } while(next_permutation(s.begin(), s.end()));
    return 0;
}
