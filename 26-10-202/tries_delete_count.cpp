// trie_delete_count.cpp
// Trie with insert, delete-one-occurrence, countWord

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt; // count of words that end here
    array<Node*,26> nxt;
    Node() { cnt = 0; nxt.fill(nullptr); }
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }
    void insert(const string &s) {
        Node* cur = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!cur->nxt[idx]) cur->nxt[idx] = new Node();
            cur = cur->nxt[idx];
        }
        cur->cnt++;
    }
    int countWord(const string &s) {
        Node* cur = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!cur->nxt[idx]) return 0;
            cur = cur->nxt[idx];
        }
        return cur->cnt;
    }
    bool removeOne(const string &s) {
        if (countWord(s) == 0) return false;
        Node* cur = root;
        vector<pair<Node*, int>> path;
        for (char ch : s) {
            int idx = ch - 'a';
            path.push_back({cur, idx});
            cur = cur->nxt[idx];
        }
        cur->cnt--;
        // cleanup bottom-up if node has no children and cnt == 0
        for (int i = (int)path.size()-1; i >= 0; --i) {
            Node* parent = path[i].first;
            int idx = path[i].second;
            Node* child = parent->nxt[idx];
            bool hasChild = false;
            for (int k = 0; k < 26; ++k) if (child->nxt[k]) { hasChild = true; break; }
            if (child->cnt == 0 && !hasChild) {
                delete child;
                parent->nxt[idx] = nullptr;
            } else break;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; if (!(cin >> q)) return 0;
    Trie trie;
    while (q--) {
        string op, w; cin >> op >> w;
        if (op == "insert") trie.insert(w);
        else if (op == "delete") cout << (trie.removeOne(w) ? "deleted" : "not_found") << '\n';
        else if (op == "count") cout << trie.countWord(w) << '\n';
    }
    return 0;
}
