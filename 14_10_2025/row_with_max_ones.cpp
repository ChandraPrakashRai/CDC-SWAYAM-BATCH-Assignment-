// Problem: Row with maximum 1s in a binary matrix (rows sorted)
// Brief: Use two-pointer from top-right.
// Time: O(r+c), Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>& m){
    int r=m.size(), c=m[0].size();
    int max_row=-1;
    int j=c-1;
    for(int i=0;i<r;i++){
        while(j>=0 && m[i][j]==1){ j--; max_row=i; }
    }
    return max_row;
}

int main(){
    vector<vector<int>> m={{0,1,1},{0,0,1},{1,1,1}};
    cout<<rowWithMaxOnes(m)<<"\n";
    return 0;
}
