// trie_basic.cpp
// Basic Trie implementation with insert/search/startsWith.
// Input: q operations: "insert word", "search word", "starts prefix"

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool end;
    array<TrieNode*,26> next;
    TrieNode() { end = false; next.fill(nullptr); }
};

struct Trie {
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(const string &s) {
        TrieNode* cur = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!cur->next[idx]) cur->next[idx] = new TrieNode();
            cur = cur->next[idx];
        }
        cur->end = true;
    }
    bool search(const string &s) {
        TrieNode* cur = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!cur->next[idx]) return false;
            cur = cur->next[idx];
        }
        return cur->end;
    }
    bool startsWith(const string &p) {
        TrieNode* cur = root;
        for (char ch : p) {
            int idx = ch - 'a';
            if (!cur->next[idx]) return false;
            cur = cur->next[idx];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    if (!(cin >> q)) return 0;
    Trie trie;
    while (q--) {
        string op, w; cin >> op >> w;
        if (op == "insert") trie.insert(w);
        else if (op == "search") cout << (trie.search(w) ? "true" : "false") << '\n';
        else if (op == "starts") cout << (trie.startsWith(w) ? "true" : "false") << '\n';
    }
    return 0;
}
