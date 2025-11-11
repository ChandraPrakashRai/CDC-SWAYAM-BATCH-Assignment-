// Problem: Rotate matrix by 90 degrees clockwise in-place
// Brief: Transpose then reverse each row.
// Time: O(n^2), Space: O(1).

#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>>& m){
    int n=m.size();
    for(int i=0;i<n;i++) for(int j=i;j<n;j++) swap(m[i][j], m[j][i]);
    for(int i=0;i<n;i++) reverse(m[i].begin(), m[i].end());
}

int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    rotate90(m);
    for(auto &r: m){ for(int x:r) cout<<x<<" "; cout<<"\n"; }
    return 0;
}
