// 01_add_node
// Problem: Add a node at any given position in a singly linked list.
//
// Notes:
// If pos is 0 or list empty, new node becomes head.
//
// Brute-force approach:
// Traverse to position and insert (O(n)).
//
// Optimized approach:
// // Optimized: single traversal insert (same complexity, clearer)
Node* insertAtPosition(Node* head, int pos, int val) {
    Node* node = new Node(val);
    if(pos<=0 || !head) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    int i=0;
    while(cur && i<pos-1) { cur = cur->next; i++; }
    node->next = cur?cur->next:nullptr;
    if(cur) cur->next = node;
    return head;
}
//
// Complexity:
// Time: O(n), Space: O(1)
//
// C++ implementation (custom Node / LinkedList)
// ------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

// helper to create list from vector (for tests)
Node* build(const vector<int>& a) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int x: a) {
        Node* n = new Node(x);
        if(!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// Solution implementation
// Optimized: single traversal insert (same complexity, clearer)
Node* insertAtPosition(Node* head, int pos, int val) {
    Node* node = new Node(val);
    if(pos<=0 || !head) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    int i=0;
    while(cur && i<pos-1) { cur = cur->next; i++; }
    node->next = cur?cur->next:nullptr;
    if(cur) cur->next = node;
    return head;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
