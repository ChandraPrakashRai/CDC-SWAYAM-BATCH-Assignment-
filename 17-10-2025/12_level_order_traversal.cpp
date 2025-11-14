// 12_level_order_traversal.cpp
// Level-order traversal (BFS) printing each level in one line.
// Input: n then array of level-order with -1 for nulls.
#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node* l; Node* r; Node(int x):v(x),l(nullptr),r(nullptr){}};
Node* build_level(const vector<int>& arr){
    if(arr.empty() || arr[0]==-1) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*>q; q.push(root);
    int i=1;
    while(i < (int)arr.size()){
        Node* cur = q.front(); q.pop();
        if(i < (int)arr.size()){
            if(arr[i] != -1){ cur->l = new Node(arr[i]); q.push(cur->l); }
            i++;
        }
        if(i < (int)arr.size()){
            if(arr[i] != -1){ cur->r = new Node(arr[i]); q.push(cur->r); }
            i++;
        }
    }
    return root;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    Node* root = build_level(arr);
    if(!root){ cout<<"\n"; return 0;}
    queue<Node*> q; q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            Node* cur=q.front(); q.pop();
            cout<<cur->v;
            if(i+1<sz) cout<<" ";
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
        }
        cout<<"\n";
    }
    return 0;
}
