// Problem: Print elements of matrix in sorted order
// Brief: Flatten and sort or use min-heap for better memory/time tradeoffs.
// Time: O(r*c log(r*c)) for sort or O(k log r) merging rows.

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedElements(vector<vector<int>>& mat){
    vector<int> v;
    for(auto &row: mat) for(int x: row) v.push_back(x);
    sort(v.begin(), v.end());
    return v;
}

int main(){
    vector<vector<int>> m={{3,1,2},{6,4,5}};
    for(int x: sortedElements(m)) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
