#include <bits/stdc++.h>
using namespace std;

// Approach: Min-heap of size k

int kthLargest(vector<int>& a,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int x:a){
        pq.push(x);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
}

int main(){
    vector<int> a={3,2,1,5,6,4};
    cout<<kthLargest(a,2);
}
