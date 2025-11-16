// wildcard_recursive.cpp
// Pure recursive (brute-force) solution for Wildcard Matching
// Input (two lines): text s, pattern p
// Output: "true" or "false"
//
// Approach (recursive):
// match(i, j) = whether s[i..end) matches p[j..end)
// - If j == plen: return i == slen
// - If p[j] == '*': try zero chars (match(i, j+1)) OR consume one char (if i<slen) and stay at j (match(i+1, j))
// - Else if p[j] == '?' or p[j] == s[i]: match(i+1, j+1)
// - Else false
//
// Complexity: exponential in worst-case (for teaching only).

#include <bits/stdc++.h>
using namespace std;

string s, p;
int slen, plen;

bool match_rec(int i, int j) {
    if (j == plen) return i == slen;
    if (p[j] == '*') {
        // '*' matches zero chars OR one char and remain on same pattern
        if (match_rec(i, j + 1)) return true;
        if (i < slen && match_rec(i + 1, j)) return true;
        return false;
    } else {
        if (i < slen && (p[j] == '?' || p[j] == s[i])) {
            return match_rec(i + 1, j + 1);
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!getline(cin, s)) return 0;
    if (!getline(cin, p)) return 0;
    slen = (int)s.size();
    plen = (int)p.size();
    bool res = match_rec(0, 0);
    cout << (res ? "true" : "false") << '\n';
    return 0;
}
