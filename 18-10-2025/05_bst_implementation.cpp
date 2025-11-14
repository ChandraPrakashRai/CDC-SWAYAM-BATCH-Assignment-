
#include <bits/stdc++.h>
using namespace std;
struct Node{int v;Node*l;Node*r;Node(int x):v(x),l(NULL),r(NULL){}};
Node* ins(Node*r,int x){
    if(!r) return new Node(x);
    if(x<r->v) r->l=ins(r->l,x);
    else r->r=ins(r->r,x);
    return r;
}
void inorder(Node*r){if(!r)return;inorder(r->l);cout<<r->v<<" ";inorder(r->r);}
int main(){int n;cin>>n;Node*r=NULL;while(n--){int x;cin>>x;r=ins(r,x);}inorder(r);}
