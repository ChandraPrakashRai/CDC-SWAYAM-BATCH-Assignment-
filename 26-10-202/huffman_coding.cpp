// huffman_coding.cpp
// Build Huffman codes for characters in input string, encode and decode to verify.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *l, *r;
    Node(char c, int f): ch(c), freq(f), l(nullptr), r(nullptr) {}
    Node(int f, Node* left, Node* right): ch(0), freq(f), l(left), r(right) {}
};

struct Cmp {
    bool operator()(Node* a, Node* b) const { return a->freq > b->freq; }
};

void buildCodes(Node* root, string cur, unordered_map<char,string>& mp) {
    if (!root) return;
    if (!root->l && !root->r) {
        mp[root->ch] = (cur.size() ? cur : "0"); // single-char edge case
    }
    buildCodes(root->l, cur + "0", mp);
    buildCodes(root->r, cur + "1", mp);
}

string encode(const string &s, unordered_map<char,string>& mp) {
    string out;
    out.reserve(s.size()*2);
    for (char c: s) out += mp[c];
    return out;
}

string decode(const string &bits, Node* root) {
    string out;
    Node* cur = root;
    for (char b: bits) {
        if (b == '0') cur = cur->l;
        else cur = cur->r;
        if (!cur->l && !cur->r) {
            out.push_back(cur->ch);
            cur = root;
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s); // read full line (may include spaces)
    if (s.size() == 0) return 0;
    unordered_map<char,int> freq;
    for (char c: s) freq[c]++;
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto &p: freq) pq.push(new Node(p.first, p.second));
    if (pq.empty()) return 0;
    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        Node* merged = new Node(a->freq + b->freq, a, b);
        pq.push(merged);
    }
    Node* root = pq.top();
    unordered_map<char,string> codes;
    buildCodes(root, "", codes);
    cout << "Codes:\n";
    for (auto &p: codes) {
        if (p.first == ' ') cout << "' '";
        else cout << p.first;
        cout << ": " << p.second << '\n';
    }
    string bits = encode(s, codes);
    cout << "Encoded: " << bits << '\n';
    cout << "Decoded: " << decode(bits, root) << '\n';
    return 0;
}
