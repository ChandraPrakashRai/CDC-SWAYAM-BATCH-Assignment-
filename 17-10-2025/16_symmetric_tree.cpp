// 16_symmetric_tree.cpp
// Check whether a binary tree is symmetric (mirror of itself).
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
bool isMirror(Node* a, Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;
    if(a->v != b->v) return false;
    return isMirror(a->l,b->r) && isMirror(a->r,b->l);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> arr(n); for(int i=0;i<n;++i) cin>>arr[i];
    Node* root = build_level(arr);
    cout<<(isMirror(root, root) ? "1\n" : "0\n");
    return 0;
}
