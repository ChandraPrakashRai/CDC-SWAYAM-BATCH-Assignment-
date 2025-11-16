// regular_expression_matching_memo.cpp
// Pattern supports '.' and '*'
// Recursion + memoization (Top-Down DP)

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005]; // -1 = unknown, 0 = false, 1 = true

bool solve(const string &s, const string &p, int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    // If both exhausted
    if (i == s.size() && j == p.size())
        return dp[i][j] = 1;

    // If pattern exhausted
    if (j == p.size())
        return dp[i][j] = 0;

    bool firstMatch = false;
    if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
        firstMatch = true;

    bool ans = false;

    if (j + 1 < p.size() && p[j+1] == '*') {
        ans = solve(s,p,i,j+2) ||
              (firstMatch && solve(s,p,i+1,j));
    } else {
        if (firstMatch)
            ans = solve(s,p,i+1,j+1);
        else
            ans = false;
    }

    return dp[i][j] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));

    string s, p;
    getline(cin, s);
    getline(cin, p);

    cout << (solve(s,p,0,0) ? "true":"false") << "\n";
}
