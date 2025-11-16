// segment_tree_sum.cpp
// Segment tree for range sum + single point update

#include <bits/stdc++.h>
using namespace std;

vector<long long> seg, arr;

// Build tree
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

// Query sum in [ql, qr]
long long query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l+r)/2;
    return query(idx*2,l,mid,ql,qr) +
           query(idx*2+1,mid+1,r,ql,qr);
}

// Point update
void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        seg[idx] = arr[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) update(idx*2, l, mid, pos, val);
    else update(idx*2+1, mid+1, r, pos, val);

    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i=0;i<n;i++) cin >> arr[i];
    seg.assign(4*n,0);
    build(1,0,n-1);

    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l,r; cin >> l >> r;
            cout << query(1,0,n-1,l,r) << "\n";
        } else {
            int pos; long long val;
            cin >> pos >> val;
            update(1,0,n-1,pos,val);
        }
    }
    return 0;
}
