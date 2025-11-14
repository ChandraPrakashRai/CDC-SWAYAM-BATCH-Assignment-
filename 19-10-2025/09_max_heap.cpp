
#include <bits/stdc++.h>
using namespace std;
struct MaxHeap{
 vector<int>a;
 void push(int x){ a.push_back(x); push_heap(a.begin(),a.end()); }
 void pop(){ pop_heap(a.begin(),a.end()); a.pop_back(); }
 int top(){ return a.front(); }
 bool empty(){ return a.empty(); }
};
int main(){MaxHeap h; int q;cin>>q;
 while(q--){string op;cin>>op;
  if(op=="push"){int x;cin>>x;h.push(x);}
  else if(op=="pop"){ if(!h.empty()) h.pop();}
  else if(op=="top"){ if(!h.empty()) cout<<h.top()<<" "; }
 }
}
