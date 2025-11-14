// 15_same_tree.cpp
// Check if two binary trees are identical (structure + values). Input: n1 arr1 then n2 arr2 (level-order with -1)
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
bool same(Node* a, Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;
    if(a->v != b->v) return false;
    return same(a->l,b->l) && same(a->r,b->r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1; if(!(cin>>n1)) return 0;
    vector<int> a(n1); for(int i=0;i<n1;++i) cin>>a[i];
    int n2; cin>>n2; vector<int> b(n2); for(int i=0;i<n2;++i) cin>>b[i];
    Node* r1 = build_level(a);
    Node* r2 = build_level(b);
    cout<<(same(r1,r2) ? "1\n" : "0\n");
    return 0;
}
