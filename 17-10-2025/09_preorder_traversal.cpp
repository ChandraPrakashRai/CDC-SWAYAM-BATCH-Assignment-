// 09_preorder_traversal.cpp
// Preorder traversal (recursive and iterative) of binary tree.
// Input: n, then node values in level-order with -1 as null. We'll build tree accordingly.
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
void preorder_rec(Node* root){
    if(!root) return;
    cout<<root->v<<" ";
    preorder_rec(root->l);
    preorder_rec(root->r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    Node* root = build_level(arr);
    preorder_rec(root); cout<<"\n";
    return 0;
}
