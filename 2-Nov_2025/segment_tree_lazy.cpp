
// segment_tree_lazy.cpp
// Segment Tree with Lazy Propagation
// Supports:
// 1) Range add update
// 2) Range sum query

#include <bits/stdc++.h>
using namespace std;

vector<long long> seg, lazy, arr;

void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        seg[idx] += (r - l + 1) * lazy[idx];
        if (l != r) {
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

void updateRange(int idx, int l, int r, int ql, int qr, long long val) {
    push(idx,l,r);
    
    if (qr < l || r < ql) return;

    if (ql <= l && r <= qr) {
        lazy[idx] += val;
        push(idx,l,r);
        return;
    }

    int mid = (l+r)/2;
    updateRange(idx*2,l,mid,ql,qr,val);
    updateRange(idx*2+1,mid+1,r,ql,qr,val);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

long long queryRange(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;

    push(idx,l,r);

    if (ql <= l && r <= qr) return seg[idx];

    int mid = (l+r)/2;

    return queryRange(idx*2,l,mid,ql,qr)
         + queryRange(idx*2+1,mid+1,r,ql,qr);
}

int main(){
    int n;
    cin >> n;
    arr.resize(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    seg.assign(4*n,0);
    lazy.assign(4*n,0);

    build(1,0,n-1);

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;

        if (type == 1) {
            int l,r;
            cin >> l >> r;
            cout << queryRange(1,0,n-1,l,r) << "\n";
        }
        else if (type == 2) {
            int l,r; long long val;
            cin >> l >> r >> val;
            updateRange(1,0,n-1,l,r,val);
        }
    }
}
