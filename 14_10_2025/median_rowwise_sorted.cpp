// Problem: Median in row-wise sorted matrix
// Brief: Use binary search on value range.
// Time: O(r * log(max-min) * log c)

#include <bits/stdc++.h>
using namespace std;

int matrix_median(vector<vector<int>>& m){
    int r=m.size(), c=m[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(auto &row: m){ low = min(low, row.front()); high = max(high, row.back()); }
    int desired = (r*c + 1)/2;
    while(low < high){
        int mid = low + (high - low)/2;
        int place = 0;
        for(auto &row: m) place += upper_bound(row.begin(), row.end(), mid) - row.begin();
        if(place < desired) low = mid+1;
        else high = mid;
    }
    return low;
}

int main(){
    vector<vector<int>> m={{1,3,5},{2,6,9},{3,6,9}};
    cout<<matrix_median(m)<<"\n";
    return 0;
}
