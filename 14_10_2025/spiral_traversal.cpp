// Problem: Spiral traversal of matrix
// Brief: Return elements in spiral order.
// Time: O(r*c), Space: O(1) extra (output size r*c).

#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>>& mat){
    vector<int> res;
    if(mat.empty()) return res;
    int top=0, bottom=mat.size()-1, left=0, right=mat[0].size()-1;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++) res.push_back(mat[top][j]); top++;
        for(int i=top;i<=bottom;i++) res.push_back(mat[i][right]); right--;
        if(top<=bottom){ for(int j=right;j>=left;j--) res.push_back(mat[bottom][j]); bottom--; }
        if(left<=right){ for(int i=bottom;i>=top;i--) res.push_back(mat[i][left]); left++; }
    }
    return res;
}

int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    for(int x: spiral(m)) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
