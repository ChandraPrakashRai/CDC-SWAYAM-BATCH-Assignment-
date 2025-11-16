// regular_expression_matching_recursion.cpp
// Pattern supports '.' and '*'
// Pure recursion, exponential time.

#include <bits/stdc++.h>
using namespace std;

bool solve(const string &s, const string &p, int i, int j) {
    // If both exhausted → match
    if (i == s.size() && j == p.size()) return true;

    // If pattern exhausted but string not → fail
    if (j == p.size()) return false;

    // Check first match condition
    bool firstMatch = false;
    if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
        firstMatch = true;

    // Case: next char is '*'
    if (j + 1 < p.size() && p[j+1] == '*') {
        // two choices:
        // 1) skip "x*" from pattern
        // 2) use "x*" to match one char
        return solve(s, p, i, j+2) ||
               (firstMatch && solve(s, p, i+1, j));
    }
    else {
        // Normal character match
        if (!firstMatch) return false;
        return solve(s, p, i+1, j+1);
    }
}

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);

    cout << (solve(s,p,0,0) ? "true" : "false") << "\n";
}
