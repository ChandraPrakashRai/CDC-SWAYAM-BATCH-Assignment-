// wildcard_dp.cpp
// Wildcard Matching using bottom-up DP (tabulation)
// Input (two lines): text s, pattern p
// Output: "true" or "false"
//
// Approach:
// dp[i][j] = true if s[i..] matches p[j..]
// Base: dp[slen][plen] = true (empty vs empty)
// Transition:
// - If p[j] == '*': dp[i][j] = dp[i][j+1] || (i < slen && dp[i+1][j])
// - Else: dp[i][j] = (i < slen) && (p[j]=='?' || p[j]==s[i]) && dp[i+1][j+1]
//
// Complexity: O(slen * plen) time and O(slen * plen) space.
// We use vector<vector<char>> to save memory slightly.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, p;
    if (!getline(cin, s)) return 0;
    if (!getline(cin, p)) return 0;
    int slen = (int)s.size();
    int plen = (int)p.size();

    // dp has dimensions (slen+1) x (plen+1)
    vector<vector<char>> dp(slen + 1, vector<char>(plen + 1, 0));
    dp[slen][plen] = 1; // both empty => match

    // Fill last row: dp[slen][j] => matching empty string with pattern suffix
    // Empty string matches only if remaining pattern consists entirely of '*'
    for (int j = plen - 1; j >= 0; --j) {
        if (p[j] == '*') dp[slen][j] = dp[slen][j + 1];
        else dp[slen][j] = 0;
    }

    // Fill table bottom-up
    for (int i = slen - 1; i >= 0; --i) {
        for (int j = plen - 1; j >= 0; --j) {
            if (p[j] == '*') {
                // zero char match OR consume one char and stay on '*'
                dp[i][j] = (dp[i][j + 1] || dp[i + 1][j]) ? 1 : 0;
            } else {
                bool charMatch = (p[j] == '?' || p[j] == s[i]);
                dp[i][j] = (charMatch && dp[i + 1][j + 1]) ? 1 : 0;
            }
        }
    }

    cout << (dp[0][0] ? "true" : "false") << '\n';
    return 0;
}
