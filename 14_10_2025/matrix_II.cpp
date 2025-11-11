// Problem: Matrix II - median of row-wise sorted, row with max 1s, rotate by 90°
// Practice on advanced matrix operations.

#include <bits/stdc++.h>
using namespace std;

// Find median in row-wise sorted matrix
int rowwiseMedian(vector<vector<int>>& m){
    int r=m.size(), c=m[0].size();
    int mn=INT_MAX, mx=INT_MIN;
    for(int i=0;i<r;i++){ mn=min(mn,m[i][0]); mx=max(mx,m[i][c-1]); }
    int desired=(r*c+1)/2;
    while(mn<mx){
        int mid=mn+(mx-mn)/2;
        int place=0;
        for(int i=0;i<r;i++)
            place += upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin();
        if(place<desired) mn=mid+1; else mx=mid;
    }
    return mn;
}

// Row with maximum 1s
int rowWithMax1s(vector<vector<int>>& m){
    int r=m.size(), c=m[0].size();
    int max_row=-1, j=c-1;
    for(int i=0;i<r;i++){
        while(j>=0 && m[i][j]==1){ j--; max_row=i; }
    }
    return max_row;
}

// Rotate matrix 90 degrees clockwise
void rotate90(vector<vector<int>>& m){
    int n=m.size();
    for(int i=0;i<n;i++) for(int j=i;j<n;j++) swap(m[i][j],m[j][i]);
    for(int i=0;i<n;i++) reverse(m[i].begin(),m[i].end());
}

int main(){
    vector<vector<int>> m={{1,3,5},{2,6,9},{3,6,9}};
    cout<<"Median="<<rowwiseMedian(m)<<"\n";
    vector<vector<int>> m2={{0,1,1,1},{0,0,1,1},{1,1,1,1}};
    cout<<"Row with max 1s="<<rowWithMax1s(m2)<<"\n";
    rotate90(m);
    for(auto &r:m){ for(int x:r) cout<<x<<" "; cout<<"\n"; }
    return 0;
}
