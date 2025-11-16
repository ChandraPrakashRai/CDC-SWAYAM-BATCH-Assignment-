// trie_word_break.cpp
// Word Break using Trie + DP
#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool end;
    array<Node*,26> nxt;
    Node(){ end=false; nxt.fill(nullptr); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    int k; cin >> k;
    Node* root = new Node();
    for (int i = 0; i < k; ++i) {
        string w; cin >> w;
        Node* cur = root;
        for (char ch : w) {
            int idx = ch - 'a';
            if (!cur->nxt[idx]) cur->nxt[idx] = new Node();
            cur = cur->nxt[idx];
        }
        cur->end = true;
    }
    int n = s.size();
    vector<char> dp(n+1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;
        Node* cur = root;
        for (int j = i; j < n; ++j) {
            int idx = s[j] - 'a';
            if (!cur->nxt[idx]) break;
            cur = cur->nxt[idx];
            if (cur->end) dp[j+1] = true;
        }
    }
    cout << (dp[n] ? "true" : "false") << '\n';
    return 0;
}
