
#include <bits/stdc++.h>
using namespace std;
struct Node{int v;Node*l;Node*r;Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&a){
    if(a.empty()||a[0]==-1)return NULL;
    Node*r=new Node(a[0]);queue<Node*>q;q.push(r);int i=1;
    while(i<a.size()){Node*c=q.front();q.pop();
        if(i<a.size()&&a[i]!=-1){c->l=new Node(a[i]);q.push(c->l);}i++;
        if(i<a.size()&&a[i]!=-1){c->r=new Node(a[i]);q.push(c->r);}i++;
    }return r;
}
bool f(Node*r,int t){
    if(!r) return false;
    if(!r->l && !r->r) return t==r->v;
    return f(r->l,t-r->v)||f(r->r,t-r->v);
}
int main(){int n,t;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;cin>>t;
Node*r=build(a);cout<<(f(r,t)?"1":"0");}
