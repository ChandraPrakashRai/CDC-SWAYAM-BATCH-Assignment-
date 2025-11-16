#include <bits/stdc++.h>
using namespace std;
// Selection sort
int main(){
    vector<int>a={64,25,12,22,11};
    for(int i=0;i<a.size();i++){
        int mn=i;
        for(int j=i+1;j<a.size();j++)
            if(a[j]<a[mn]) mn=j;
        swap(a[mn],a[i]);
    }
    for(int x:a) cout<<x<<" ";
}
