
#include <bits/stdc++.h>
using namespace std;
struct Node{int v;Node*l;Node*r;Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&a){if(a.empty()||a[0]==-1)return NULL;
Node*r=new Node(a[0]);queue<Node*>q;q.push(r);int i=1;
while(i<a.size()){Node*c=q.front();q.pop();
 if(i<a.size()&&a[i]!=-1){c->l=new Node(a[i]);q.push(c->l);}i++;
 if(i<a.size()&&a[i]!=-1){c->r=new Node(a[i]);q.push(c->r);}i++;
}return r;}
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;
Node*r=build(a); if(!r) return 0; queue<Node*>q;q.push(r);
while(!q.empty()){int sz=q.size();Node*last=NULL;
    while(sz--){Node*c=q.front();q.pop();last=c;
        if(c->l)q.push(c->l); if(c->r)q.push(c->r);
    }
    cout<<last->v<<" ";
}}
