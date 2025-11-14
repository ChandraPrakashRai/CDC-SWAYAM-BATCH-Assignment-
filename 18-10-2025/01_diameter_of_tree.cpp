
#include <bits/stdc++.h>
using namespace std;
struct Node{int v;Node*l;Node*r;Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&a){
    if(a.empty()||a[0]==-1) return NULL;
    Node*root=new Node(a[0]); queue<Node*>q; q.push(root); int i=1;
    while(i<a.size()){ Node*cur=q.front(); q.pop();
        if(i<a.size()&&a[i]!=-1){cur->l=new Node(a[i]);q.push(cur->l);} i++;
        if(i<a.size()&&a[i]!=-1){cur->r=new Node(a[i]);q.push(cur->r);} i++;
    } return root;
}
int ans;
int dfs(Node*r){
    if(!r) return 0;
    int L=dfs(r->l),R=dfs(r->r);
    ans=max(ans,L+R);
    return 1+max(L,R);
}
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;Node*r=build(a);ans=0;dfs(r);cout<<ans;}
