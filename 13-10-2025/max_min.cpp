#include <bits/stdc++.h>
using namespace std;
// Find maximum and minimum element
int main(){
    vector<int> a={3,5,1,9,2};
    int mn=INT_MAX,mx=INT_MIN;
    for(int x:a){ mn=min(mn,x); mx=max(mx,x); }
    cout<<mn<<" "<<mx;
}
