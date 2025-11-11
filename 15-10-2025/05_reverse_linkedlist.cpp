// 05_reverse_linkedlist
// Problem: Reverse a singly linked list (iterative and recursive).
//
// Notes:
// 
//
// Brute-force approach:
// Brute: create new list by prepending nodes (O(n), O(n) extra).
//
// Optimized approach:
// // Iterative in-place (optimized)
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while(cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
// Recursive approach
Node* reverseRecursive(Node* head) {
    if(!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
//
// Complexity:
// Iterative Time: O(n), Space: O(1). Recursive Space: O(n) recursion.
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
// Iterative in-place (optimized)
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while(cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
// Recursive approach
Node* reverseRecursive(Node* head) {
    if(!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
