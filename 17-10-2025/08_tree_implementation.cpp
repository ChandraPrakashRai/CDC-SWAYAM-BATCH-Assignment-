// 08_tree_implementation.cpp
// Simple binary tree node, insert (BST insert), and print inorder to verify
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val; Node *l,*r;
    Node(int v):val(v),l(nullptr),r(nullptr){}
};
Node* insertBST(Node* root,int v){
    if(!root) return new Node(v);
    if(v < root->val) root->l = insertBST(root->l, v);
    else root->r = insertBST(root->r, v);
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->l);
    cout<<root->val<<" ";
    inorder(root->r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    Node* root = nullptr;
    for(int i=0;i<n;++i){ int x; cin>>x; root = insertBST(root,x); }
    inorder(root); cout<<"\n";
    return 0;
}
