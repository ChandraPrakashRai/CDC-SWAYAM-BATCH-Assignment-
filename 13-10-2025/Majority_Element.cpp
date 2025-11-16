#include <bits/stdc++.h>
using namespace std;
// Moore's Voting Algorithm
int main(){
    vector<int>a={2,2,1,1,1,2,2};
    int cand=0, cnt=0;
    for(int x:a){
        if(cnt==0) cand=x;
        cnt += (x==cand?1:-1);
    }
    cout<<cand;
}
