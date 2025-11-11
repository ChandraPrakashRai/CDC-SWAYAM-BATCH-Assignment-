// Problem: Matrix I - spiral traversal, search element, print sorted elements
// Covers 2D matrix traversal and searching.

#include <bits/stdc++.h>
using namespace std;

// Spiral traversal
vector<int> spiralOrder(vector<vector<int>>& mat){
    vector<int> res;
    if(mat.empty()) return res;
    int top=0,bottom=mat.size()-1,left=0,right=mat[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++) res.push_back(mat[top][i]); top++;
        for(int i=top;i<=bottom;i++) res.push_back(mat[i][right]); right--;
        if(top<=bottom){ for(int i=right;i>=left;i--) res.push_back(mat[bottom][i]); bottom--; }
        if(left<=right){ for(int i=bottom;i>=top;i--) res.push_back(mat[i][left]); left++; }
    }
    return res;
}

// Search element in sorted matrix (rows/cols sorted)
bool searchMatrix(vector<vector<int>>& mat,int target){
    int r=0,c=mat[0].size()-1;
    while(r<(int)mat.size() && c>=0){
        if(mat[r][c]==target) return true;
        if(mat[r][c]>target) c--; else r++;
    }
    return false;
}

// Print elements in sorted order (flatten + sort)
vector<int> printSorted(vector<vector<int>>& mat){
    vector<int> v;
    for(auto &row:mat) v.insert(v.end(),row.begin(),row.end());
    sort(v.begin(),v.end());
    return v;
}

int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    auto sp=spiralOrder(m);
    for(int x:sp) cout<<x<<" "; cout<<"\n";
    cout<<(searchMatrix(m,5)?"Found":"Not Found")<<"\n";
    auto sorted=printSorted(m);
    for(int x:sorted) cout<<x<<" "; cout<<"\n";
    return 0;
}
