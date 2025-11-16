#include <bits/stdc++.h>
using namespace std;
// Equilibrium index
int main(){
    vector<int>a={1,3,5,2,2};
    int sum=accumulate(a.begin(),a.end(),0), left=0;
    for(int i=0;i<a.size();i++){
        sum-=a[i];
        if(left==sum){ cout<<i; break; }
        left+=a[i];
    }
}
