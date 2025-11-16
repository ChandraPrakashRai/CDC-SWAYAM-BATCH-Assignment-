// segment_tree_max.cpp
// Segment Tree for Range Maximum Query + Point Update
// Supports:
// 1) build
// 2) query maximum in range
// 3) update single index

#include <bits/stdc++.h>
using namespace std;

vector<int> seg, arr;

// Build tree in O(n)
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx*2, l, mid);
    build(idx*2 + 1, mid+1, r);
    seg[idx] = max(seg[idx*2], seg[idx*2 + 1]);
}

// Query max in range [ql, qr]
int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INT_MIN;   // no overlap
    if (ql <= l && r <= qr) return seg[idx]; // total overlap
    int mid = (l+r)/2;
    return max(
        query(idx*2, l, mid, ql, qr),
        query(idx*2+1, mid+1, r, ql, qr)
    );
}

// Point update: arr[pos] = val
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = arr[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) update(idx*2, l, mid, pos, val);
    else update(idx*2+1, mid+1, r, pos, val);

    seg[idx] = max(seg[idx*2], seg[idx*2 + 1]);
}

int main(){
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.assign(4*n, 0);
    build(1, 0, n-1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) { 
            // query max
            int l, r;
            cin >> l >> r;
            cout << query(1,0,n-1,l,r) << "\n";
        }
        else {
            // point update
            int pos, val;
            cin >> pos >> val;
            update(1,0,n-1,pos,val);
        }
    }
    return 0;
}
