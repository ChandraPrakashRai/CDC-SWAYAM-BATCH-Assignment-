// Lemonade Change (LeetCode 860)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    if(!(cin>>m)) return 0;
    vector<int> bills(m);
    for(int i=0;i<m;++i) cin>>bills[i];
    int five=0, ten=0;
    for(int b: bills){
        if(b==5) five++;
        else if(b==10){
            if(five==0){ cout<<"false\n"; return 0; }
            five--; ten++;
        } else if(b==20){
            if(ten>0 && five>0){ ten--; five--; }
            else if(five>=3){ five-=3; }
            else { cout<<"false\n"; return 0; }
        }
    }
    cout<<"true\n";
    return 0;
}
