// Can Place Flowers (LeetCode 605)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> flowerbed(n);
    for(int i=0;i<n;++i) cin>>flowerbed[i];
    int k; cin>>k;
    int count=0;
    for(int i=0;i<n && count<k; ++i){
        if(flowerbed[i]==0){
            int prev = (i==0?0:flowerbed[i-1]);
            int next = (i==n-1?0:flowerbed[i+1]);
            if(prev==0 && next==0){
                flowerbed[i]=1;
                ++count;
            }
        }
    }
    cout<<(count>=k? "true":"false")<<"\n";
    return 0;
}
