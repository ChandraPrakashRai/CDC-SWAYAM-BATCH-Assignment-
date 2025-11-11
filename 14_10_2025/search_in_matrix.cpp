// Problem: Search in row-wise and column-wise sorted matrix
// Brief: Start from top-right and move accordingly.
// Time: O(r+c), Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool searchMat(vector<vector<int>>& mat, int target){
    if(mat.empty()) return false;
    int r=0, c=mat[0].size()-1;
    while(r < (int)mat.size() && c >= 0){
        if(mat[r][c]==target) return true;
        if(mat[r][c] > target) c--;
        else r++;
    }
    return false;
}

int main(){
    vector<vector<int>> m={{1,3,5},{2,4,6},{3,5,7}};
    cout<<(searchMat(m,4) ? "Found\n":"Not Found\n");
    return 0;
}
