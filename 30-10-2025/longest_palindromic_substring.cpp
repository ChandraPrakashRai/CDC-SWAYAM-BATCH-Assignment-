// ============================================================================
// Longest Palindromic Substring – All 3 major approaches in one file
// Approaches:
// (1) Expand Around Center  – O(n^2)
// (2) Dynamic Programming   – O(n^2) time & O(n^2) space
// (3) Manacher’s Algorithm  – O(n)  (fastest)
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// (1) EXPAND AROUND CENTER – O(n^2)
// ============================================================================
string expandCenter(const string &s, int L, int R) {
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--; R++;
    }
    return s.substr(L + 1, R - L - 1);
}

string LPS_center(string s) {
    if (s.empty()) return "";
    string best = s.substr(0, 1);

    for (int i = 0; i < s.size(); i++) {
        // Odd length palindrome
        string p1 = expandCenter(s, i, i);
        if (p1.size() > best.size()) best = p1;

        // Even length palindrome
        string p2 = expandCenter(s, i, i + 1);
        if (p2.size() > best.size()) best = p2;
    }

    return best;
}

// ============================================================================
// (2) DP TABLE APPROACH – O(n^2) time, O(n^2) space
//
// dp[l][r] = true if substring s[l..r] is palindrome
//
// Fill from smaller substrings → larger substrings.
// ============================================================================
string LPS_dp(string s) {
    int n = s.size();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // Length 1 substrings
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // Length 2 substrings
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Length >= 3 substrings
    for (int len = 3; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            if (s[l] == s[r] && dp[l + 1][r - 1]) {
                dp[l][r] = true;
                if (len > maxLen) {
                    start = l;
                    maxLen = len;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

// ============================================================================
// (3) MANACHER'S ALGORITHM – O(n)
// Fastest algorithm for Longest Palindromic Substring.
// Transform string: "abc" → "^#a#b#c#$"
// Then compute palindrome radii.
// ============================================================================
string LPS_manacher(string s) {
    if (s.empty()) return "";

    // Transform string with separators
    string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.size();
    vector<int> P(n, 0);  // Radius array
    int C = 0, R = 0;     // Center, Right boundary

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2*C - i;

        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand
        while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;

        // Update center & right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find max radius
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

// ============================================================================
// MAIN
// Choose which method to run:
// 1 → Expand Around Center
// 2 → Dynamic Programming
// 3 → Manacher
// ============================================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    int choice;
    cin >> choice;

    string ans;
    if (choice == 1)
        ans = LPS_center(s);
    else if (choice == 2)
        ans = LPS_dp(s);
    else
        ans = LPS_manacher(s);

    cout << ans << "\n";
    return 0;
}
